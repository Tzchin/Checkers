#include "Coord.h"

ostream& operator<<(ostream& os, Coord& co)
{
	os << "(" << co.x << "," << co.y << ")";
	return os;
}