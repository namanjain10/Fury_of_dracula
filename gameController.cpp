#include <string.h>
//#include "map.h"
#include <assert.h>
#include "places.h"
//#include "trail.h"
#include "Globals.h"
#include "gameController.h"
#include "list.h"
#include "pqueue.h"
//#include "queue.h"

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

int inTrail (Queue* a, LocationID loc);
string getFirstLetter (PlayerID player);
// string revealDracPos (string a, Queue* b, PlayerID player, int n) ;
bool checkHide (Queue* a);
bool checkDoubleBack (Queue* a);
QueueNode* getTrailElement (Queue* currentView, LocationID location);

QueueNode* getTrailElement (Queue* currentView, LocationID location) {
    return findNode (currentView, location);
}

gameData* newGameData () {

    gameData* a = new gameData;
    a->map = newGraph(71);
    constMap(a->map);

    a->round = -1;
    a->score = GAME_START_SCORE;
    a->health[PLAYER_DRACULA] = GAME_START_BLOOD_POINTS;
    a->location[PLAYER_DRACULA] = NOWHERE;

    for (int i = 0; i<NUM_PLAYERS-1; i++) {

        a->health[i] = GAME_START_HUNTER_LIFE_POINTS;
        a->location[i] = NOWHERE;
        a->hide[i] = 0;
     }

     a->hide[PLAYER_DRACULA] = 0;

    a->dracTrail = newQueue(TRAIL_SIZE);

    for (int j = 0; j<6; j++) {
        pushQueue (a->dracTrail,UNKNOWN_LOCATION, -1, -1, -1);
    }

    a->pastPlaysHunter = new char[1];
    a->pastPlaysDrac = new char[1];

    return a;
}

