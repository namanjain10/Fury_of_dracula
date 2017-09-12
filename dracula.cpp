#include "DracView.h"

//registerBestPlay(char *play, PlayerMessage message);

LocationID DracAI (DracView view) {
    cout << "entered dracai\n";

    LocationID hunterLoc[NUM_PLAYERS-1];
    LocationID myLocation = whereIs (view, PLAYER_DRACULA);

    cout << "i am at : " << myLocation << endl;
    cout << "lets\n";

    if (myLocation == NOWHERE) {
        return initDrac();
    }
    cout << "lets\n";

    for (int i=0; i<NUM_PLAYERS-1; i++) {
        hunterLoc[i] = whereIs (view, i);
    }
    cout << "lets\n";

    int myHealth = howHealthyIs (view, PLAYER_DRACULA);
    LocationID* edges;
    int size;
    int virtualHealth;
    cout << "lets\n";

    edges = whereCanIgo (view, &size, 1, 1);
    cout << "lets\n";

    int hunterDistance[size], castleDistance[size];
    int maxHuntDis = 0;
    int maxCastleDis = 0;
    double result[size];
    cout << "lets\n";

    for (int i=0; i<size; i++) {
        result[i] = 0;
    }
    cout << "lets1\n";

    cout << "expected places \n";

    for (int i=0; i<size; i++) {
        cout << edges[i] << endl;
    }

    for (int i=0; i<size; i++) {

        cout << "end\n";

        hunterDistance[i] = minDist(giveMeMap(view), edges[i], hunterLoc);
        cout << "exit\n";
        if (hunterDistance[i] > maxHuntDis) {
            maxHuntDis = hunterDistance[i];
        }
    }

    cout << "lets\n";

    for (int i=0; i<size; i++) {
        hunterDistance[i] = maxHuntDis - hunterDistance[i];
        result[i] += hunterDistance[i];
    }
    cout << "lets\n";

    if (myHealth < 18) {
        cout << "entered health " << endl;
        cout << "size : " << size << '\n';

        for (int i=0; i<size; i++) {
            cout << "entered for \n";

            virtualHealth = 0 ;
            castleDistance[i] = shortestDistanceDrac (giveMeMap(view), edges[i], CASTLE_DRACULA);

            cout << "gotIt \n" ;
            result[i] += (myHealth * castleDistance[i])/(myHealth - virtualHealth);

            cout << castleDistance[i] << " " << result[i] << " " ;
        }
        cout << endl;
    }
    cout << "lets\n";

    double min = result[0];
    int pos = 0;

    for (int i=0; i<size; i++) {
        if (min > result[i]) {
            min = result[i];
            pos = i;
        }
    }
    cout << "exiting\n";
    return edges[pos];
}
