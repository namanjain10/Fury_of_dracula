#include "map.h"
#include <iostream>
#include <assert.h>
#include "Globals.h"
#include "list.h"
#include "pqueue.h"
#include "places.h"
//#include "stack.h"

using namespace std;

int validV (GraphRep* g, LocationID v);
int sameEdge (GraphRep* a, LocationID from, LocationID to, TransportID x);

// struct graphNode {
// 	LocationID location;
// 	TransportID mode ;
// 	graphNode* next;
// };

// struct GraphRep {
// 	int nV;
// 	graphNode** arr;
// };

//constucts map according to the data provided
void constMap (GraphRep* g) {
    //### RAIL Connections ###

    addLink(g, ALICANTE, BARCELONA, RAIL);
    addLink(g, ALICANTE, MADRID, RAIL);
    addLink(g, BARCELONA, SARAGOSSA, RAIL);
    addLink(g, BARI, NAPLES, RAIL);
    addLink(g, BELGRADE, SOFIA, RAIL);
    addLink(g, BELGRADE, SZEGED, RAIL);
    addLink(g, BERLIN, HAMBURG, RAIL);
    addLink(g, BERLIN, LEIPZIG, RAIL);
    addLink(g, BERLIN, PRAGUE, RAIL);
    addLink(g, BORDEAUX, PARIS, RAIL);
    addLink(g, BORDEAUX, SARAGOSSA, RAIL);
    addLink(g, BRUSSELS, COLOGNE, RAIL);
    addLink(g, BRUSSELS, PARIS, RAIL);
    addLink(g, BUCHAREST, CONSTANTA, RAIL);
    addLink(g, BUCHAREST, GALATZ, RAIL);
    addLink(g, BUCHAREST, SZEGED, RAIL);
    addLink(g, BUDAPEST, SZEGED, RAIL);
    addLink(g, BUDAPEST, VIENNA, RAIL);
    addLink(g, COLOGNE, FRANKFURT, RAIL);
    addLink(g, EDINBURGH, MANCHESTER, RAIL);
    addLink(g, FLORENCE, MILAN, RAIL);
    addLink(g, FLORENCE, ROME, RAIL);
    addLink(g, FRANKFURT, LEIPZIG, RAIL);
    addLink(g, FRANKFURT, STRASBOURG, RAIL);
    addLink(g, GENEVA, MILAN, RAIL);
    addLink(g, GENOA, MILAN, RAIL);
    addLink(g, LEIPZIG, NUREMBURG, RAIL);
    addLink(g, LE_HAVRE, PARIS, RAIL);
    addLink(g, LISBON, MADRID, RAIL);
    addLink(g, LIVERPOOL, MANCHESTER, RAIL);
    addLink(g, LONDON, MANCHESTER, RAIL);
    addLink(g, LONDON, SWANSEA, RAIL);
    addLink(g, MADRID, SANTANDER, RAIL);
    addLink(g, MADRID, SARAGOSSA, RAIL);
    addLink(g, MARSEILLES, PARIS, RAIL);
    addLink(g, MILAN, ZURICH, RAIL);
    addLink(g, MUNICH, NUREMBURG, RAIL);
    addLink(g, NAPLES, ROME, RAIL);
    addLink(g, PRAGUE, VIENNA, RAIL);
    addLink(g, SALONICA, SOFIA, RAIL);
    addLink(g, SOFIA, VARNA, RAIL);
    addLink(g, STRASBOURG, ZURICH, RAIL);
    addLink(g, VENICE, VIENNA, RAIL);


   addLink(g, ALICANTE, GRANADA, ROAD);
   addLink(g, ALICANTE, MADRID, ROAD);
   addLink(g, ALICANTE, SARAGOSSA, ROAD);
   addLink(g, AMSTERDAM, BRUSSELS, ROAD);
   addLink(g, AMSTERDAM, COLOGNE, ROAD);
   addLink(g, ATHENS, VALONA, ROAD);
   addLink(g, BARCELONA, SARAGOSSA, ROAD);
   addLink(g, BARCELONA, TOULOUSE, ROAD);
   addLink(g, BARI, NAPLES, ROAD);
   addLink(g, BARI, ROME, ROAD);
   addLink(g, BELGRADE, BUCHAREST, ROAD);
   addLink(g, BELGRADE, KLAUSENBURG, ROAD);
   addLink(g, BELGRADE, SARAJEVO, ROAD);
   addLink(g, BELGRADE, SOFIA, ROAD);
   addLink(g, BELGRADE, ST_JOSEPH_AND_ST_MARYS, ROAD);
   addLink(g, BELGRADE, SZEGED, ROAD);
   addLink(g, BERLIN, HAMBURG, ROAD);
   addLink(g, BERLIN, LEIPZIG, ROAD);
   addLink(g, BERLIN, PRAGUE, ROAD);
   addLink(g, BORDEAUX, CLERMONT_FERRAND, ROAD);
   addLink(g, BORDEAUX, NANTES, ROAD);
   addLink(g, BORDEAUX, SARAGOSSA, ROAD);
   addLink(g, BORDEAUX, TOULOUSE, ROAD);
   addLink(g, BRUSSELS, COLOGNE, ROAD);
   addLink(g, BRUSSELS, LE_HAVRE, ROAD);
   addLink(g, BRUSSELS, PARIS, ROAD);
   addLink(g, BRUSSELS, STRASBOURG, ROAD);
   addLink(g, BUCHAREST, CONSTANTA, ROAD);
   addLink(g, BUCHAREST, GALATZ, ROAD);
   addLink(g, BUCHAREST, KLAUSENBURG, ROAD);
   addLink(g, BUCHAREST, SOFIA, ROAD);
   addLink(g, BUDAPEST, KLAUSENBURG, ROAD);
   addLink(g, BUDAPEST, SZEGED, ROAD);
   addLink(g, BUDAPEST, VIENNA, ROAD);
   addLink(g, BUDAPEST, ZAGREB, ROAD);
   addLink(g, CADIZ, GRANADA, ROAD);
   addLink(g, CADIZ, LISBON, ROAD);
   addLink(g, CADIZ, MADRID, ROAD);
   addLink(g, CASTLE_DRACULA, GALATZ, ROAD);
   addLink(g, CASTLE_DRACULA, KLAUSENBURG, ROAD);
   addLink(g, CLERMONT_FERRAND, GENEVA, ROAD);
   addLink(g, CLERMONT_FERRAND, MARSEILLES, ROAD);
   addLink(g, CLERMONT_FERRAND, NANTES, ROAD);
   addLink(g, CLERMONT_FERRAND, PARIS, ROAD);
   addLink(g, CLERMONT_FERRAND, TOULOUSE, ROAD);
   addLink(g, COLOGNE, FRANKFURT, ROAD);
   addLink(g, COLOGNE, HAMBURG, ROAD);
   addLink(g, COLOGNE, LEIPZIG, ROAD);
   addLink(g, COLOGNE, STRASBOURG, ROAD);
   addLink(g, CONSTANTA, GALATZ, ROAD);
   addLink(g, CONSTANTA, VARNA, ROAD);
   addLink(g, DUBLIN, GALWAY, ROAD);
   addLink(g, EDINBURGH, MANCHESTER, ROAD);
   addLink(g, FLORENCE, GENOA, ROAD);
   addLink(g, FLORENCE, ROME, ROAD);
   addLink(g, FLORENCE, VENICE, ROAD);
   addLink(g, FRANKFURT, LEIPZIG, ROAD);
   addLink(g, FRANKFURT, NUREMBURG, ROAD);
   addLink(g, FRANKFURT, STRASBOURG, ROAD);
   addLink(g, GALATZ, KLAUSENBURG, ROAD);
   addLink(g, GENEVA, MARSEILLES, ROAD);
   addLink(g, GENEVA, PARIS, ROAD);
   addLink(g, GENEVA, STRASBOURG, ROAD);
   addLink(g, GENEVA, ZURICH, ROAD);
   addLink(g, GENOA, MARSEILLES, ROAD);
   addLink(g, GENOA, MILAN, ROAD);
   addLink(g, GENOA, VENICE, ROAD);
   addLink(g, GRANADA, MADRID, ROAD);
   addLink(g, HAMBURG, LEIPZIG, ROAD);
   addLink(g, KLAUSENBURG, SZEGED, ROAD);
   addLink(g, LEIPZIG, NUREMBURG, ROAD);
   addLink(g, LE_HAVRE, NANTES, ROAD);
   addLink(g, LE_HAVRE, PARIS, ROAD);
   addLink(g, LISBON, MADRID, ROAD);
   addLink(g, LISBON, SANTANDER, ROAD);
   addLink(g, LIVERPOOL, MANCHESTER, ROAD);
   addLink(g, LIVERPOOL, SWANSEA, ROAD);
   addLink(g, LONDON, MANCHESTER, ROAD);
   addLink(g, LONDON, PLYMOUTH, ROAD);
   addLink(g, LONDON, SWANSEA, ROAD);
   addLink(g, MADRID, SANTANDER, ROAD);
   addLink(g, MADRID, SARAGOSSA, ROAD);
   addLink(g, MARSEILLES, MILAN, ROAD);
   addLink(g, MARSEILLES, TOULOUSE, ROAD);
   addLink(g, MARSEILLES, ZURICH, ROAD);
   addLink(g, MILAN, MUNICH, ROAD);
   addLink(g, MILAN, VENICE, ROAD);
   addLink(g, MILAN, ZURICH, ROAD);
   addLink(g, MUNICH, NUREMBURG, ROAD);
   addLink(g, MUNICH, STRASBOURG, ROAD);
   addLink(g, MUNICH, VENICE, ROAD);
   addLink(g, MUNICH, VIENNA, ROAD);
   addLink(g, MUNICH, ZAGREB, ROAD);
   addLink(g, MUNICH, ZURICH, ROAD);
   addLink(g, NANTES, PARIS, ROAD);
   addLink(g, NAPLES, ROME, ROAD);
   addLink(g, NUREMBURG, PRAGUE, ROAD);
   addLink(g, NUREMBURG, STRASBOURG, ROAD);
   addLink(g, PARIS, STRASBOURG, ROAD);
   addLink(g, PRAGUE, VIENNA, ROAD);
   addLink(g, SALONICA, SOFIA, ROAD);
   addLink(g, SALONICA, VALONA, ROAD);
   addLink(g, SANTANDER, SARAGOSSA, ROAD);
   addLink(g, SARAGOSSA, TOULOUSE, ROAD);
   addLink(g, SARAJEVO, SOFIA, ROAD);
   addLink(g, SARAJEVO, ST_JOSEPH_AND_ST_MARYS, ROAD);
   addLink(g, SARAJEVO, VALONA, ROAD);
   addLink(g, SARAJEVO, ZAGREB, ROAD);
   addLink(g, SOFIA, VALONA, ROAD);
   addLink(g, SOFIA, VARNA, ROAD);
   addLink(g, STRASBOURG, ZURICH, ROAD);
   addLink(g, ST_JOSEPH_AND_ST_MARYS, SZEGED, ROAD);
   addLink(g, ST_JOSEPH_AND_ST_MARYS, ZAGREB, ROAD);
   addLink(g, SZEGED, ZAGREB, ROAD);
   addLink(g, VIENNA, ZAGREB, ROAD);


   //### BOAT Connections ###

   addLink(g, ADRIATIC_SEA, BARI, BOAT);
   addLink(g, ADRIATIC_SEA, IONIAN_SEA, BOAT);
   addLink(g, ADRIATIC_SEA, VENICE, BOAT);
   addLink(g, ALICANTE, MEDITERRANEAN_SEA, BOAT);
   addLink(g, AMSTERDAM, NORTH_SEA, BOAT);
   addLink(g, ATHENS, IONIAN_SEA, BOAT);
   addLink(g, ATLANTIC_OCEAN, BAY_OF_BISCAY, BOAT);
   addLink(g, ATLANTIC_OCEAN, CADIZ, BOAT);
   addLink(g, ATLANTIC_OCEAN, ENGLISH_CHANNEL, BOAT);
   addLink(g, ATLANTIC_OCEAN, GALWAY, BOAT);
   addLink(g, ATLANTIC_OCEAN, IRISH_SEA, BOAT);
   addLink(g, ATLANTIC_OCEAN, LISBON, BOAT);
   addLink(g, ATLANTIC_OCEAN, MEDITERRANEAN_SEA, BOAT);
   addLink(g, ATLANTIC_OCEAN, NORTH_SEA, BOAT);
   addLink(g, BARCELONA, MEDITERRANEAN_SEA, BOAT);
   addLink(g, BAY_OF_BISCAY, BORDEAUX, BOAT);
   addLink(g, BAY_OF_BISCAY, NANTES, BOAT);
   addLink(g, BAY_OF_BISCAY, SANTANDER, BOAT);
   addLink(g, BLACK_SEA, CONSTANTA, BOAT);
   addLink(g, BLACK_SEA, IONIAN_SEA, BOAT);
   addLink(g, BLACK_SEA, VARNA, BOAT);
   addLink(g, CAGLIARI, MEDITERRANEAN_SEA, BOAT);
   addLink(g, CAGLIARI, TYRRHENIAN_SEA, BOAT);
   addLink(g, DUBLIN, IRISH_SEA, BOAT);
   addLink(g, EDINBURGH, NORTH_SEA, BOAT);
   addLink(g, ENGLISH_CHANNEL, LE_HAVRE, BOAT);
   addLink(g, ENGLISH_CHANNEL, LONDON, BOAT);
   addLink(g, ENGLISH_CHANNEL, NORTH_SEA, BOAT);
   addLink(g, ENGLISH_CHANNEL, PLYMOUTH, BOAT);
   addLink(g, GENOA, TYRRHENIAN_SEA, BOAT);
   addLink(g, HAMBURG, NORTH_SEA, BOAT);
   addLink(g, IONIAN_SEA, SALONICA, BOAT);
   addLink(g, IONIAN_SEA, TYRRHENIAN_SEA, BOAT);
   addLink(g, IONIAN_SEA, VALONA, BOAT);
   addLink(g, IRISH_SEA, LIVERPOOL, BOAT);
   addLink(g, IRISH_SEA, SWANSEA, BOAT);
   addLink(g, MARSEILLES, MEDITERRANEAN_SEA, BOAT);
   addLink(g, MEDITERRANEAN_SEA, TYRRHENIAN_SEA, BOAT);
   addLink(g, NAPLES, TYRRHENIAN_SEA, BOAT);
   addLink(g, ROME, TYRRHENIAN_SEA, BOAT);
}

