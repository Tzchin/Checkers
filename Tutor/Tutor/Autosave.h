#pragma once
#include <fstream>
#include "Coord.h"
#include "GameModel.h"
#include <string>
using namespace std;
class GameModel;

class Autosave
{
public:
	Autosave(int numRows, int numCols);
	void addMove(Coord co1, Coord co2);
	static GameModel* load(string filename);
private:
	fstream save;

};