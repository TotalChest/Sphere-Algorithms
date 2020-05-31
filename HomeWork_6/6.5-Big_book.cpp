#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stack>
#include <memory>

using namespace std;
using ull = unsigned long long;

const ull PR = 24571;
const int LENGTH = 500;
const int HASHSIZE = 100001;

struct Data {
	char key[LENGTH];
	char value[LENGTH];
	ull address;
	Data() {}
	Data(const char* key_2, const char* value_2, const ull address_2) {
		strcpy(key, key_2);
		strcpy(value, value_2);
		address = address_2;
	}
};

class Hash {
	ull PRIME;
	vector<ull> polinom;
public:
	Hash(const ull PR) {
		PRIME = PR;
		polinom.resize(LENGTH);
		polinom[0] = 1;
		for (int j = 0; j < LENGTH; ++j)
			polinom[j] =  PRIME * polinom[j-1];
	}
	ull hash(const string &str) {
		ull hash = 0;
		int size = str.size();
		for (int j = 0; j < size; ++j)
			hash += str[j] * polinom[j];
		return hash;
	}
};

ull read_position(FILE* file, int position) {
	ull answer;
	fseek(file, position * sizeof(ull), SEEK_SET);
	fread(&answer, sizeof(ull), 1, file);
	return answer;
}

ull write_position(FILE* file, int position, stack<ull> &curr_free) {
	ull place = curr_free.top();
	curr_free.pop();
	if (curr_free.empty())
		curr_free.push(place + sizeof(Data));
	fseek(file, position * sizeof(ull), SEEK_SET);
	fwrite(&place, sizeof(ull), 1, file);
	return place;
}

void write_data(FILE* file, string &key, string &value, ull place) {
	Data curr(key.c_str(), value.c_str(), 0);
	fseek(file, place, SEEK_SET);
	fwrite(&curr, sizeof(curr), 1, file);
}

Data read_data(FILE* file, ull place) {
	Data curr;
	fseek(file, place, SEEK_SET);
	fread(&curr, sizeof(Data), 1, file);
	return curr;
}

void print_data(FILE* file, ull place) {
	Data curr = read_data(file, place);
	cout << curr.key << ' ' << curr.value << '\n';
}

ull find_free_block(string &key, FILE* file, ull place, stack<ull> &curr_free) {
	Data curr;
	ull save_place = place;
	while(place != 0) {
		curr = read_data(file, place);
		if (!strcmp(curr.key, key.c_str()))
			return 0;
		save_place = place;
		place = curr.address;
	}
	ull new_place = curr_free.top();
	curr_free.pop();
	if (curr_free.empty())
		curr_free.push(new_place + sizeof(Data));
	curr.address = new_place;
	fseek(file, save_place, SEEK_SET);
	fwrite(&curr, sizeof(curr), 1, file);
	return new_place;
}

ull find_place(string &key, FILE* file, ull place) {
	Data curr;
	while(place != 0) {
		curr = read_data(file, place);
		if (!strcmp(curr.key, key.c_str()))
			return place;
		place = curr.address;
	}
	return 0;
}

ull find_for_delete(string &key, FILE* file, ull place, stack<ull> &curr_free) {
	Data curr;
	ull save_place = place;
	while(place != 0) {
		curr = read_data(file, place);
		if (!strcmp(curr.key, key.c_str())) {
			Data pred_curr = read_data(file, save_place);
			pred_curr.address = curr.address;
			fseek(file, save_place, SEEK_SET);
			fwrite(&pred_curr, sizeof(pred_curr), 1, file);
			curr_free.push(place);
			return 1;
		}
		save_place = place;
		place = curr.address;
	}
	return 0;
}

int main() {
	int N;
	cin >> N;

	Hash H(PR);
	stack<ull> curr_free;
	curr_free.push(HASHSIZE * sizeof(ull));
	ull fill_zeros = 0;
	FILE* file = fopen("table.txt", "w+");
	for (int i = 0; i < HASHSIZE; ++i)
		fwrite(&fill_zeros, sizeof(ull) , 1, file); 

	for (int i = 0; i < N; ++i) {
		string comand, key, value;
		cin >> comand;
		switch (comand[0]) {
			case 'A': {
				cin >> key >> value;
				int position = H.hash(key) % HASHSIZE;
				ull place = read_position(file, position);
				if (place == 0) {
					place = write_position(file, position, curr_free);
					write_data(file, key, value, place);
				}
				else {
					ull new_place = find_free_block(key, file, place, curr_free);
					if (new_place == 0) {
						cout << "ERROR\n";
						break;
					}
					write_data(file, key, value, new_place);
				}
				break;
			}
			case 'D': {
				cin >> key;
				int position = H.hash(key) % HASHSIZE;
				ull place = read_position(file, position);
				if (place == 0) {
					cout << "ERROR\n";
					break;
				}
				else {
					Data curr = read_data(file, place);
					if (!strcmp(curr.key, key.c_str())) {
						fseek(file, position * sizeof(ull), SEEK_SET);
						fwrite(&curr.address, sizeof(ull), 1, file);
						curr_free.push(place);
						break;
					}
					if (find_for_delete(key, file, place, curr_free) == 0)
						cout << "ERROR\n";
				}
				break;
			}
			case 'U': {
				cin >> key >> value;
				int position = H.hash(key) % HASHSIZE;
				ull place = read_position(file, position);
				if (place == 0) {
					cout << "ERROR\n";
					break;
				}
				else {
					ull new_place = find_place(key, file, place);
					if (new_place == 0){
						cout << "ERROR\n";
						break;
					}
					Data curr = read_data(file, new_place);
					strcpy(curr.value, value.c_str());
					fseek(file, new_place, SEEK_SET);
					fwrite(&curr, sizeof(curr), 1, file);
				}
				break;
			}
			case 'P': {
				cin >> key;
				int position = H.hash(key) % HASHSIZE;
				ull place = read_position(file, position);
				if (place == 0) {
					cout << "ERROR\n";
					break;
				}
				else {
					ull new_place = find_place(key, file, place);
					if (new_place == 0){
						cout << "ERROR\n";
						break;
					}	
					print_data(file, new_place);
				}
				break;
			}
		}
	}

	fclose(file);
	return 0;
}