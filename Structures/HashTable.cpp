#include <functional>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <vector>
#include <cstdlib>
using namespace std;

class HashTable {
private:
	vector<const char *> table;
	hash<string> hs;
public:
  	HashTable(size_t size = 101) {
    	table.resize(size);
  	}

  	~HashTable() {
  		for(unsigned i = 0; i < table.size(); ++i)
  			if(!(table[i] == nullptr) && !(table[i] == (const char *)-1))
  				free((char *)table[i]);
  	}
  
 	bool insert(const char *key) {
    	unsigned h = hs(string(key)) % table.size();
    	for (;;) {
      	if (table[h] == nullptr || table[h] == (const char *)-1) {
        	table[h] = strdup(key);
        	return true;
      		}
      		h = (h+1) % table.size();
    	}
  	}

  	bool remove(const char *key) {
    	for (unsigned h = hs(string(key)) % table.size(); ; h = (h+1) % table.size()) {
      		if (table[h] == nullptr) return false;
      		if (table[h] == (const char *)-1) continue;
      		if (strcmp(table[h],key) == 0) {
        		free((char *)table[h]);
        		table[h] = (const char *)-1;
        		return true;
      		}
    	}
  	}

  	bool find(const char *key) {
  		for (unsigned h = hs(string(key)) % table.size(); ; h = (h+1) % table.size()) {
  			if (table[h] == nullptr) return false;
  			if (table[h] == (const char *)-1) continue;
  			if (strcmp(table[h],key) == 0)
  				return true;
  		}
  	}

  	void print() {
  		for (unsigned i = 0; i < table.size(); ++i)
  			if (table[i] == nullptr)
  				printf("null\n");
  			else if (table[i] == (const char *)-1)
  				printf("deleted\n");
  			else
  				printf("%s\n", table[i]);
  	}
};

int main() {
    const int SIZE = 1000;
    srand(time(NULL));
    vector<string> pat;
    for (int i = 0; i < SIZE; i++) {
        string s = "s" + to_string(rand()%10000);
        pat.push_back(s);
    }
    HashTable t(SIZE*3+4);
    for (auto const &s: pat) {
        t.insert(s.c_str());
    }
    printf("%d\n", t.find("s100"));
    //t.print();
    for (auto const &s: pat) {
        t.remove(s.c_str());
    }
    //t.print();
}