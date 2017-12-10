#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include "gameView.h"
#include "DracView.h"
#include "places.h"
#include <ctime>

using namespace std;

typedef struct dracView* DracView ;
//typedef struct gameView* GameView;

struct dracView {
    GameView view;
};

// newDracView() creates a new game view to summarise the current state of the game.
DracView newDracView(string pastPlays, PlayerMessage messages[]) {
    DracView view = new dracView;
    assert (view != NULL);
    view->view = newGameView (pastPlays, messages);
    return view;
}

// disposeDracView() frees all memory previously allocated for the DracView toBeDeleted. toBeDeleted should not be accessed after the call.
void disposeDracView(DracView toBeDeleted) {
    assert (toBeDeleted != NULL);
    delete toBeDeleted;
}

// Get the current round
Round giveMeTheRound(DracView currentView) {
    assert (currentView != NULL);
    return getRound(currentView->view);
}

// Get the current score
int giveMeTheScore(DracView currentView) {
    assert (currentView != NULL);
    return getScore(currentView->view);
}

// Get the current health points for a given player
int howHealthyIs(DracView currentView, PlayerID player) {
    assert (currentView != NULL);
    return getHealth(currentView->view, player);
}

// Get the current location id of a given player
LocationID whereIs(DracView currentView, PlayerID player) {
    assert (currentView != NULL);
    return getLocation(currentView->view,player);
}

// void lastMove(DracView currentView, PlayerID player, LocationID *start, LocationID *end) {
//
// }

// Find out what minions I (Dracula) has placed at the specified location minions are traps and immature vampires)
void whatsThere(DracView currentView, LocationID where, int *numTraps, int *numVamps) {
    QueueNode* add = getTrailElement (currentView->view, where);

    if (add == NULL) {
        *numTraps = -1;
        *numVamps = -1;
    }

    else {
        *numTraps = add->nT;
        *numVamps = add->nV;
    }
}

void giveMeTheTrail(DracView currentView, PlayerID player, LocationID trail[TRAIL_SIZE]) {
    getHistory(currentView->view, player, trail);
}

// whereCanIgo() returns an array of LocationIDs giving all locations that Dracula could reach in his next move
LocationID *whereCanIgo(DracView currentView, int *numLocations, int road, int sea) {
    return connectedLocations(currentView->view, numLocations, getLocation(currentView->view, PLAYER_DRACULA), PLAYER_DRACULA, 0, road, 0, sea);
}

// whereCanTheyGo() returns an array of LocationIDs giving all of the locations that the given Player could reach from their current location
LocationID *whereCanTheyGo(DracView currentView, int *numLocations, PlayerID player, int road, int rail, int sea) {
    return connectedLocations (currentView->view, numLocations, whereIs(currentView, player), player, road, road, rail, sea);
}

// returns the map
GraphRep* giveMeMap (DracView currentView) {
    return getMap(currentView->view);
}

int minDist (GraphRep* map, LocationID to, LocationID* hunterLoc) {

    LocationID dist[NUM_PLAYERS-1];

    for (int i=0; i<NUM_PLAYERS-1; i++) {
        dist[i] = minimumDistanceHunter (map, to, hunterLoc[i]);
    }

    int min = dist[0];

    for (int i=0; i<NUM_PLAYERS-1; i++) {
        if (min > dist[i]) {
            min = dist[i];
        }
    }
    return min;
}

LocationID initDrac () {

	srand((int)time(0));
    LocationID p = rand() % 70;
    while (getPlaceType(p) != LAND) {
        p = rand() % 70;
    }
    return p;
}
