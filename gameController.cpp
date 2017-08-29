#include <string.h>
#include "map.h"
#include "places.h"
#include "trail.h"
#include "Globals.h"
#include "gameController.h"
#include "gameData.h"

// struct gameData {
//
//     GraphRep* map ;
//
//     Trail* dracTrail;
//
//     int score ;
//     int round ;
//     int* health ;
//     int bloodPt ;
//     LocationID* location;
//     char* pastPlaysHunter;
//     char* pastplaysDrac;
// }

bool isValid (LocationID a, LocationID b, GraphRep* map);
int inTrail (Trail* a, LocationID loc);
char* getFirstLetter (PlayerID player);
void add (char* a, char* d);

gameData* newGameData () {

    gameData* a = new gameData;
    a->map = newGraph(71);
    constMap(a->map);

    //cout << "gvuvhb" << endl;

    a->round = 0;
    a->score = GAME_START_SCORE;
    a->bloodPt = GAME_START_BLOOD_POINTS;

    //cout << "gvuvhb" << endl;

    a->health = init_health ();
    a->location = init_location();

    a->dracTrail = newTrail();

    //cout << "gvuvhb" << endl;

    for (int j = 0; j<6; j++) {
        push(a->dracTrail);
        //cout << "gvuvhb" << endl;
    }

    a->pastPlaysHunter = "";
    a->pastPlaysDrac = "";
    //cout << "gvuvhb" << endl;
    return a;
}

void makeMove (PlayerID player, LocationID loc, Encounter trap, gameData* data) {

    Place* a = getPlaces ();
    cout << "gvuvhb" << endl;

    if (isValid (data->location[player], loc, data->map)) {  // to be made return boolean if move is valid
        cout << "gvuvhb" << endl;
        data->location[player] = loc;

        if (player != PLAYER_DRACULA) {

            int q = inTrail (data->dracTrail, loc);

            if (q == -1) {

                char* fir = getFirstLetter (player);
                char* r = getAbbrev (loc,a);

                // char* s = new char[8];
                // s[0] = fir;
                // strcat (s,r);
                // strcat (s,".... ");
                //
                // char* h = new char[strlen(data->pastPlaysHunter) + 8];
                // strcat (h,s);
                //
                // char* t = new char[strlen(data->pastPlaysDrac) + 8];
                // strcat (t,s);

                add (fir,data->pastPlaysHunter);
                add (fir,data->pastPlaysDrac);

                add (r,data->pastPlaysHunter);
                add (r,data->pastPlaysDrac);

                add(".... ", data->pastPlaysHunter);
                add(".... ", data->pastPlaysDrac);

            }

            else {
                // addTrap and change hunternpastPlay
            }
        }

        else {

            State* state = pushToTrail (data->dracTrail, loc, trap);

            if (state->hides == HIDE) {
                add("HI", data->pastPlaysHunter);
            }

            else if (state->hides == DOUBLE_BACK_1) {
                add("D1", data->pastPlaysHunter);
            }

            else if (state->hides == DOUBLE_BACK_2) {
                add("D2", data->pastPlaysHunter);
            }

            else if (state->hides == DOUBLE_BACK_3) {
                add("D3", data->pastPlaysHunter);
            }

            else if (state->hides == DOUBLE_BACK_4) {
                add("D4", data->pastPlaysHunter);
            }

            else if (state->hides == DOUBLE_BACK_5) {
                add("D5", data->pastPlaysHunter);
            }

            else {
                PlaceType pla = getPlaceType(loc,a);

                if (pla == LAND) {
                    add("C?", data->pastPlaysHunter);
                }

                else {
                    add ("S?", data->pastPlaysHunter);
                }
            }
            add(getAbbrev (loc,a) , data->pastPlaysDrac);

            if (trap == TRAP) {
                add("T", data->pastPlaysHunter);
                add("T", data->pastPlaysDrac);
            }

            else {
                add(".", data->pastPlaysHunter);
                add(".", data->pastPlaysDrac);
            }

            if (trap == VAMPIRE) {
                add("V", data->pastPlaysHunter);
                add("V", data->pastPlaysDrac);
            }

            else {
                add(".", data->pastPlaysHunter);
                add(".", data->pastPlaysDrac);
            }

            add("... ", data->pastPlaysHunter);
            add("... ", data->pastPlaysDrac);

         }
    }

    // else {
    //     return -1;
    // }
}

bool isValid (LocationID a, LocationID b, GraphRep* map) {
    return TRUE;
}

int inTrail (Trail* a, LocationID loc) {
    return -1;
}

char* getFirstLetter (PlayerID player) {
    if (player == PLAYER_LORD_GODALMING) {
        return "G";
    }

    else if (player == PLAYER_VAN_HELSING) {
        return "H";
    }

    else if (player == PLAYER_DR_SEWARD) {
        return "S";
    }

    else if (player == PLAYER_MINA_HARKER) {
        return "M";
    }

    else {
        return "D";
    }
}

void add (char* a, char* d) {

    char* s = new char[(strlen(a) + strlen(d))];
    strcpy (s,d);
    strcat (s,a);

    d = s;
}
