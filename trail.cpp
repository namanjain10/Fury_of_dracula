// not covering 3 encounter at a location

//#include "map.h"
#include "Globals.h"
#include "places.h"
#include <iostream>
#include <assert.h>
#include "trail.h"
using namespace std;

typedef char encounter ;

// struct TrailNode {
//     LocationID val;
//     Queue* trap;
//     TrailNode* next;
// };
//
// struct Trail {
//     TrailNode* start;
//     TrailNode* end;
//     int size;
//     int nHides;
//     int nDoubleBack;
//     int currentSize;
// };
//
// struct State {
//     Encounter trap;
//     int hides;
// };

Encounter popTrail (Trail* a);
int checkHide (Trail* a, LocationID loc);

Trail* newTrail () {

    Trail* a = new Trail;
    a->start = NULL;
    a->end = NULL;
    a->currentSize = 0;
    a->trap = newQueue (6);
    a->size = 6;
    // a->nHides = 0;
    // a->nDoubleBack = 0;
    return a;
}

// push at end
void push (Trail* a) {

    TrailNode* node = new TrailNode;
    node->val = NOWHERE;

    for (int i=0; i<6; i++) {
        node->trap = NO_ENCOUNTER;
    }
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

State* pushToTrail (Trail* a, LocationID k, Encounter t) {

    State* s = new State;

    Encounter q = -1;
    // int h = checkHide (a,k);
    //
    // if (h == HIDE) {
    //     a->nHides = a->nHides + 1;
    // }
    //
    // else if (h == DOUBLE_BACK_1 || h == DOUBLE_BACK_2 || h == DOUBLE_BACK_3 || h == DOUBLE_BACK_4 || h == DOUBLE_BACK_5) {
    //     a->nDoubleBack = a->nDoubleBack + 1;
    // }
    //
    // assert (a->nHides < 3 && a->nDoubleBack < 3);

    if (a->currentSize == a->size) {
        q = popTrail(a);
    }

    TrailNode* node = new TrailNode;
    node->val = k;
    node->trap = t;
    node->next = NULL;

    if (a->start == NULL) {
        a->start = node;
    }
    else if (a->end != NULL) {
        a->end->next = node;
    }
    a->end = node;
    a->currentSize ++;

    s->trap = q;
    s->hides = h;

    return s;
}

// void checkMaturity (TrailNode* a) {
//     if (a->trap == TRAP) {
//         return ;
//     }
//
//     else if (a->trap == VAMPIRE) {
//
//     }
//
//     else if (a->trap == DRACULA) {
//
//     }
//
//     else {
//
//     }
// }

// pop from front
Encounter popTrail (Trail* a) {

    if (a->start != NULL) {
        Encounter q = a->start->trap;
        TrailNode* add = a->start->next;
        delete a->start;
        a->start = add ;
        a->currentSize --;
        return q;
    }
}

void printTrail (Trail* a) {
    cout << "yes\n";
    TrailNode* add = a->start;
    cout << "yes\n";

    cout << "yes\n";
    while (add != NULL) {
        //cout << places[add->val].id << " < ";
        //cout << places[add->val].name << " < " ;
        cout << add->val << " < ";
        add = add->next;
    }
    cout << endl;
}

int checkHide (Trail* a, LocationID loc) {

    if (a->start->val == loc) {
        return HIDE;
    }

    else {
        int count = 1;
        int q = 0;

        TrailNode* add = a->start->next;

        while (add != NULL) {
            if (add->val == loc) {
                q = 1;
                break;
            }
            count ++;
            add = add->next;
        }
            if (q == 1) {

                if (count == 1) {
                    return DOUBLE_BACK_1;
                }

                else if (count == 2) {
                    return DOUBLE_BACK_2;
                }

                else if (count == 3) {
                    return DOUBLE_BACK_3;
                }

                else if (count == 4) {
                    return DOUBLE_BACK_4;
                }

                else if (count == 5) {
                    return DOUBLE_BACK_5;
                }
            }

            else {
                return 0;
            }
    }
}
