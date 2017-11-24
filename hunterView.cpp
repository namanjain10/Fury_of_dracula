#include "gameView.h"
#include "hunterView.h"
#include <assert.h>

typedef struct hunterView* HunterView;

struct hunterView {
    GameView view;
};

// newHunterView() creates a new game view to summarise the current state of the game.
HunterView newHunterView(char *pastPlays, PlayerMessage messages[]) {

    HunterView view = new hunterView;
    assert (view != NULL);
    view->view = newGameView (pastPlays, messages);
    return view;
}

// disposeHunterView() frees all memory previously allocated for the HunterView toBeDeleted. toBeDeleted should not be accessed after the call.
void disposeHunterView(HunterView toBeDeleted) {
    assert (toBeDeleted != NULL);
    delete toBeDeleted;
}

// Get the current round
Round giveMeTheRound(HunterView currentView) {
    assert (currentView != NULL);
    return getRound(currentView->view);
}

// Get the id of current player - ie whose turn is it?
PlayerID whoAmI(HunterView currentView) {
    assert (currentView != NULL);
    return getCurrentPlayer(currentView->view);
}

// Get the current score
int giveMeTheScore(HunterView currentView) {
    assert (currentView != NULL);
    return getScore(currentView->view);
}

// Get the current health points for a given player
int howHealthyIs(HunterView currentView, PlayerID player) {
    assert (currentView != NULL);
    return getHealth(currentView->view, player);
}

// Get the current location id of a given player
LocationID whereIs(HunterView currentView, PlayerID player) {
    assert (currentView != NULL);
    return getLocation(currentView->view,player);
}

// Fills the trail array with the location ids of the last 6 turns for the given player, including Dracula (if he asks about his own trail)
void giveMeTheTrail(HunterView currentView, PlayerID player,
                        LocationID trail[TRAIL_SIZE]) {
    getHistory(currentView->view, player, trail);
}

// whereCanIgo() returns an array of LocationIDs giving all locations that the current player could reach in his next move
LocationID *whereCanIgo(HunterView currentView, int *numLocations, int road, int rail, int sea) {
    return connectedLocations (currentView->view, numLocations, whereIs(currentView, whoAmI(currentView)), whoAmI(currentView), road, road, rail, sea);
}

// whereCanTheyGo() returns an array of LocationIDs giving all of the locations that the given Player could reach from their current location
LocationID *whereCanTheyGo(HunterView currentView, int *numLocations, PlayerID player, int road, int rail, int sea){
    return connectedLocations (currentView->view, numLocations, whereIs(currentView, player), player, road, road, rail, sea);
}
