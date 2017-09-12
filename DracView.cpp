#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include "gameView.h"
#include "DracView.h"
#include "places.h"

using namespace std;

typedef struct dracView* DracView ;
//typedef struct gameView* GameView;

struct dracView {
    GameView view;
};

DracView newDracView(string pastPlays, PlayerMessage messages[]) {
    DracView view = new dracView;
    assert (view != NULL);
    view->view = newGameView (pastPlays, messages);
    return view;
}

void disposeDracView(DracView toBeDeleted) {
    assert (toBeDeleted != NULL);
    delete toBeDeleted;
}

Round giveMeTheRound(DracView currentView) {
    assert (currentView != NULL);
    return getRound(currentView->view);
}

int giveMeTheScore(DracView currentView) {
    assert (currentView != NULL);
    return getScore(currentView->view);
}

int howHealthyIs(DracView currentView, PlayerID player) {
    assert (currentView != NULL);
    return getHealth(currentView->view, player);
}

LocationID whereIs(DracView currentView, PlayerID player) {
    assert (currentView != NULL);
    return getLocation(currentView->view,player);
}

// void lastMove(DracView currentView, PlayerID player, LocationID *start, LocationID *end) {
//
// }

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

LocationID *whereCanIgo(DracView currentView, int *numLocations, int road, int sea) {
    return connectedLocations(currentView->view, numLocations, getLocation(currentView->view, PLAYER_DRACULA), PLAYER_DRACULA, 0, road, 0, sea);
}

LocationID *whereCanTheyGo(DracView currentView, int *numLocations, PlayerID player, int road, int rail, int sea) {
    return connectedLocations (currentView->view, numLocations, whereIs(currentView, player), player, road, road, rail, sea);
}

GraphRep* giveMeMap (DracView currentView) {
    return getMap(currentView->view);
}

int minDist (GraphRep* map, LocationID to, LocationID* hunterLoc) {
    
    cout << "entered min dist\n";

    LocationID dist[NUM_PLAYERS-1];

    for (int i=0; i<NUM_PLAYERS-1; i++) {
        dist[i] = minimumDistanceHunter (map, to, hunterLoc[i]);
    }

    cout << "in mid\n";

    int min = dist[0];

    for (int i=0; i<NUM_PLAYERS-1; i++) {
        if (min > dist[i]) {
            min = dist[i];
        }
    }
    return min;
}

LocationID initDrac () {

    LocationID p = rand() % 70;
    while (getPlaceType(p) != LAND) {
        p = rand() % 70;
    }
    return p;
}
