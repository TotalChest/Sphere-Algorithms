#include "crc.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
#include "FastRandom.h"
using namespace std;

class HashTable {
private:
	vector<const char *> table;
 	CRCCoder<unsigned> coder;
public:
  	HashTable(size_t size = 101) {
    	table.resize(size);
    	coder.init();
  	}

  	~HashTable() {
  		for(unsigned i = 0; i < table.size(); ++i)
  			if(!(table[i] == nullptr) && !(table[i] == (const char *)-1))
  				free((char *)table[i]);
  	}
  
 	bool insert(const char *key) {
    	unsigned h = coder.calc(key) % table.size();
    	for (;;) {
      	if (table[h] == nullptr || table[h] == (const char *)-1) {
        	table[h] = strdup(key);
        	return true;
      		}
      		h = (h+1) % table.size();
    	}
  	}

  	bool remove(const char *key) {
    	for (unsigned h = coder.calc(key) % table.size(); ; h = (h+1) % table.size()) {
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
  		for (unsigned h = coder.calc(key) % table.size(); ; h = (h+1) % table.size()) {
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
    const int SIZE = 1000001;
    FastRandom r;
    r.seed(time(NULL));
    vector<string> pat;
    for (int i = 0; i < SIZE; i++) {
        string s = "s" + to_string(r.rand()%10000000000);
        pat.push_back(s);
    }
    HashTable t(SIZE*3+4);
    clock_t s1 = clock();
    for (auto const &s: pat) {
        t.insert(s.c_str());
    }
    t.print();
    for (auto const &s: pat) {
        t.remove(s.c_str());
    }
    clock_t e1 = clock();

    unordered_set<string> uset(SIZE*3+4);
    clock_t s2 = clock();
    for (auto const &s: pat) {
        uset.insert(s);
    }
    for (auto const &s: pat) {
      uset.erase(s);
    }
    clock_t e2 = clock();
    printf("HT=%.3f USET=%.3f\n", 
      (double)(e1 - s1) / CLOCKS_PER_SEC, 
      (double)(e2 - s2) / CLOCKS_PER_SEC);
}

