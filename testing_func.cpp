#include <iostream>
#include <string.h>
#include <assert.h>
//#include "map.h"
//#include "places.h"
// #include "Globals.h"
// #include "trail.h"
//#include "list.h"
//#include "places.h"
//#include "GameView.h"
//#include "stack.h"

//#include "gameController.h"
#include "map.h"

using namespace std;

int main () {

    // char pastPlays[] = "GMN.... SPL.... HAM.... MPA.... DCA.V.. GLV.... SLO.... HNS.... MST.... DCGT... GIR.... SPL.... HAO.... MZU.... DCDT... GSW.... SLO.... HNS.... MFR.... DCNT... GLV.... SPL.... HAO.... MZU.... DCOT... GSW.... SLO.... HNS.... " ;
    // cout << "here \n" << strlen(pastPlays) << " " << pastPlays[222]<< endl;
    // GameView a = newGameView (pastPlays);
    // //cout << "here10 \n";
    //
    // cout << a->current << endl;
    // cout << "here \n";
    //
    // for (int i=0; i<5; i++) {
    //     //cout << "here \n";
    //     printTrail (a->huntTrail[i]);
    // }
    GraphRep* a = newGraph(71);
    constMap (a);

    Stack* l = shortestPathHunter (a, NAPLES, LISBON);
    printStack (l);

    int y = minimumDistance (a, NAPLES, LISBON);
    cout << y << endl;
    return 0 ;
}
