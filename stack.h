struct StackNode {
    int val;
    StackNode* next;
};

struct Stack {
    StackNode* start;
    StackNode* end;
};

Stack* newStack ();
void pushStack (Stack* a, int k);
void popStack (Stack* a);
void printStack (Stack* a) ;
