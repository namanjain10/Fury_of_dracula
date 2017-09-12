struct QueueNode {
    int val;
    int place;
    int nT;
    int nV;
    QueueNode* next;
};

struct Queue {
    QueueNode* start;
    QueueNode* end;
    int size ;
    int currentSize;
};

Queue* newQueue (int k) ;
void pushQueue (Queue* a, int k, int p, int, int);
void popQueue (Queue* a);
void printQueue (Queue* a);
QueueNode* findNode (Queue* a, int location);
