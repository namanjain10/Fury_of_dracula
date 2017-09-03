#include "map.h"
#include <iostream>

using namespace std;

struct Place {
   string name;
   string abbrev;
   LocationID id;
   PlaceType type;
} ;

char* getAbbrev (LocationID loc);
PlaceType getPlaceType (LocationID loc);
char* getName (LocationID loc);
