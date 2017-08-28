#include <iostream>
#include "gameView.h"

using namespace std;

typedef struct dracView* Dracview ;

struct dracView {

    Gameview gameView;
    encounter
};

DracView newDracView(char *pastPlays) {
    DracView view = new dracView;
    assert (view != NULL);
    view->gameView = newGameView (pastPlays);

}

void disposeDracView(DracView toBeDeleted) {
    assert (toBeDeleted != NULL);
    delete toBeDeleted;
}

Round giveMeTheRound(DracView currentView) {
    assert (currentView != NULL);
    return currentView->round;
}

int giveMeTheScore(DracView currentView) {
    assert (currentView != NULL);
    return currentView->score;
}

int howHealthyIs(DracView currentView, PlayerID player) {
    assert (currentView != NULL);
    return currentView->health[PlayerID];
}

LocationID whereIs(DracView currentView, PlayerID player) {
    assert (currentView != NULL);
    return currentView->hunters[player];
}

void lastMove(DracView currentView, PlayerID player, LocationID *start, LocationID *end);

void whatsThere(DracView currentView, LocationID where, int *numTraps, int *numVamps);

void giveMeTheTrail(DracView currentView, PlayerID player, LocationID trail[TRAIL_SIZE]);

LocationID *whereCanIgo(DracView currentView, int *numLocations, int road, int sea);

LocationID *whereCanTheyGo(DracView currentView, int *numLocations, PlayerID player, int road,
                                int rail, int sea);
