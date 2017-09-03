#include <iostream>
#include "list.h"
using namespace std;

struct Node {
    int val;
    int weight;
    int mode;
    int prev;
    Node* next;
};

struct List {
    Node* start;
};

// int main() {
//
//     List* naman = newList();
//
//     pushList(naman,3,4);
//     pushList(naman,6,7);
//     pushList(naman,9,4);
//     pushList(naman,2,2);
//     pushList(naman,1,4);
//
//     printList(naman);
//
// }

List* newList () {

    List* a = new List;
    a->start = NULL;
    return a;
}

void pushList (List* a, int k, int x, int m, int q) {

    Node* add = a->start;
    Node* p = new Node;
    p->val = k;
    p->weight = x;
    p->mode = m;
    p->prev = q;
    p->next = NULL;

    if (add == NULL) {
        a->start = p;
    }

    else {
        while (add->next != NULL) {
            add = add->next;
        }
        add->next = p;
    }
}

void printList (List* a) {

    Node* add = a->start;
    while (add != NULL) {
        cout << add->val << "," << add->mode << ","  << add->prev << ","<< add->weight <<  "  " ;
        add = add->next;
    }
    cout << endl;
}

int checkList (List* a, int x, int w) {
    Node* add = a->start;

    while (add != NULL) {
        if (add->val == x) {
            return 1;
        }
        add = add->next;
    }
    return 0;
}

int prevList (List* a, int x) {

    Node* add = a->start;
    while (add->val != x) {
        add = add->next;
    }
    return add->prev;
}
