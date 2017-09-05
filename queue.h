struct QueueNode {
    int val;
    int place;
    QueueNode* next;
};

struct Queue {
    QueueNode* start;
    QueueNode* end;
    int size ;
    int currentSize;
};

Queue* newQueue (int k) ;
void pushQueue (Queue* a, int k, int p);
void popQueue (Queue* a);
void printQueue (Queue* a);
