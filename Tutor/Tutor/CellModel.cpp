#include "CellModel.h"
#include <stddef.h>

CellModel::CellModel(bool _colour, int _x, int _y)
{
	colour = _colour;
	x = _x;
	y = _y;
	piece = nullptr;
}

CellModel::CellModel(int _x, int _y)
{
	x = _x;
	y = _y;
	piece = nullptr;
}

bool CellModel::HasPiece()
{
	if(piece != nullptr)
	{
		return true;
	}
	return false;
}
