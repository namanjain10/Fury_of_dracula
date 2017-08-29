#include "map.h"
#include "Globals.h"

// struct TrailNode;
// struct Trail;
// struct State;

struct TrailNode {
    LocationID val;
    Encounter trap;
    TrailNode* next;
};

struct Trail {
    TrailNode* start;
    TrailNode* end;
    int size;
    int nHides;
    int nDoubleBack;
    int currentSize;
};

struct State {
    Encounter trap;
    int hides;
};

Trail* newTrail ();
State* pushToTrail (Trail* a, LocationID k, Encounter t);
void printTrail (Trail* a);
void push (Trail*);
