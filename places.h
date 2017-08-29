#include <string.h>
#include <iostream>
using namespace std;

struct Place {
   char* name;
   char* abbrev;
   LocationID id;
   PlaceType type;
} ;

Place* getPlaces () ;
char* getAbbrev (LocationID loc, Place* place);
PlaceType getPlaceType (LocationID loc, Place* place);
