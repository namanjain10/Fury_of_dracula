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
//     Trail* huntTrail;
//     int bloodPt;
// };

GameView newGameView(char *pastPlays) {

    GameView a = new gameView;
    GraphRep* m = newGraph(71);
    a->map = m;
    constMap(m);

    a->round = 0;
    a->score = GAME_START_SCORE;
    a->bloodPt = GAME_START_BLOOD_POINTS;

    for (int i = 0; i<NUM_PLAYERS-1; i++) {

        a->health[i] = GAME_START_HUNTER_LIFE_POINTS;
        a->location[i] = NOWHERE;
        //a->hide[i] = 0;
     }

    int n = pastPlays.length();
    int r = n/8;

    a->huntTrail = new Trail;

    for (int j = 0; j<6; j++) {
        push(a->huntTrail);
    }

    int i = 0;
    int chance = 0;

    while (chance != r) {

        if (i%8 == 0) {

            if (pastPlays[i] == 'G') {a->current = PLAYER_LORD_GODALMING; }
            else if (pastPlays[i] == 'S') {a->current = PLAYER_DR_SEWARD; }
            else if (pastPlays[i] == 'H') {a->current = PLAYER_VAN_HELSING; }
            else if (pastPlays[i] == 'M') {a->current = PLAYER_MINA_HARKER; }
            else if (pastPlays[i] == 'D') {
                a->current = PLAYER_DRACULA ;
                a->round = a->round + 1;
            }
            i++ ;
        }

        else if (i%8 == 1){
            //cout << "here2 \n";
            //cout << i << endl;
            char* c = new char [2];
            c[0] = pastPlays[i] ;
            c[1] = pastPlays[i+1] ;

            if (a->current == PLAYER_DRACULA) {

                if (strcmp("S?",c)) {

                }

                else if (strcmp("C?",c)) {

                }

                else {
                    for (int k=0; k<71; k++) {

                        if (getAbbrev(k) == c) {

                            a->location[a->current] = k;
                        }
                    }
                }
                i += 2;
            }
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


// void disposeGameView(GameView toBeDeleted) {
//     assert (toBeDeleted != NULL);
//     delete toBeDeleted;
// }
//
// Round getRound(GameView currentView) {
//     assert (currentView != NULL);
//     return currentView->round;
// }
//
// PlayerID getCurrentPlayer(GameView currentView) {
//     assert (currentView != NULL);
//     return currentView->current;
// }
//
// int getScore(GameView currentView) {
//     assert (currentView != NULL);
//     return currentView->score;
// }
//
// int getHealth(GameView currentView, PlayerID player) {
//     assert (currentView != NULL);
//     return currentView->health[player];
// }
//
// LocationID getLocation(GameView currentView, PlayerID player) {
//     assert (currentView != NULL);
//     return currentView->hunters[player];
// }
//
//
// void getHistory(GameView currentView, PlayerID player, LocationID trail[TRAIL_SIZE]);
//
//
// LocationID *connectedLocations(GameView currentView, int *numLocations, LocationID from,
//                                 PlayerID player, Round round, int road, int rail, int sea);