// returns a new datatype graph
GraphRep* newGraph (int x) {

	GraphRep* a = new GraphRep;
	assert (a!= NULL);

	a->nV = x;
	a->arr = new graphNode* [x];     // array of pointers (graphNode)
    assert (a->arr != NULL);

	for (int i=0; i<x; i++) {

		a->arr[i] = new graphNode;
        assert (a->arr[i] != NULL);
		a->arr[i]->location = i;    // location id
		a->arr[i]->mode = 0;        // mode is used when travelling (land, sea, train) initailly none
		a->arr[i]->next = NULL;     // pointer to next connected node (linked list)
	}
	return a;
}

//adds links to the graph
void addLink (GraphRep* a, LocationID from, LocationID to, TransportID x) {

	assert (a != NULL && validV(a,from) && validV(a,to));

    int q = sameEdge (a,from, to, x);   // checking if link is not repeated

    if (q == 1) {

        graphNode* f = new graphNode ;
        assert (f!= NULL);

    	f->location = to;
    	f->mode = x;
    	f->next = NULL;

    	if (a->arr[from]->next == NULL) {
    		a->arr[from]->next = f ;
    	}

    	else {
    		graphNode* y = a->arr[from]->next;
    		a->arr[from]->next = f;
    		a->arr[from]->next->next = y;
    	}
    }
    else {
        return ;
    }

    addLink (a,to,from,x);      // because it is undirected graph (symmetry)
}

