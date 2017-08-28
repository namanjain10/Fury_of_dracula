#include "map.h"
#include "Globals.h"
#include "places.h"
#include <iostream>
#include <assert.h>
using namespace std;

typedef char encounter ;

struct TrailNode {
    LocationID val;
    encounter trap;
    TrailNode* next;
};

struct Trail {
    struct TrailNode* start;
    struct TrailNode* end;
    int size;
    int currentSize;
};

void popTrail (Trail* a);

Trail* newTrail () {

    Trail* a = new Trail;
    a->start = NULL;
    a->end = NULL;
    a->currentSize = 0;
    a->size = 6;
    return a;
}

// push at end
void pushToTrail (Trail* a, LocationID k) {

    if (a->currentSize == a->size) {
        popTrail(a);
    }

    TrailNode* node = new TrailNode;
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

// void checkMaturity (TrailNode* a) {
//     if (a->trap == 'T') {
//         return ;
//     }
//     else if (a->trap == 'V') {
//         reduceScore('V');
//     }
//     else if (a->trap == 'D') {
//         reduceScore('D');
//     }
// }

// pop from front
void popTrail (Trail* a) {

    if (a->start != NULL) {
        //checkMaturity (a->start);
        TrailNode* add = a->start->next;
        delete a->start;
        a->start = add ;
        a->currentSize --;
    }
}

void printTrail (Trail* a) {
    cout << "yes\n";
    TrailNode* add = a->start;
    cout << "yes\n";
    Place* places = getPlaces ();
    cout << "yes\n";
    while (add != NULL) {
        //cout << places[add->val].id << " < ";
        //cout << places[add->val].name << " < " ;
        cout << add->val << " < ";
        add = add->next;
    }
    cout << endl;
}
