#include <iostream>
#include "gameView.h"

using namespace std;

typedef struct dracView* Dracview ;

struct dracView {
    Gameview gameView;
};

DracView newDracView(char *pastPlays) {
    DracView view = new dracView;
    assert (view != NULL);
    view->gameView = newGameView (pastPlays);
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

void lastMove(DracView currentView, PlayerID player, LocationID *start, LocationID *end) {

}

void whatsThere(DracView currentView, LocationID where, int *numTraps, int *numVamps) {

}

void giveMeTheTrail(DracView currentView, PlayerID player, LocationID trail[TRAIL_SIZE]) {

}

LocationID *whereCanIgo(DracView currentView, int *numLocations, int road, int sea) {

}

LocationID *whereCanTheyGo(DracView currentView, int *numLocations, PlayerID player, int road, int rail, int sea) {

}
