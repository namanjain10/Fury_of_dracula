#include "gameView.h"
#include "hunterView.h"
#include <assert.h>

typedef struct hunterView* HunterView;

struct hunterView {
    GameView view;
};

HunterView newHunterView(char *pastPlays, PlayerMessage messages[]) {

    HunterView view = new hunterView;
    assert (view != NULL);
    view->view = newGameView (pastPlays, messages);
    return view;
}

void disposeHunterView(HunterView toBeDeleted) {
    assert (toBeDeleted != NULL);
    delete toBeDeleted;
}

Round giveMeTheRound(HunterView currentView) {
    assert (currentView != NULL);
    return getRound(currentView->view);
}

PlayerID whoAmI(HunterView currentView) {
    assert (currentView != NULL);
    return getCurrentPlayer(currentView->view);
}

int giveMeTheScore(HunterView currentView) {
    assert (currentView != NULL);
    return getScore(currentView->view);
}

int howHealthyIs(HunterView currentView, PlayerID player) {
    assert (currentView != NULL);
    return getHealth(currentView->view, player);
}

LocationID whereIs(HunterView currentView, PlayerID player) {
    assert (currentView != NULL);
    return getLocation(currentView->view,player);
}

void giveMeTheTrail(HunterView currentView, PlayerID player,
                        LocationID trail[TRAIL_SIZE]) {
    getHistory(currentView->view, player, trail);
}

LocationID *whereCanIgo(HunterView currentView, int *numLocations, int road, int rail, int sea) {
    return connectedLocations (currentView->view, numLocations, whereIs(currentView, whoAmI(currentView)), whoAmI(currentView), road, road, rail, sea);
}

LocationID *whereCanTheyGo(HunterView currentView, int *numLocations, PlayerID player, int road, int rail, int sea) {
    return connectedLocations (currentView->view, numLocations, whereIs(currentView, player), player, road, road, rail, sea);
}
