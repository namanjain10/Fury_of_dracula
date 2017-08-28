//#include "game.h"
#include "GameView.h"
#include <assert.h>
#include "map.h"
#include "trail.h"
#include "places.h"
#include <string.h>
#include <iostream>
using namespace std;

// struct gameView {
//
//     GraphRep* map;
//     Round round;
//     int score;
//     int* health;
//     LocationID location[NUM_PLAYERS];
//     PlayerID current;
//     Trail** huntTrail;
// };

GameView newGameView(char *pastPlays) {

    GameView a = new gameView;
    GraphRep* m = newGraph(71);
    a->map = m;
    constMap(m);

    Place* places = getPlaces();

    int i = 0;
    int chance = 0;

    a->round = 0;
    a->score = GAME_START_SCORE;

    a->health = init_health();

    int n = strlen(pastPlays);
    int r = n/8;

    a->huntTrail = new Trail* [NUM_PLAYERS];
    cout << NUM_PLAYERS << "\n";

    for (int k=0; k<NUM_PLAYERS; k++) {
        a->huntTrail[k] = newTrail();
        cout << "here \n";

        for (int j = 0; j<6; j++) {
            pushToTrail(a->huntTrail[k], UNKNOWN_LOCATION);
        }
    }

    a->location = init_location();
    //cout << "here0 \n";

    while (chance != r) {
        //cout << i << endl;
        if (i%8 == 0) {
            //cout << "here1 \n";
            cout << i << endl;
            if (pastPlays[i] == 'G') {a->current = PLAYER_LORD_GODALMING; }
            else if (pastPlays[i] == 'S') {a->current = PLAYER_DR_SEWARD; }
            else if (pastPlays[i] == 'H') {a->current = PLAYER_VAN_HELSING; }
            else if (pastPlays[i] == 'M') {a->current = PLAYER_MINA_HARKER; }
            else if (pastPlays[i] == 'D') {
                a->current = PLAYER_DRACULA ;
                a->round = a->round + 1;
            }
            cout << a->current << endl;
            i++ ;
        }

        else if (i%8 == 1){
            //cout << "here2 \n";
            //cout << i << endl;
            string c = "";
            c += pastPlays[i] ;
            c += pastPlays[i+1] ;

            for (int k=0; k<71; k++) {
                if (places[k].abbrev == c) {
                    pushToTrail(a->huntTrail[a->current], places[k].id);
                    a->location[a->current] = places[k].id;
                }
            }
            i += 2;
        }

        else if (i%8 == 3) {
            if (pastPlays[i] == 'T') {
                if (a->current != PLAYER_DRACULA) {
                    lifeLossTrap (a->current, a->health);
                }
                else if (a->current == PLAYER_DRACULA) {

                }
            }
        }

        else if (i%8 == 4) {
            if (pastPlays[i] == 'V') {
                if (a->current != PLAYER_DRACULA) {

                }
                else if (a->current == PLAYER_DRACULA) {

                }
            }
        }

        else if (i%8 == 5) {
            if (pastPlays[i] == 'D') {
                if (a->current != PLAYER_DRACULA) {
                    lifeLossDrac (a->current, a->health);
                }
                else if (a->current == PLAYER_DRACULA) {

                }
            }
        }

        else {
            
            if (i%8 == 7) {
                chance++;
            }
            i++;
        }
    }
    return a;
}

//
// char pastPlays[] = "GMN.... SPL.... HAM.... MPA.... DC?.V.. GLV.... SLO.... HNS.... MST.... DC?T... GIR.... SPL.... HAO.... MZU.... DCDT... GSW.... SLO.... HNS.... MFR.... DC?T... GLV.... SPL.... HAO.... MZU.... DC?T... GSW.... SLO.... HNS.... " ;

void disposeGameView(GameView toBeDeleted) {
    assert (toBeDeleted != NULL);
    delete toBeDeleted;
}

Round getRound(GameView currentView) {
    assert (currentView != NULL);
    return currentView->round;
}

PlayerID getCurrentPlayer(GameView currentView) {
    assert (currentView != NULL);
    return currentView->current;
}

int getScore(GameView currentView) {
    assert (currentView != NULL);
    return currentView->score;
}

int getHealth(GameView currentView, PlayerID player) {
    assert (currentView != NULL);
    return currentView->health[player];
}

LocationID getLocation(GameView currentView, PlayerID player) {
    assert (currentView != NULL);
    return currentView->hunters[player];
}


void getHistory(GameView currentView, PlayerID player, LocationID trail[TRAIL_SIZE]);


LocationID *connectedLocations(GameView currentView, int *numLocations, LocationID from,
                                PlayerID player, Round round, int road, int rail, int sea);
