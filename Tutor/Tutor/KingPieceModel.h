#pragma once
#include "PieceModel.h"

class KingPieceModel : public PieceModel
{
public:
	KingPieceModel(PlayerModel * _p, BoardModel * _bm);
	bool canMove(Coord co1, Coord co2);
};