// prints the graph
void printGraph (GraphRep* g) {
	graphNode* add;

	for (int i = 0; i < g->nV; i++) {
		add = g->arr[i];
		while (add != NULL) {
			cout << add->location << "," << add->mode << "  " ;
			add = add->next;
		}
		cout << endl;
	}
}

// check the validity of nodes provided for connecting
int validV (GraphRep* g, LocationID v) {
	return (g != NULL && v >= 0 && v < g->nV);
}

// prints the locations connected to location x
void printList (GraphRep* a, LocationID x) {

	graphNode* add = a->arr[x];

	while (add!= NULL) {
		cout << add->location << "," << add->mode << "  " ;
		add = add->next;
	}
	cout << endl;
}

// to avoid repetition of edges (same mode as well)
int sameEdge (GraphRep* a, LocationID from, LocationID to, TransportID x) {

    graphNode* add = a->arr[from];

    while (add != NULL) {
        if (add->location == to && add->mode == x) {
            return 0;
        }
        add = add->next;
    }
    return 1;
}

int minimumDistanceHunter (GraphRep* a, LocationID x, LocationID y) {

    List* list = newList() ;
    Pqueue* queue = newPqueue() ;

    cout << "x is " << x << endl;
    cout << "y is " << y << endl;

    cout << "location " << a->arr[x]->location << endl;
    cout << "mode " << a->arr[x]->mode << endl;

	pushPqueue(queue, a->arr[x]->location, 0, a->arr[x]->mode, -1);
    cout << "ok mid\n";

    graphNode* add = a->arr[x]->next;
    cout << "ok mid\n";

    int p = 0;
    PqueueNode* w;
    cout << "ok mid\n";

    int count = 0;
    cout << "ok mid\n";

    while (count != a->nV) {

        cout << "entering loop minimumDistanceHunter\n";

        while (add != NULL) {

            if (checkPqueue(queue,add->location, add->mode) == 0 && checkList (list, add->location, add->mode) == 0) {
                pushPqueue(queue, add->location, p+1 ,add->mode,-1);
                //cout << "pushed " ;
            }
            add = add->next;
        }

        w = popPqueue(queue);

        if (w->val == y) {
			break;
		}
        //printPqueue(queue);
        add = a->arr[w->val]->next;
        p = w->priority;

        pushList(list, w->val, w->priority, w->mode, -1);
        count++;
    }
    cout << "ok done\n";

    return w->priority;
}

