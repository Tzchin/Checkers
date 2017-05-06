#pragma once
#include "PieceModel.h"

class StandardPieceModel : public PieceModel
{
public:
	StandardPieceModel(PlayerModel* _p, BoardModel * _bm);
	bool canMove(Coord co1, Coord co2);
};