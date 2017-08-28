#include "gameView.h"

typedef struct hunterView *HunterView;

struct hunterView {

    Gameview gameView;
};

HunterView newHunterView(char *pastPlays) {

    HunterView view = new hunterView;
    assert (view != NULL);
    view->gameView = newGameView (pastPlays);

    return view;
}

void disposeHunterView(HunterView toBeDeleted) {
    assert (toBeDeleted != NULL);
    delete toBeDeleted;
}

Round giveMeTheRound(HunterView currentView) {
    assert (currentView != NULL);
    return currentView->round;
}

PlayerID whoAmI(HunterView currentView) {
    assert (currentView != NULL);
    return currentView->current;
}

int giveMeTheScore(HunterView currentView) {
    assert (currentView != NULL);
    return currentView->score;
}

int howHealthyIs(HunterView currentView, PlayerID player) {
    assert (currentView != NULL);
    return currentView->health[PlayerID];
}

LocationID whereIs(HunterView currentView, PlayerID player) {
    assert (currentView != NULL);
    return currentView->hunters[player];
}

void giveMeTheTrail(HunterView currentView, PlayerID player,
                        LocationID trail[TRAIL_SIZE]);

LocationID *whereCanIgo(HunterView currentView, int *numLocations,
                        int road, int rail, int sea);

LocationID *whereCanTheyGo(HunterView currentView, int *numLocations,
                           PlayerID player, int road, int rail, int sea);