// returns the stack with shortest path from location x to location loc (shortest for hunter)
Stack* shortestPathHunter (GraphRep* a, LocationID x, LocationID loc) {

    List* list = newList() ;
    Pqueue* queue = newPqueue() ;

	pushPqueue(queue, a->arr[x]->location, 0, a->arr[x]->mode, -1);

    graphNode* add = a->arr[x]->next;

    int p = 0;
    PqueueNode* w;
	int prev = x;

    int count = 0;

    while (count <= 70) {

        while (add != NULL) {

            if (checkPqueue(queue,add->location, add->mode) == 0 && checkList (list, add->location, add->mode) == 0) {
                pushPqueue(queue, add->location, p+1 ,add->mode, prev);
            }
            add = add->next;
        }

        w = popPqueue(queue);

		if (w->val == loc) {
			break;
		}

		pushList(list, w->val, w->priority, w->mode, w->prev);

        add = a->arr[w->val]->next;
		prev = w->val;
        p = w->priority;
		count ++;
    }

	int y = w->prev;

	Stack* path = newStack();
	pushStack (path, loc);
	pushStack (path,y);

	while (y != x) {

		y = prevList(list,y);
		pushStack (path, y);
	}

    return path;
}

// returns the stack with shortest path from location x to location loc (shortest for dracula)
Stack* shortestPathDrac (GraphRep* a, LocationID x, LocationID loc) {

    List* list = newList() ;
    Pqueue* queue = newPqueue() ;

	pushPqueue(queue, a->arr[x]->location, 0, a->arr[x]->mode, -1);

    graphNode* add = a->arr[x]->next;

    int p = 0;
    PqueueNode* w;
	int prev = x;

    int count = 0;

    while (count <= 70) {

        while (add != NULL) {

			if (add->location != ST_JOSEPH_AND_ST_MARYS) {

				if (add->mode == ROAD) {

	            	if (checkPqueue(queue,add->location, add->mode) == 0 && checkList (list, add->location, add->mode) == 0) {
						pushPqueue(queue, add->location, p + 1,add->mode, prev);
	            	}
	            	add = add->next;
				}

				else if (add->mode == BOAT) {

					if (checkPqueue(queue,add->location, add->mode) == 0 && checkList (list, add->location, add->mode) == 0) {
						pushPqueue(queue, add->location, p + 2, add->mode, prev);
	            	}
	            	add = add->next;
				}

				else {
					add = add->next;
				}
        	}
			else {
				add = add->next;
			}
		}

    	w = popPqueue(queue);

		if (w->val == loc) {
			break;
		}

		pushList(list, w->val, w->priority, w->mode, w->prev);

        add = a->arr[w->val]->next;
		prev = w->val;
        p = w->priority;

		count ++;
    }

	int y = w->prev;

	Stack* path = newStack();
	pushStack (path, loc);
	pushStack (path,y);

	while (y != x) {
		y = prevList(list,y);
		pushStack (path, y);
	}

    return path;
}

