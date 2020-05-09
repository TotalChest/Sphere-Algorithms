#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int N = 10000;

struct bhnode {
   int priority;
   string value;
};

class priority_queue {
public:
   priority_queue(int MAX) {
      body = new bhnode[maxsize = MAX+1];
      numnodes = 0;
   }

   ~priority_queue() {
      delete [] body;
   }
   
   int insert(bhnode node) {
     if (numnodes > maxsize) {
        return -1;
     }
     body[++numnodes] = node;
     for (int i = numnodes; i > 1 &&
       body[i].priority < body[i/2].priority;
       i /= 2) {
        swap(i, i/2);
     }
     return 0; 
   }  

   bhnode *fetchMin() {
      return numnodes == 0? NULL : body + 1;
   }

   int removeMin() {
      if (numnodes == 0) return -1;
      body[1] = body[numnodes--];
      heapify(1);
      return 0;
   }
private:
   void heapify(int index) {
      for (;;) {
         int left = index + index; int right = left + 1;
         int largest = index;
         if (left <= numnodes &&
           body[left].priority < body[index].priority)
             largest = left;
         if (right <= numnodes &&
           body[right].priority < body[largest].priority)
              largest = right;
         if (largest == index) break;
         swap(index, largest);
         index = largest;
      }
   }

   void swap(int n1, int n2) {
      bhnode t = body[n1];
      body[n1] = body[n2];
      body[n2] = t;
   }
   bhnode *body;
   int numnodes;
   int maxsize;
};

int priority(string str, int k) {
	int pr = k;
	for(int i = 0; i < 9; ++i)
		if(str[i] != '0'+(i+1))
			++pr;
	return pr;
}

bool check(string str) {
	for(int i = 0; i < 8; ++i)
		if(str[i] != '0'+(i+1))
			return false;
	return true;
}


int main() {

	string tbl("");
	for(int i = 0; i < 11; ++i){
		char d = getchar();
		if(d == '\n')
			continue;
		if(d == ' ')	
			tbl += 'a';
		else
			tbl += d;
	}

	int k = 0;

	priority_queue PQ(N);
	bhnode tmp;
	tmp.priority = priority(tbl, k);
	tmp.value = tbl;
	PQ.insert(tmp);

	while(!check(tbl)) {
		++k;

		if (k > 10000) {
			cout << -1;
			return 0;
		}
		bhnode *p = PQ.fetchMin();
		tbl = p->value;
		PQ.removeMin();

		int space = tbl.find("a");

		if(space == 4) {
			string str = tbl;
			char c = str[1];
			str[1] = str[4];
			str[4] = c;
			tmp.priority = priority(str, k);
			tmp.value = str;
			PQ.insert(tmp);

			str = tbl;
			c = str[1];
			str[7] = str[7];
			str[7] = c;
			tmp.priority = priority(str, k);
			tmp.value = str;
			PQ.insert(tmp);

			str = tbl;
			c = str[1];
			str[1] = str[5];
			str[5] = c;
			tmp.priority = priority(str, k);
			tmp.value = str;
			PQ.insert(tmp);

			str = tbl;
			c = str[1];
			str[1] = str[3];
			str[3] = c;
			tmp.priority = priority(str, k);
			tmp.value = str;
			PQ.insert(tmp);
		}

		else if(space == 1 || space == 7) {
			string str = tbl;
			char c = str[space-1];
			str[space-1] = str[space];
			str[space] = c;
			tmp.priority = priority(str, k);
			tmp.value = str;
			PQ.insert(tmp);

			str = tbl;
			c = str[space+1];
			str[space+1] = str[space];
			str[space] = c;
			tmp.priority = priority(str, k);
			tmp.value = str;
			PQ.insert(tmp);
		}

		else if(space == 3 || space == 5) {
			string str = tbl;
			char c = str[space-3];
			str[space-3] = str[space];
			str[space] = c;
			tmp.priority = priority(str, k);
			tmp.value = str;
			PQ.insert(tmp);

			str = tbl;
			c = str[space+3];
			str[space+3] = str[space];
			str[space] = c;
			tmp.priority = priority(str, k);
			tmp.value = str;
			PQ.insert(tmp);
		}

		else if(space == 0) {
			string str = tbl;
			char c = str[1];
			str[1] = str[space];
			str[space] = c;
			tmp.priority = priority(str, k);
			tmp.value = str;
			PQ.insert(tmp);

			str = tbl;
			c = str[3];
			str[3] = str[space];
			str[space] = c;
			tmp.priority = priority(str, k);
			tmp.value = str;
			PQ.insert(tmp);
		}

		else if(space == 2) {
			string str = tbl;
			char c = str[1];
			str[1] = str[space];
			str[space] = c;
			tmp.priority = priority(str, k);
			tmp.value = str;
			PQ.insert(tmp);

			str = tbl;
			c = str[5];
			str[5] = str[space];
			str[space] = c;
			tmp.priority = priority(str, k);
			tmp.value = str;
			PQ.insert(tmp);
		}

		else if(space == 6) {
			string str = tbl;
			char c = str[3];
			str[3] = str[space];
			str[space] = c;
			tmp.priority = priority(str, k);
			tmp.value = str;
			PQ.insert(tmp);

			str = tbl;
			c = str[7];
			str[7] = str[space];
			str[space] = c;
			tmp.priority = priority(str, k);
			tmp.value = str;
			PQ.insert(tmp);
		}

		else if(space == 8) {
			string str = tbl;
			char c = str[5];
			str[5] = str[space];
			str[space] = c;
			tmp.priority = priority(str, k);
			tmp.value = str;
			PQ.insert(tmp);

			str = tbl;
			c = str[7];
			str[7] = str[space];
			str[space] = c;
			tmp.priority = priority(str, k);
			tmp.value = str;
			PQ.insert(tmp);
		}
	}

	cout << k;

	return 0;
}