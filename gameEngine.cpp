#include <string.h>
#include <assert.h>
#include "map.h"
//#include "places.h"
//#include "trail.h"
#include "gameController.h"
#include "DracView.h"
#include "hunterView.h"
#include "dracula.h"
//#include "hunter.h"
#include "Globals.h"
#include <iostream>

using namespace std;

int main () {

    gameData* data = newGameData ();
    LocationID g, s, h, m;
    PlayerID currentPlayer = 0;
    int turn = 0;
    int loc = 1;
    LocationID result;
    string message[] = {"hi", "helol"};

//     string a = "GED.... SGE.... HZU.... MCA.... DCF.V.. GMN.... SCFVD.. HGE.... MLS.... DBOT... GLO.... SMR.... HCF.... MMA.... DC?T... GPL.... SMS.... HMR.... MGR.... DBAT... GLO.... SBATD.. HMS.... MMA.... DC?T... GPL.... SSJ.... HBA.... MGR.... DC?T... GPL.... SSJ.... HBA.... MGR.... DC?T... ";
//
// cout << a.length () << endl;
// a = revealDracPos (a, )
// cout << a << endl;
// }
    while (gameContinue(data)) {

        currentPlayer = turn%5 ;
        int trap;

        if (currentPlayer == PLAYER_DRACULA) {
            cout << "entered dracula \n";

            DracView view = newDracView (data->pastPlaysDrac, message);

            cout << "view made !!\n";
            result = DracAI (view);

            makeMove (currentPlayer, result, data);
            disposeDracView (view);
            cout << "dracula" << endl;
            turn++;

            cout << data->pastPlaysHunter << endl ;
            cout << data->pastPlaysDrac << endl ;
            cout << '\n';

            for (int i = 0; i<NUM_PLAYERS; i++) {
                cout << "player " << i << endl;
                cout << "Location : " << data->location[i] << endl;
            }

            cout << '\n';

            for (int i = 0; i<NUM_PLAYERS; i++) {
                cout << "player " << i << endl;
                cout << "Health : " << data->health[i] << endl;
            }
            cout << '\n';

            cout << "Dracula Trail : ";
            printQueue (data->dracTrail);
            cout << '\n';

            cout << "round : " << data->round << endl;
            cout << "score : " << data->score << endl;
            cout << '\n';
            //cout << data->pastPlaysHunter << endl;//strlen(data->pastPlaysHunter)<< endl ;
            //cout << data->pastPlaysDrac << endl;//strlen(data->pastPlaysDrac) << endl ;
        }

        else {
            cout << "PLAYER_LORD_GODALMING " ;
            cin >>  g;
            //HunterView view = newHunterView (pastPlaysHunter);
            result = g;
            makeMove (currentPlayer, result, data);
            //disposeHunterView (view);
            turn ++;
            currentPlayer ++;

            cout << "PLAYER_DR_SEWARD ";
            cin >> s;
            //HunterView view = newHunterView (pastPlaysHunter);
            result = s;
            makeMove (currentPlayer, result, data);
            //disposeHunterView (view);
            turn ++;
            currentPlayer ++;

            cout << "PLAYER_VAN_HELSING ";
            cin >> h;
            //HunterView view = newHunterView (pastPlaysHunter);
            result = h;
            makeMove (currentPlayer, result, data);
            //disposeHunterView (view);
            turn ++;
            currentPlayer ++;

            cout << "PLAYER_MINA_HARKER ";
            cin >> m;
            //HunterView view = newHunterView (pastPlaysHunter);
            result = m;
            makeMove (currentPlayer, result, data);
            //disposeHunterView (view);
            turn ++;
            currentPlayer ++;
            cout << "dracula turn next\n";
            // HunterView view = newHunterView (pastPlaysHunter);
            // result = HunterAI (view);
            // makeMove (currentPlayer, loc, NO_ENCOUNTER, data);
            //cout << "hunter" << endl;
            //cout << data->pastPlaysHunter << endl;//strlen(data->pastPlaysHunter)<< endl ;
            //cout << data->pastPlaysDrac << endl;//strlen(data->pastPlaysDrac) << endl ;
        }
        //evaluate (result,currentPlayer);
        // turn ++;
    }
    cout << data->pastPlaysHunter << endl ;
    cout << data->pastPlaysDrac << endl ;
    cout << '\n';

    for (int i = 0; i<NUM_PLAYERS; i++) {
        cout << "player " << i << endl;
        cout << "Location : " << data->location[i] << endl;
    }

    cout << '\n';

    for (int i = 0; i<NUM_PLAYERS; i++) {
        cout << "player " << i << endl;
        cout << "Health : " << data->health[i] << endl;
    }
    cout << '\n';

    cout << "Dracula Trail : ";
    printQueue (data->dracTrail);
    cout << '\n';

    cout << "round : " << data->round << endl;
    cout << "score : " << data->score << endl;
    cout << '\n';
    cout << "end!!!!\n";
}