void makeMove (PlayerID player, LocationID loc,  gameData* data) {

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
            data->pastPlaysHunter = revealDracPos (data->pastPlaysHunter, data->dracTrail, player, 6);
        }
        //cout << "first\n";
    }

    else {
        data->hide[player] = 0;
    }

    if (player == PLAYER_LORD_GODALMING) {
        data->round ++;
    }
    assert (isValid (data, loc, player)) ;  // to be made return boolean if move is valid

    cout << "valid move\n";

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
        }

        else {
            data->pastPlaysHunter = revealDracPos (data->pastPlaysHunter, data->dracTrail, player, q);
            //cout << "first\n";

            QueueNode* e = getTrailElement (data->dracTrail, loc);
            //cout << "second\n";

            string play = getFirstLetter (player);
            char* fir = new char[1];
            strcpy (fir,play.c_str());

            //cout << "third\n";
            char* r = getAbbrev(loc);

            char* h = new char[8];
            char* t = new char[8];

            strcpy (h,fir);
            strcpy (t,fir);

            strcat (h,r);
            strcat (t,r);
            //cout << "fourth\n";
            int y = 0;

            if (e->nT > 0) {
                //cout << "mid\n";
                int c = e->nT;
                //cout << "fifth\n";

                while (c != 0) {
                    lifeLossTrap (player, data->health);

                    if (data->health[player] <= 0) {
                        data->location[player] = ST_JOSEPH_AND_ST_MARYS;
                        data->score = data->score - SCORE_LOSS_HUNTER_HOSPITAL;
                        break;
                    }
                    c--;
                }

                e->nT = c;

                strcat (h,"T");
                strcat (t,"T");
                y++;
            }
            //cout << "seventh\n";

            if (e->nV > 0) {
                e->nV = 0;
                strcat (h,"V");
                strcat (t,"V");
                y++;
            }

            if (data->location[PLAYER_DRACULA] == loc) {

                if (getPlaceType(loc) != SEA) {

                    bloodLossHunter (data->health);
                    lifeLossDrac (player, data->health);

                    if (data->health[player] <= 0) {
                        data->location[player] = ST_JOSEPH_AND_ST_MARYS;
                        data->score = data->score - SCORE_LOSS_HUNTER_HOSPITAL;
                    }

                    strcat (h,"D");
                    strcat (t,"D");
                    y++;
                }
            }

            for (int i=0; i<3-y; i++) {
                strcat (h,".");
                strcat (t,".");
            }
            //cout << "ninth\n";

            strcat (h,". ");
            strcat (t,". ");

            string ha = h;
            string ta = t;

            data->pastPlaysHunter += ha;
            data->pastPlaysDrac += ta;
        }
    }

    else {
        Encounter trap;
        if (data->round %13 == 0) {
            trap = VAMPIRE;
        }

        else {
            trap = TRAP;
        }

        int t = data->dracTrail->start->nT;
        int v = data->dracTrail->start->nV;

        printQueue (data->dracTrail);
        if (trap == TRAP) {
            pushQueue (data->dracTrail, loc, getPlaceType(loc), 1, 0);
        }

        else if (trap == VAMPIRE) {
            pushQueue (data->dracTrail, loc, getPlaceType(loc), 0, 1);
        }
        char* hu = new char[8];
        char* d = new char[8];

        strcpy (hu,"D");
        strcpy (d,"D");

        int q = inTrail (data->dracTrail, loc);
        cout << "present in trail " << q << "\n";
        q = TRAIL_SIZE - q ;

        if (q == 6) {
            cout << "oops entered \n";
            strcat (d,"HI");
            strcat (hu,"C?");
        }

        else if (q == 1) {
            strcat (hu,"D1");
            strcat (d,"D1");
        }

        else if (q == 2) {
            strcat (hu,"D2");
            strcat (d,"D2");
        }

        else if (q == 3) {
             strcat (hu,"D3");
             strcat (d,"D3");
        }

        else if (q == 4) {
             strcat (hu,"D4");
             strcat (d,"D4");
        }

        else if (q == 5) {
            strcat (hu,"D5");
            strcat (d,"D5");
        }

        else {

            PlaceType pla = getPlaceType(loc);

            if (pla == LAND) {
                strcat (hu,"C?");
                strcat (d,getAbbrev(loc));
            }

            else {
                strcat (hu,"S?");
                strcat (d,getAbbrev(loc));
                bloodLossSea (data->health);
            }
        }

        data->location[PLAYER_DRACULA] = loc;

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
        printQueue (data->dracTrail);

        if (t > 0) {
            strcat(hu,"M");
            strcat(d,"M");
        }

        else if (v > 0) {
            data->score = data->score - SCORE_LOSS_VAMPIRE_MATURES;
            strcat(hu,"V");
            strcat(d,"V");
        }

        else {
            strcat(hu,".");
            strcat(d,".");
        }
        strcat(hu,". ");
        strcat(d,". ");

        string ha = hu;
        string ta = d;

        data->pastPlaysHunter += ha;
        data->pastPlaysDrac += ta;

        data->score = data->score - SCORE_LOSS_DRACULA_TURN;
     }
}

