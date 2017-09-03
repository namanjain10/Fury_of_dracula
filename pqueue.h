struct PqueueNode {
    int val;
    int priority;
    int mode;
    int prev;
    PqueueNode* next;
};

struct Pqueue {
    PqueueNode* start;
};

Pqueue* newPqueue ();
//void pushPqueue (Pqueue* a, int val, int k, int);
void pushPqueue (Pqueue* a, int val, int k, int, int);

void printPqueue (Pqueue* a);
PqueueNode* popPqueue (Pqueue* a);
void deletePqueueNode (Pqueue* a, PqueueNode* w);
int checkPqueue (Pqueue* a, int x, int w);
int getSize (Pqueue* a);
