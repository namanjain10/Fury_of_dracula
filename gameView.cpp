//#include "game.h"
#include "gameView.h"
//#include "gameController.h"
#include <assert.h>
//#include "map.h"
//#include "trail.h"
#include "places.h"
#include <string.h>
#include <iostream>
using namespace std;

// struct gameView {
//
//     GraphRep* map;
// Round round;
// int score;
// int health[NUM_PLAYERS];
// LocationID location[NUM_PLAYERS];
// PlayerID current;
// Trail** huntTrail;
// };
PlaceType getPlaceTypeDoubleBack (Queue* a, int db);

GameView newGameView(char* pastPlays, PlayerMessage messages[]) {

    GameView a = new gameView;
    GraphRep* m = newGraph(NUM_MAP_LOCATIONS);
    a->map = m;
    constMap(m);

    a->round = 0;
    a->score = GAME_START_SCORE;
    a->health[PLAYER_DRACULA] = GAME_START_BLOOD_POINTS;
    a->location[PLAYER_DRACULA] = NOWHERE;

    a->current = PLAYER_LORD_GODALMING;

    for (int i = 0; i<NUM_PLAYERS-1; i++) {

        a->health[i] = GAME_START_HUNTER_LIFE_POINTS;
        a->location[i] = NOWHERE;
        //a->hide[i] = 0;
     }

    a->huntTrail = new Queue*[NUM_PLAYERS];
    a->trap = new Queue;

    for (int i = 0; i<NUM_PLAYERS; i++) {
        a->huntTrail[i] = newQueue (TRAIL_SIZE);

        for (int j = 0; j<TRAIL_SIZE; j++) {
            pushQueue (a->huntTrail[i], NOWHERE, -1);
        }
    }

    for (int i = 0; i<TRAIL_SIZE; i++) {
        pushQueue(a->trap, NO_ENCOUNTER, -1);
    }

    int i = 0;
    int chance = 0;
    //PlayerID a->current = 0;
    int n = strlen(pastPlays);
    int r = n/8;

    while (chance != r) {

        //cout << "current player " << a->current << '\n';
        if (i%8 == 0) {

            if (pastPlays[i] == 'G') {
                a->current = PLAYER_LORD_GODALMING;
                a->round = a->round + 1;
            }

            else if (pastPlays[i] == 'S') {a->current = PLAYER_DR_SEWARD; }
            else if (pastPlays[i] == 'H') {a->current = PLAYER_VAN_HELSING; }
            else if (pastPlays[i] == 'M') {a->current = PLAYER_MINA_HARKER; }
            else if (pastPlays[i] == 'D') {a->current = PLAYER_DRACULA ;
                a->score = a->score - SCORE_LOSS_DRACULA_TURN;
            }
            i++ ;
        }

        else if (i%8 == 1){

            char* c = new char [2];
            c[0] = pastPlays[i] ;
            c[1] = pastPlays[i+1] ;

            //cout << c << endl;

            if (a->current == PLAYER_DRACULA) {

                if (strcmp("S?",c) == 0) {
                    a->location[PLAYER_DRACULA] = SEA_UNKNOWN;
                    pushQueue(a->huntTrail[PLAYER_DRACULA], SEA_UNKNOWN, SEA);
                    bloodLossSea (a->health);
                }

                else if (strcmp("C?",c) == 0) {
                    a->location[PLAYER_DRACULA] = CITY_UNKNOWN;
                    pushQueue(a->huntTrail[PLAYER_DRACULA], CITY_UNKNOWN, LAND);
                }

                else if (strcmp("HI",c) == 0) {
                    a->location[PLAYER_DRACULA] = HIDE;
                    pushQueue(a->huntTrail[PLAYER_DRACULA], HIDE, UNKNOWN);
                }

                else if (strcmp("D1",c) == 0) {
                    a->location[PLAYER_DRACULA] = DOUBLE_BACK_1;
                    PlaceType p = getPlaceTypeDoubleBack (a->huntTrail[PLAYER_DRACULA], 1);

                    if (p == SEA) {
                        bloodLossSea (a->health);
                    }
                    pushQueue(a->huntTrail[PLAYER_DRACULA], DOUBLE_BACK_1, p);
                }
                else if (strcmp("D2",c) == 0) {
                    a->location[PLAYER_DRACULA] = DOUBLE_BACK_2;
                    PlaceType p = getPlaceTypeDoubleBack (a->huntTrail[PLAYER_DRACULA], 2);

                    if (p == SEA) {
                        bloodLossSea (a->health);
                    }
                    pushQueue(a->huntTrail[PLAYER_DRACULA], DOUBLE_BACK_2, p);
                }
                else if (strcmp("D3",c) == 0) {
                    a->location[PLAYER_DRACULA] = DOUBLE_BACK_3;
                    PlaceType p = getPlaceTypeDoubleBack (a->huntTrail[PLAYER_DRACULA], 3);

                    if (p == SEA) {
                        bloodLossSea (a->health);
                    }
                    pushQueue(a->huntTrail[PLAYER_DRACULA], DOUBLE_BACK_3, p);
                }
                else if (strcmp("D4",c) == 0) {
                    a->location[PLAYER_DRACULA] = DOUBLE_BACK_4;
                    PlaceType p = getPlaceTypeDoubleBack (a->huntTrail[PLAYER_DRACULA], 4);

                    if (p == SEA) {
                        bloodLossSea (a->health);
                    }
                    pushQueue(a->huntTrail[PLAYER_DRACULA], DOUBLE_BACK_4, p);
                }
                else if (strcmp("D5",c) == 0) {
                    a->location[PLAYER_DRACULA] = DOUBLE_BACK_5;
                    PlaceType p = getPlaceTypeDoubleBack (a->huntTrail[PLAYER_DRACULA], 5);

                    if (p == SEA) {
                        bloodLossSea (a->health);
                    }
                    pushQueue(a->huntTrail[PLAYER_DRACULA], DOUBLE_BACK_5, p);
                }

                else if (strcmp("TP",c) == 0) {
                    a->location[PLAYER_DRACULA] = TELEPORT;
                    pushQueue(a->huntTrail[PLAYER_DRACULA], TELEPORT, LAND);
                    bloodGainCastle (a->health);
                }

                else if (strcmp("CD",c) == 0) {
                    a->location[PLAYER_DRACULA] =  CASTLE_DRACULA;
                    pushQueue(a->huntTrail[PLAYER_DRACULA], CASTLE_DRACULA, LAND);
                    bloodGainCastle (a->health);
                }

                else {

                    for (int k=0; k<NUM_MAP_LOCATIONS; k++) {

                        if (strcmp(getAbbrev(k),c) == 0) {
                            //cout << "entered\n";
                            a->location[a->current] = k;
                            pushQueue (a->huntTrail[a->current], k, getPlaceType(k));

                            if (getPlaceType (k) == SEA) {
                                bloodLossSea (a->health);
                            }
                            break;
                        }
                    }
                }
            }

            else {
                for (int k=0; k<NUM_MAP_LOCATIONS; k++) {

                    if (strcmp(getAbbrev(k),c) == 0) {
                        //cout << "entered\n";
                        if (k == a->location[a->current]) {
                            lifeGainRest (a->current, a->health);
                        }

                        a->location[a->current] = k;
                        pushQueue (a->huntTrail[a->current], k, getPlaceType(k));
                        break;
                    }
                }
            }
            i += 2;
        }

        else if (i%8 == 3) {
            //cout << "ok " << pastPlays[i] << '\n';
            if (pastPlays[i] == 'T') {
                if (a->current != PLAYER_DRACULA) {
                    lifeLossTrap (a->current, a->health);
                    if (a->health[a->current] <= 0) {
                        a->location[a->current] = ST_JOSEPH_AND_ST_MARYS;
                        a->score = a->score - SCORE_LOSS_HUNTER_HOSPITAL;
                        a->health[a->current] = GAME_START_HUNTER_LIFE_POINTS;
                    }
                }

                else if (a->current == PLAYER_DRACULA) {
                    pushQueue(a->trap,TRAP,-1);
                }
            }

            else if (pastPlays[i] == 'D') {

                if (a->current != PLAYER_DRACULA) {
                    //cout << "executed " << a->current << endl;
                    lifeLossDrac (a->current, a->health);
                    bloodLossHunter (a->health);

                    if (a->health[a->current] <= 0) {
                        a->location[a->current] = ST_JOSEPH_AND_ST_MARYS;
                        a->score = a->score - SCORE_LOSS_HUNTER_HOSPITAL;
                        a->health[a->current] = GAME_START_HUNTER_LIFE_POINTS;
                    }
                }
            }

            i++;
        }

        else if (i%8 == 4) {
            if (pastPlays[i] == 'V') {
                if (a->current != PLAYER_DRACULA) {
                    popQueue (a->trap);
                }

                else if (a->current == PLAYER_DRACULA) {
                    pushQueue (a->trap,VAMPIRE,-1);
                }
            }
            else if (pastPlays[i] == 'D') {

                if (a->current != PLAYER_DRACULA) {
                    //cout << "executed " << a->current << endl;
                    lifeLossDrac (a->current, a->health);
                    bloodLossHunter (a->health);

                    if (a->health[a->current] <= 0) {
                        a->location[a->current] = ST_JOSEPH_AND_ST_MARYS;
                        a->score = a->score - SCORE_LOSS_HUNTER_HOSPITAL;
                        a->health[a->current] = GAME_START_HUNTER_LIFE_POINTS;
                    }
                }
            }
            i++;
        }

        else if (i%8 == 5) {

            if (pastPlays[i] == 'D') {

                if (a->current != PLAYER_DRACULA) {
                    cout << "executed " << a->current << endl;
                    lifeLossDrac (a->current, a->health);
                    bloodLossHunter (a->health);

                    if (a->health[a->current] <= 0) {
                        a->location[a->current] = ST_JOSEPH_AND_ST_MARYS;
                        a->score = a->score - SCORE_LOSS_HUNTER_HOSPITAL;
                        a->health[a->current] = GAME_START_HUNTER_LIFE_POINTS;
                    }
                }
            }

            else if (pastPlays[i] == 'M') {
                popQueue (a->trap);
            }

            else if (pastPlays[i] == 'V') {
                popQueue (a->trap);
                a->score = a->score - SCORE_LOSS_VAMPIRE_MATURES;
            }
            i++;
        }

        else {
            if (i%8 == 7) {
                if (a->current == PLAYER_DRACULA) {
                    a->current = PLAYER_LORD_GODALMING;
                }
                else {
                    a->current = a->current+1;
                }
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
    return currentView->location[player];
}

void getHistory(GameView currentView, PlayerID player, LocationID trail[TRAIL_SIZE]) {

    QueueNode* add = currentView->huntTrail[player]->start;
    int i = TRAIL_SIZE - 1;

    while (add != NULL) {

        trail[i] = add->val;
        add = add->next;
        i -- ;
    }
}

LocationID *connectedLocations(GameView currentView, int *numLocations, LocationID from, PlayerID player, Round round1, int road, int rail, int sea) {

    graphNode* add = currentView->map->arr[from];
    Stack* a = newStack();
    *numLocations = 0;
    int steps = (round1 + player)%4;

    pushStack (a,from);
    graphNode* b;
    graphNode* c;

    while (add != NULL) {
        if (road == TRUE) {
            if (add->mode == ROAD) {
                pushStack (a,add->location);
            }
        }

        if (sea == TRUE) {
            if (add->mode == BOAT) {
                pushStack (a,add->location);
            }
        }

        if (rail == TRUE) {
            if ( add->mode == RAIL) {
                if (player != PLAYER_DRACULA) {

                    if (steps == 1) {
                        pushStack (a,add->location);
                    }

                    else if (steps > 1) {
                        Stack* stack1 = newStack();

                        b = currentView->map->arr[add->location];
                        pushStack (stack1, add->location);

                        if (steps == 2) {
                            while (b != NULL) {
                                if (b->mode == RAIL) {

                                    if (notInStack(stack1,b->location) == 1) {
                                        if (notInStack(a,b->location)) {
                                            pushStack (a,b->location);
                                        }
                                    }
                                }
                                b = b->next;
                            }
                        }

                        else {
                            while (b != NULL) {
                                if (b->mode == RAIL) {
                                    if (notInStack(stack1, b->location) == 1) {
                                        if (notInStack(a, b->location) == 1) {
                                            pushStack(stack1, b->location);

                                            c = currentView->map->arr[b->location] ;

                                            while (c != NULL) {

                                                if (c->mode == RAIL) {
                                                    if (notInStack(stack1, c->location)) {
                                                        if (notInStack(a, c->location)) {
                                                            pushStack (a, c->location);
                                                        }
                                                    }
                                                }
                                                    c = c->next;
                                            }
                                        }
                                    }
                                }
                                    b = b->next;
                        }
                        }
                        delete stack1;
                    }
                }
            }
        }
        add = add->next;
    }

    StackNode* s = a->start;
    //numLocations = new int;

    while (s != NULL) {
        *numLocations = *numLocations+1;
        s = s->next;
    }

    LocationID* loc = new LocationID[*numLocations];
    s = a->start;
    int i = 0;

    while (s != NULL) {
        loc[i] = s->val;
        s = s->next;
        i++;
    }
    delete a;

    return loc;
}

PlaceType getPlaceTypeDoubleBack (Queue* a, int db) {

    QueueNode* add = a->start;
    int count = TRAIL_SIZE ;

    while (count != db) {
        add = add->next;
        count --;
    }
    return add->place;
}
