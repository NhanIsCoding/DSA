#include "Header.h"

BTree* init(BTree*&r,BTree*&np,BTree*&x) {
    int i;
    np = new BTree;
    np->d = new int[6];
    np->childPointer = new BTree * [7];
    np->l = true;
    np->n = 0;
    for (i = 0; i < 7; i++) {
        np->childPointer[i] = NULL;
    }
    return np;
}

void sort(int* p, int n) {
    int i, j, t;
    for (i = 0; i < n; i++) {
        for (j = i; j <= n; j++) {
            if (p[i] > p[j]) {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
}

int splitChild(BTree*&r,BTree*&np,BTree*&x, int i) {
    int j, mid;
    BTree* np1, * np3, * y;
    np3 = init(r,np,x);
    np3->l = true;
    if (i == -1) {
        mid = x->d[2];
        x->d[2] = 0;
        x->n--;
        np1 = init( * &r, * &np, * &x);
        np1->l = false;
        x->l = true;
        for (j = 3; j < 6; j++) {
            np3->d[j - 3] = x->d[j];
            np3->childPointer[j - 3] = x->childPointer[j];
            np3->n++;
            x->d[j] = 0;
            x->n--;
        }
        for (j = 0; j < 6; j++) {
            x->childPointer[j] = NULL;
        }
        np1->d[0] = mid;
        np1->childPointer[np1->n] = x;
        np1->childPointer[np1->n + 1] = np3;
        np1->n++;
        r = np1;
    }
    else {
        y = x->childPointer[i];
        mid = y->d[2];
        y->d[2] = 0;
        y->n--;
        for (j = 3; j < 6; j++) {
            np3->d[j - 3] = y->d[j];
            np3->n++;
            y->d[j] = 0;
            y->n--;
        }
        x->childPointer[i + 1] = y;
        x->childPointer[i + 1] = np3;
    }
    return mid;
}

void insert(BTree*& r, BTree*& np, BTree*& x,int a) {
    int i, t;
    x = r;
    if (x == NULL) {
        r = init(r,np,x);
        x = r;
    }
    else {
        if (x->l == true && x->n == 6) {
            t = splitChild(r,np,x, -1);
            x = r;
            for (i = 0; i < (x->n); i++) {
                if ((a > x->d[i]) && (a < x->d[i + 1])) {
                    i++;
                    break;
                }
                else if (a < x->d[0]) {
                    break;
                }
                else {
                    continue;
                }
            }
            x = x->childPointer[i];
        }
        else {
            while (x->l == false) {
                for (i = 0; i < (x->n); i++) {
                    if ((a > x->d[i]) && (a < x->d[i + 1])) {
                        i++;
                        break;
                    }
                    else if (a < x->d[0]) {
                        break;
                    }
                    else {
                        continue;
                    }
                }
                if ((x->childPointer[i])->n == 6) {
                    t = splitChild(r,np,x, i);
                    x->d[x->n] = t;
                    x->n++;
                    continue;
                }
                else {
                    x = x->childPointer[i];
                }
            }
        }
    }
    x->d[x->n] = a;
    sort(x->d, x->n);
    x->n++;
}

void traverseBtree(BTree* p) {
    cout << endl;
    int i;
    for (i = 0; i < p->n; i++) {
        if (p->l == false) {
            traverseBtree(p->childPointer[i]);
        }
        cout << " " << p->d[i];
    }
    if (p->l == false) {
        traverseBtree(p->childPointer[i]);
    }
    cout << endl;
}