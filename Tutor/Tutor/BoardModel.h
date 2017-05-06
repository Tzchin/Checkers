#pragma once
#include "CellModel.h"
#include "Coord.h"
#include "PieceModel.h"
#include <vector>
#include <stdexcept> //Exception
#define BLACK true
#define WHITE false

using std::vector;

class CellModel;
class PieceModel;
class BoardModel
{
public:
	int numRows, numCols;
	vector< vector<CellModel> > cells;
	BoardModel(int _numRows, int _numCols);
	BoardModel(){};
	void PrintBoard();
	void PrintBoardNorm();
	bool CellValid(Coord c); //Checks if cell fits board
	PieceModel * GetPiece(Coord c);
	void SetPiece(Coord c, PieceModel * p);


};