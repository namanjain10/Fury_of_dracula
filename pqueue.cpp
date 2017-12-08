#include <iostream>
#include "pqueue.h"
#include <assert.h>

using namespace std;

Pqueue* newPqueue () {
    Pqueue* a = new Pqueue;
    a->start = NULL;
    return a;
}

PqueueNode* popPqueue (Pqueue* a) {

    PqueueNode* d = a->start;
    assert(a->start != NULL);

    a->start = a->start->next;
    return d;
}

int getSize (Pqueue* a) {
    int c = 0;

    PqueueNode* add = a->start;

    while (add != NULL) {
        c++;
        add = add->next;
    }
    return c;
}

void pushPqueue (Pqueue* a, int val, int k, int m, int p) {

    PqueueNode* add = a->start ;
    PqueueNode* d = new PqueueNode;
    PqueueNode* prev;
    PqueueNode* curr;

    d->val = val;
    d->priority = k;
    d->mode = m;
    d->prev = p;

    if (a->start == NULL) {
        a->start = d;
        d->next = NULL;

    }
    else {
        curr = add;
        prev = NULL;

        while (curr != NULL) {
            if (curr->priority > k) break;
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL) {
            d->next = add;
            a->start = d;
        }

        else {
            prev->next = d;
            d->next = curr;
        }
    }
}

void printPqueue (Pqueue* a) {
    PqueueNode* add = a->start;

    while (add != NULL) {
        cout << add->val << " < " ;
        add = add->next;
    }
    cout << endl;
}

void deletePqueueNode (Pqueue* a, PqueueNode* w) {

    PqueueNode *add = a->start ;

    if (add == w) {
        a->start = w;
    }

    else {

        while (add->next != NULL) {
            if (add->next == w) {

                PqueueNode* temp = w->next;
                add->next = temp;
                delete w ;
            }
            add = add->next;
        }
    }
}

int checkPqueue (Pqueue* a, int x, int w) {
    PqueueNode* add = a->start;
    int k;

    while (add != NULL) {
        if (add->val == x) {
            return 1;
        }
        add = add->next;
    }
    return 0;
}
