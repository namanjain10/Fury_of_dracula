#include <iostream>
using namespace std;

// struct QueueNode {
//     int val;
//     struct QueueNode* next;
// };
//
// struct Queue {
//     struct QueueNode* start;
//     struct QueueNode* end;
//     int size ;
//     int currentSize;
// };

// Queue* newQueue (int k) ;
// void push (Queue* a, int k);
// void pop (Queue* a);
// void print (Queue* a);

// int main() {
//
//     Queue* queue = newQueue (5);
//
//     int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
//
//     for (int i = 0; i<16; i++) {
//         push(queue,arr[i]);
//         print (queue);
//     }
//
//     return 0;
// }

Queue* newQueue (int k) {

    Queue* a = new Queue;
    a->start = NULL;
    a->end = NULL;
    a->size = k;
    a->currentSize = 0;

    return a;
}

// push at end
void pushQueue (Queue* a, int k) {

    if (a->currentSize == a->size) {
        popQueue(a);
    }

    struct QueueNode* node = new QueueNode;
    node->val = k;
    node->next = NULL;

    if (a->start == NULL) {
        a->start = node;
    }
    else if (a->end != NULL) {
        a->end->next = node;
    }
    a->end = node;
    a->currentSize ++;
}

// pop from front
void popQueue (Queue* a) {

    if (a->start != NULL) {
        QueueNode* add = a->start->next;
        delete a->start;
        a->start = add ;
        a->currentSize --;
    }
}

void printQueue (Queue* a) {
    QueueNode* add = a->start;

    while (add != NULL) {
        cout << add->val << " < " ;
        add = add->next;
    }
    cout << endl;
}
