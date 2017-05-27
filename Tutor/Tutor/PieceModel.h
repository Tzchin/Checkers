#pragma once
#include "PlayerModel.h"
#include "Coord.h"
#include "BoardModel.h"

class BoardModel;
class PieceModel
{
public:
	PlayerModel* player;
	virtual bool canMove(Coord co1, Coord co2) = 0;
	PieceModel(PlayerModel* p, BoardModel* _bm);
protected:
	BoardModel * bm;
};
