#include <iostream>
#include <string.h>
#include <assert.h>
#include "map.h"
// #include "Globals.h"
// #include "trail.h"
#include "places.h"
#include "GameView.h"
using namespace std;

int main () {

    // Trail** a = new Trail* [5];
    //
    // for (int i=0; i<5; i++) {
    //     a[i] = newTrail() ;
    // }
    //
    // pushToTrail (a[0],8);
    // pushToTrail (a[0],0);
    // pushToTrail (a[0],1);
    // pushToTrail (a[0],5);
    // pushToTrail (a[0],4);
    // pushToTrail (a[1],7);
    // pushToTrail (a[1],6);
    // pushToTrail (a[1],9);
    // pushToTrail (a[1],12);
    // pushToTrail (a[2],3);
    // pushToTrail (a[2],8);
    // pushToTrail (a[3],7);
    // pushToTrail (a[4],5);
    // pushToTrail (a[4],4);
    //
    // for (int i=0; i<5; i++) {
    //     printTrail(a[i]);
    // }
    // char a = 'B';
    // char b = 'O';
    //
    // string c = "";
    // c += a ;
    // c += b ;

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
    Place* a = new Place[71];
    getPlaces (a);
    char const* y = getAbbrev (3,a);

    cout << y << endl;
    return 0 ;
}
