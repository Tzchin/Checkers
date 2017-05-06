#include "KingPieceModel.h"
#include <stdlib.h>

KingPieceModel::KingPieceModel(PlayerModel * _p, BoardModel * _bm) : PieceModel(_p,_bm)
{
}

bool KingPieceModel::canMove(Coord co1, Coord co2)
{
	//Safety Checks
	if(!bm->CellValid(co1)) return false;
	if(!bm->CellValid(co2)) return false;
	if(bm->GetPiece(co1) != this) return false;
	if(bm->GetPiece(co2) != nullptr) return false;
	//Checks if directtion is |1| and left or right 1
	if(abs(co2.y - co1.y) == 1  && abs(co2.x - co1.x) == 1 )
	{
		return true;
	}
	if(abs(co2.y - co1.y) == 2) //Checks If jump of 2
	{
		if(abs(co2.x - co1.x) == 2) //|| co2.x - co1.x == -2
		{
			Coord nco;
			nco.x = (co1.x + co2.x)/2;
			nco.y = (co1.y + co2.y)/2;
			return (bm->GetPiece(nco)->player->number != player->number);
		}
	}
	return false;

}
