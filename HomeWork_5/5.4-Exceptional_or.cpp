#include <bits/stdc++.h>
using namespace std;

struct Tree {
	Tree *children[2];
	unsigned long long value; 
	Tree() {
		children[0] = children[1] = nullptr;
		value = 0;
	}
};

void insert(Tree *t, unsigned long long A) {
	Tree *curr = t;
	for(int i = 31; i >= 0; --i) {
		int index = (A>>i)&1u;
		if(curr->children[index])
			curr = curr->children[index];
		else {
			curr->children[index] = new Tree;
			curr = curr->children[index];
		}
	}
	curr->value = A;
}

bool remove_elem(Tree *t, unsigned long long A, int height) {
	Tree *curr = t;
	if(height == 0) {
		delete curr;
		return true;
	}
	int index = (A>>(height-1))&1u;
	if(curr == nullptr)
		return false;
	if(remove_elem(curr->children[index], A, height-1))
		if(curr->children[index ? 0 : 1]) {
			curr->children[index] = nullptr;
			return false;
		}
		else {
			delete curr;
			return true;
		}
	return false;
}

void remove(Tree *t, unsigned long long A, int height) {
	if(remove_elem(t->children[A>>height-1], A, height-1))
		t->children[A>>height-1] = nullptr;
}

unsigned long long findMax(Tree *t, unsigned long long Q) {
	Tree *curr = t;
	for(int i = 31; i >= 0; --i) {
		int index = (Q>>i)&1u ? 0 : 1;
		if(curr->children[index])
			curr = curr->children[index];
		else 
			curr = curr->children[index ? 0 : 1];
	}
	return curr->value;
}

void print(Tree *t, int height) {
	if (t->children[1] != nullptr) print(t->children[1],height-1);
    for (int i = 32; i >= height; i--) {
        printf("  ");
    }
    printf("[%llu]\n", t->value);
    if (t->children[0] != nullptr) print(t->children[0],height-1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unsigned long long N, com, arg;
	cin >> N;
	Tree *t = new Tree;
	for(unsigned long long i = 0; i < N; ++i) {
		cin >> com >> arg;
		switch(com) {
			case 1:
				insert(t, arg);
				break;
			case 2:
				remove(t, arg, 32);
				break;
			case 3:
				cout << findMax(t, arg) << '\n';
				break;
		}
	}	
}