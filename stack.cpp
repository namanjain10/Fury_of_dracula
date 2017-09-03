#include <iostream>
#include "stack.h"
#include <assert.h>
//#include "places.h"
using namespace std;

// struct Stack {
//     struct StackNode* start;
//     struct StackNode* end;
// };
//
// struct StackNode {
//     int val;
//     struct StackNode* next;
// };
//
// Stack* newStack ();
// void push (struct Stack* a, int k);
// void pop (struct Stack* a);
// void print (struct Stack* a) ;
// push at start

Stack* newStack () {

    Stack* a = new Stack;
    a->start = NULL;
    a->end = NULL;

    return a;
}

void pushStack (Stack* a, int k) {

    struct StackNode* add = new StackNode;
    add->val = k;

    if (a->start == NULL) {
        a->start = add;
        add->next = NULL;
        a->end = add;
    }

    else {
        add->next = a->start;
        a->start = add;
    }
}

// pop from start
void popStack (Stack* a) {

    if (a->start != NULL) {
        StackNode* add = a->start->next;
        delete a->start;
        a->start = add;
    }
}

void printStack (Stack* a) {

    StackNode* add = a->start;

    while (add != NULL) {

        //char* s = getName(add->val);
        cout << add->val << " < " ;
        add = add->next;
    }
    cout << endl;
}
