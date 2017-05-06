#pragma once
#include "PieceModel.h"

PieceModel::PieceModel(PlayerModel* p, BoardModel * _bm)
{
	player = p;
	bm = _bm;
}