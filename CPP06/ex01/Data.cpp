#include "Data.h"

/*** struct initialization ***/
Data::Data() : number(0), text("default") {}

/*** struct method ***/
Data::Data( int n, std::string t ) : number(n), text(t) {}