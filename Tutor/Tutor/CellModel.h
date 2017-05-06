#pragma once
#include "PieceModel.h"

class PieceModel;
class CellModel
{
public:
	CellModel(bool _colour, int _x, int _y);
	CellModel(int _x, int _y);
	bool colour;
	int x;
	int y;
	PieceModel* piece;

	bool HasPiece();

};