#pragma once
#include <iostream>
using namespace std;
struct Coord
{
	int x;
	int y;
};

ostream& operator<<(ostream& os, Coord& co);