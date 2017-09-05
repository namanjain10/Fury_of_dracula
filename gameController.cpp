#include <string.h>
//#include "map.h"
#include <assert.h>
//#include "places.h"
//#include "trail.h"
#include "Globals.h"
#include "gameController.h"
#include "list.h"
#include "pqueue.h"
//#include "gameData.h"
using namespace std;

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
//     int hide[NUM_PLAYERS] ;
// };

//bool isValid (LocationID a, LocationID b, GraphRep* map);
int inTrail (Trail* a, LocationID loc);
string getFirstLetter (PlayerID player);

gameData* newGameData () {

    gameData* a = new gameData;
    a->map = newGraph(71);
    constMap(a->map);

    a->round = 0;
    a->score = GAME_START_SCORE;
    a->bloodPt = GAME_START_BLOOD_POINTS;

    for (int i = 0; i<NUM_PLAYERS-1; i++) {

        a->health[i] = GAME_START_HUNTER_LIFE_POINTS;
        a->location[i] = NOWHERE;
        a->hide[i] = 0;
     }

     a->hide[PLAYER_DRACULA] = 0;

    a->dracTrail = newTrail();

    for (int j = 0; j<6; j++) {
        push(a->dracTrail);
    }

    a->pastPlaysHunter = new char[1];
    a->pastPlaysDrac = new char[1];

    return a;
}

void makeMove (PlayerID player, LocationID loc, Encounter trap, gameData* data) {

    if (data->location[player] == loc) {

        data->hide[player] = 1;
        lifeGainRest (player, data->health);

        int q = 0;

        for (int i=0; i<4; i++) {
            if (data->hide[i] == 1) {
                q = 1;
            }

            else {
                q = 0;
                break;
            }
        }

        if (q == 1) {
            data->pastPlaysHunter = revealDracPos (data->pastPlaysHunter, data->trail, 6);    // unfold the 6th trail position of drac
        }
    }

    else {
        data->hide[player] = 0;
    }

    assert (isValid (data, loc, player)) ;  // to be made return boolean if move is valid

    if (player != PLAYER_DRACULA) {

        data->location[player] = loc;
        int q = inTrail (data->dracTrail, loc);

        if (q == -1) {

            string play = getFirstLetter (player);
            char* fir = new char[1];
            strcpy (fir,play.c_str());

            char* r = getAbbrev(loc);

            char* h = new char[8];
            char* t = new char[8];

            strcpy (h,fir);
            strcpy (t,fir);

            strcat (h,r);
            strcat (t,r);

            strcat (h,".... ");
            strcat (t,".... ");

            string ha = h;
            string ta = t;

            data->pastPlaysHunter += ha;
            data->pastPlaysDrac += ta;

            cout << data->pastPlaysHunter << endl;//strlen(data->pastPlaysHunter)<< endl ;
            cout << data->pastPlaysDrac << endl;//strlen(data->pastPlaysDrac) << endl ;

        }

        else {
            data->pastPlaysHunter = revealDracPos (data->pastPlaysHunter, data->trail, q);
            Queue e = getTrap (data->trail, q);

            if (e == TRAP) {
                lifeLossTrap (data->)
            }

            else if (e == VAMPIRE) {
                removeVampire (data->trail, q);

            }
        }
    }

    else {

        State* state = pushToTrail (data->dracTrail, loc, trap);
        char* hu = new char[8];
        char* d = new char[8];

        strcpy (hu,"D");
        strcpy (d,"D");

        if (state->hides == HIDE) {
            strcat (d,"HI");
            strcat (hu, "C?");
        }

        else if (state->hides == DOUBLE_BACK_1) {
            strcat (hu,"D1");
            strcat (d,"D1");
        }

        else if (state->hides == DOUBLE_BACK_2) {
            strcat (hu,"D2");
            strcat (d,"D2");
        }

        else if (state->hides == DOUBLE_BACK_3) {
             strcat (hu,"D3");
             strcat (d,"D3");
        }

        else if (state->hides == DOUBLE_BACK_4) {
             strcat (hu,"D4");
             strcat (d,"D4");
        }

        else if (state->hides == DOUBLE_BACK_5) {
            strcat (hu,"D5");
            strcat (d,"D5");
        }

        else {
            PlaceType pla = getPlaceType(loc);

            if (pla == LAND) {
                strcat (hu,"C?");
            }

            else {
                strcat (hu,"S?");
                bloodLossSea (data->bloodPt);
            }
        }

        strcat (d,getAbbrev(loc));

        if (trap == TRAP) {
            strcat(hu, "T");
            strcat(d, "T");
        }

        else {
            strcat(hu,".");
            strcat(d,".");
        }

        if (trap == VAMPIRE) {
            strcat(hu,"V");
            strcat(d,"V");
        }

        else {
            strcat(hu,".");
            strcat(d,".");
        }

        strcat(hu,".. ");
        strcat(d,".. ");

        string ha = hu;
        string ta = d;

        data->pastPlaysHunter += ha;
        data->pastPlaysDrac += ta;

        cout << "2222222\n";
        cout << data->pastPlaysHunter << endl;
        cout << data->pastPlaysDrac << endl;
     }
}