// returns the distance from location x to location loc (shortest distance for dracula)
int shortestDistanceDrac (GraphRep* a, LocationID x, LocationID loc) {

    Stack* path = shortestPathDrac (a, x, loc);

    StackNode* add = path->start;
    int c = 0;

    while (add != NULL) {
        // if (getPlaceType(add->val) == SEA) {
        //     *s = *s + 2;
        // }
        c ++;
        add = add->next;
    }
    return c;
}

// dracula health lost because of encounter with hunter
void bloodLossHunter (int* health) {
    health[PLAYER_DRACULA] = health[PLAYER_DRACULA] - LIFE_LOSS_HUNTER_ENCOUNTER;
}

// dracula health loss going to sea
void bloodLossSea (int* health) {
    health[PLAYER_DRACULA] = health[PLAYER_DRACULA] - LIFE_LOSS_SEA;
}

//health gain of dracula at castle dracula
void bloodGainCastle (int* health) {
    health[PLAYER_DRACULA] = health[PLAYER_DRACULA] + LIFE_GAIN_CASTLE_DRACULA;
}

// hunter health lost because of trap
void lifeLossTrap (PlayerID x, int* health) {
    health[x] = health[x] - LIFE_LOSS_TRAP_ENCOUNTER;
}

// hunter health lost because of encounter with dracula
void lifeLossDrac (PlayerID x, int* health) {
    health[x] = health[x] - LIFE_LOSS_DRACULA_ENCOUNTER;
}

// hunter health gain by rest
void lifeGainRest (PlayerID x,int* health) {
    health[x] = health[x] + LIFE_GAIN_REST;
}
