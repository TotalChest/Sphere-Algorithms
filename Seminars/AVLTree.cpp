#include <string>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;


class FastRandom {
private:
    unsigned long long rnd;
public:
    FastRandom() {
        rnd = 1;
    }
    void seed(unsigned long long seed) {
        rnd = seed;
    }
    unsigned long long rand() {
        rnd ^= rnd << 21;
        rnd ^= rnd >> 35;
        rnd ^= rnd << 4;
        return rnd;
    }
};


struct AVLNode {
    AVLNode *left = nullptr, *right = nullptr; 
    string key;
    int height = 1;
    AVLNode(string const &_key) : key(_key) {}
    AVLNode(string const &&_key) : key(_key) {}
    int getBalanceFactor() const {
        int r = right == nullptr ? 0 : right->height;
        int l = left == nullptr ? 0 : left->height;
        return r - l;
    }
    void fix() {
        int r = right == nullptr ? 0 : right->height;
        int l = left == nullptr ? 0 : left->height;
        height = (r > l ? r : l) + 1;
    }
    AVLNode *rotateLeft() {
        AVLNode *t = right;
        right = t->left;
        t->left = this;
        fix();
        t->fix();
        return t;
    }
    AVLNode *rotateRight() {
        AVLNode *t = left;
        left = t->right;
        t->right = this;
        fix();
        t->fix();
        return t;
    }
    AVLNode *balance() {
        fix();
        switch (getBalanceFactor()) {
        case -2: 
            if (left->getBalanceFactor() > 0) {
                left = left->rotateLeft();
            }
            return rotateRight();
        case 2:
            if (right->getBalanceFactor() < 0) {
                right = right->rotateRight();
            }
            return rotateLeft();
        default:
            return this;
        }
    }
    AVLNode *insert(string const &_key) {
    	if (_key < key)
            left = left == nullptr ? new AVLNode(_key) : left->insert(_key);
        else
            right = right == nullptr ? new AVLNode(_key) : right->insert(_key);
        return balance();
    }
    AVLNode *findMinimum() {
        return left != nullptr ? left->findMinimum() : this;
    }   

    AVLNode *removeMinimum() {
        if (left == NULL) return right;
        left = left->removeMinimum();
        return balance();
    }

    static AVLNode *remove(AVLNode *p, string const &_key) {
        if (p == NULL) return NULL;
        if (_key < p->key) {
            p->left = remove(p->left, _key);
            return p->balance();
        } else if (_key > p->key) {
            p->right = remove(p->right, _key);
            return p->balance();
        } else {
            AVLNode *l = p->left;
            AVLNode *r = p->right;
            delete p;
            if (r == nullptr) return l;
            AVLNode *min = r->findMinimum();
            min->right = r->removeMinimum();
            min->left = l;
            return min->balance();
        }
    }

    void print() {
        if (right != NULL) right->print();
        for (int i = 6; i >= height; i--) {
            printf("  ");
        }
        printf("[%s]\n", key.c_str());
        if (left != NULL) left->print();
    }
};

struct AVLTree {
    AVLNode *root;
    AVLTree() {
        root = NULL;
    }
    void print() const {
        if (root != NULL) root->print();
    }

    bool insert(string const &_key) {
        if (root == NULL) root = new AVLNode(move(_key));
        else root = root->insert(move(_key));
        return true;
    }

    bool remove(string const &_key) {
        root = AVLNode::remove(root, _key);
        return true;
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
    AVLTree t;
    clock_t s1 = clock();
    for (auto const &s: pat) {
        t.insert(s);
    }
    clock_t s12 = clock();
    for (auto const &s: pat) {
        t.remove(s);
    }
    clock_t e1 = clock();

    set<string> se1;
    clock_t s2 = clock();
    for (auto const &s: pat) {
        se1.insert(s);
    }
    clock_t s22 = clock();
    for (auto const &s: pat) {
      se1.erase(s);
    }
    clock_t e2 = clock();
    
    printf("AVL_INS=%.3f AVL_REM=%.3f SET_INS=%.3f SET_REM=%.3f\n", 
      (double)(s12 - s1) / CLOCKS_PER_SEC,
      (double)(e1  - s12) / CLOCKS_PER_SEC, 
      (double)(s22 - s2) / CLOCKS_PER_SEC,
      (double)(e2 - s22) / CLOCKS_PER_SEC);
}