bool isValid (gameData* data, LocationID to, PlayerID player) {

    graphNode* add = data->map->arr[data->location[player]];
    //graphNode* add = map->arr[from];
    int r = 0;

    if (player == PLAYER_DRACULA) {
        cout << "Dracula\n";

        while (add != NULL) {
            if (add->location == to) {
                r = 1;
                break;
            }
            add = add->next;
        }

        if (r == 0) {
            return FALSE;
        }

        else {
            if (add->mode == RAIL) {
                return FALSE;
            }

            else {
                return TRUE;
            }
        }
    }

    else {
        cout << "player\n";
        int u = (data->round + player)%4 ;
        //int u = (score + player)%4 ;
        cout << u << endl;
        if (u == 0) {

            while (add != NULL) {
                if (add->location == to) {
                    r = 1;
                    break;
                }
                add = add->next;
            }

            if (r == 0) {
                return FALSE;
            }

            else {
                if (add->mode == RAIL) {
                    return FALSE;
                }
                else {
                    return TRUE;
                }
            }
        }

        else {

            while (add != NULL) {

                if (add->location == to) {
                    r = 1;
                    break;
                }
                add = add->next;
            }

            cout << "r is " << r << endl;

            if (r == 0) {

                if (u == 1) {
                    return FALSE;
                }

                else {
                    return checkRail (data->map->arr[data->location[player]]->location, to, u, data->map);
                    // cout << "entered checkrail\n";
                    // return checkRail (from, to, u, map);
                }
            }

            else {
                return TRUE;
            }
    }
}
}

int inTrail (Trail* a, LocationID loc) {
    return -1;
}

string getFirstLetter (PlayerID player) {
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

bool checkRail (LocationID from, LocationID to, int u, GraphRep* map) {

    cout << "entered checkrail\n";
    graphNode* add = map->arr[from];

    List* list = newList() ;
    Pqueue* queue = newPqueue() ;

    pushList (list, from, 0, 0, -1);

    int count = 0, p = 0;
    PqueueNode* w;
    LocationID prev = from ;

    while (count <= 70 && u != 0) {

        while (add != NULL) {

            if (add->mode == RAIL) {
                if (checkPqueue(queue,add->location, add->mode) == 0 && checkList (list, add->location, add->mode) == 0) {
                    pushPqueue(queue, add->location, p + 1, add->mode, prev);
                }
                add = add->next;
            }

            else {
                add = add->next;
            }
        }

            int size = getSize (queue);

            if (size == 0) {
                return 0;
            }

            w = popPqueue(queue);

    		if (w->val == to) {
                p = w->priority ;
    			break;
    		}

    		pushList(list, w->val, w->priority, w->mode, w->prev);

            add = map->arr[w->val]->next;
    		prev = w->val;
            p = w->priority;

        count ++;
    }
    if (p != u) {
        return FALSE;
    }
    else {
        return TRUE;
    }
}

string revealDracPos (string a, Trail* b, PlayerID player, int n) {

    if (b->start->val != NOWHERE) {

        char* s = getAbbrev (b->start->val);
        a[a.length() - (8*(player+2) + 40*(n-1)) + 1] = s[0];
        a[a.length() - (8*(player+2) + 40*(n-1)) + 2] = s[1];
    }
    return a;
}