bool isValid (gameData* data, LocationID to, PlayerID player) {

    if (data->location[player] == NOWHERE) {
        return TRUE;
    }

    graphNode* add = data->map->arr[data->location[player]];

    int r = 0;
    int q = inTrail (data->dracTrail, to);

    cout << "in trail " << q << '\n';

    if (player == PLAYER_DRACULA) {
        cout << "Dracula\n";

        if (data->location[PLAYER_DRACULA] == to) {
            if (getPlaceType(to) == SEA) {
                cout << "cant hide in sea\n";
                return FALSE;
            }

            else {
                cout << "problem\n";
                return (checkHide (data->dracTrail));
            }
        }

        if (q != -1) {
            cout << "entered DOUBLE_BACK\n";
            return (checkDoubleBack (data->dracTrail));
        }

        cout << "please\n";

        while (add != NULL) {
            if (add->location == to) {
                r = 1;
                break;
            }
            cout << "ok\n";
            add = add->next;
        }

        cout << "now what \n";

        if (r == 0) {
            cout << "cant find path\n";
            return FALSE;
        }

        else {
            if (add->mode == RAIL) {
                cout << "cant go in rail \n";
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
            cout << "is it??\n";

            while (add != NULL) {
                if (add->location == to) {
                    cout << add->location << endl;
                    r = 1;
                    break;
                }
                add = add->next;
            }
            cout << "is it??\n";
            if (r == 0) {
                cout << "false\n";
                return FALSE;
            }

            else {
                cout << "true\n";
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

int inTrail (Queue* a, LocationID loc) {
    QueueNode* add = a->start;
    int count = 1;

    while (add != NULL) {
        if (add->val == loc) {
            return count;
        }
        count ++;
        add = add->next;
    }
    return -1;
}

//returns first letter to be passed to view
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

string revealDracPos (string a, Queue* b, PlayerID player, int n) {

    QueueNode* add = b->start;

    int i = 0;

    while (i < n-1) {
        add = add->next;
        i++;
    }

    if (add->val == NOWHERE) {
        return a;
    }

    char* s = getAbbrev (add->val);

    a[a.length() - (8*(player+1) + 40*(TRAIL_SIZE - n)) + 1] = s[0];
    a[a.length() - (8*(player+1) + 40*(TRAIL_SIZE - n)) + 2] = s[1];

    return a;
}

bool checkHide (Queue* a) {
    cout << "entered checkHide\n";
    QueueNode* add = a->start->next;
    QueueNode* prev = NULL;
    int hide = 0;
    cout << "initialized\n";

    while (add != NULL) {

        if (prev->val == add->val) {
            cout << "cant hide twice in trail\n";
            cout << "exit True\n";
            return FALSE;
        }

        prev = add;
        add = add->next;
        cout << "added to next\n";
    }
    cout << "exit True\n";
    return TRUE;
}

bool checkDoubleBack (Queue* a) {
    cout << "entered checkDoubleBack\n";
    QueueNode* add = a->start->next;
    cout << "initial add " << add->val << endl;
    QueueNode* prev = add;
    cout << "initialized\n";

    while (add != NULL) {
        prev = add->next->next;
        cout << "prev " << prev->val << endl;
        while (prev != NULL) {
            if (prev->val == add->val && prev->val != NOWHERE) {
                cout << "cant double back twice\n";
                cout << "exit True\n";
                return FALSE;
            }
            prev = prev->next;
        }
        add = add->next;
        cout << "added to next\n";
    }
    cout << "exit True\n";
    return TRUE;
}

// returns if game should continue or not
bool gameContinue (gameData* data) {
    return (data->health[PLAYER_DRACULA] > 0 && data->score > 0);
}




// Dracula Trail : -1 < -1 < -1 < -1 < 61 < 38 <
// from 38
// pushing boat 33
// pushing road 61
// pushing road 41
// edges made 4
// edges are 41
// edges are 61
// edges are 33
// edges are 38
// check
// exit
// exit
// exit
// exit
// result given 38
// in trail 6
// Dracula
// problem
// entered checkHide
// initialized
// Segmentation fault (core dumped)


// Dracula Trail : -1 < -1 < -1 < 20 < 26 < 17 <
// view made
// from 17
// pushing road 34
// pushing road 26
// edges made 3
// edges are 26
// edges are 34
// edges are 17
// check
// exit
// exit
// exit
// result given 26
// in trail 5
// Dracula
// entered DOUBLE_BACK
// entered checkDoubleBack
// initialized
// added to next
// added to next
// added to next
// added to next
// Segmentation fault (core dumped)




// Dracula Trail : -1 < -1 < -1 < -1 < 38 < 41 <
// from 41
// pushing road 39
// pushing road 38
// pushing road 22
// edges made 4
// edges are 22
// edges are 38
// edges are 39
// edges are 41
// check
// exit
// exit
// exit
// exit
// result given 38
// in trail 5
// Dracula
// entered DOUBLE_BACK
// entered checkDoubleBack
// initial add -1
// initialized
// prev -1
// added to next
// prev 38
// added to next
// prev 41
// added to next
// Segmentation fault (core dumped)
