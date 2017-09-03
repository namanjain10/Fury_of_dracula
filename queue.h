struct QueueNode {
    int val;
    QueueNode* next;
};

struct Queue {
    QueueNode* start;
    QueueNode* end;
    int size ;
    int currentSize;
};

Queue* newQueue (int k) ;
void pushQueue (Queue* a, int k);
void popQueue (Queue* a);
void printQueue (Queue* a);
