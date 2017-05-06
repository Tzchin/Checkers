#include "StandardPieceModel.h"

StandardPieceModel::StandardPieceModel(PlayerModel* _p, BoardModel * _bm) : PieceModel(_p,_bm)
{

}

bool StandardPieceModel::canMove(Coord co1, Coord co2)
{
		//Safety Checks
	if(!bm->CellValid(co1)) return false;
	if(!bm->CellValid(co2)) return false;
	if(bm->GetPiece(co1) != this) return false;
	if(bm->GetPiece(co2) != nullptr) return false;
	//Checks if right directtion and left or right 1
	if(co2.y - co1.y == player->direction && (co2.x - co1.x == 1 || co2.x - co1.x == -1)) 
	{
		return true;
	}
	if(co2.y - co1.y == player->direction * 2)
	{
		if(co2.x - co1.x == 2) //|| co2.x - co1.x == -2
		{
			Coord nco;
			nco.x = co1.x +1;
			nco.y = co1.y + player->direction;
			return (bm->GetPiece(nco)->player->number != player->number);	
		}
		if(co2.x - co1.x == -2)
		{
			Coord nco;
			nco.x = co1.x - 1;
			nco.y = co1.y + player->direction;
			return (bm->GetPiece(nco)->player->number != player->number);	
		}
	}
	return false;

}
