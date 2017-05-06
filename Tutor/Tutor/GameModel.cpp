#include "GameModel.h"
#include "StandardPieceModel.h"
#include "KingPieceModel.h"
#include "InterfaceControl.h"

#include <iostream>

GameModel::GameModel(PlayerModel* p1, PlayerModel* p2, int _numRows, int _numCols, Autosave* _a) 
{
	board = BoardModel(_numRows, _numCols);
	player1 = p1;
	player2 = p2;
	activePlayer = player1;
	autosave = _a;
}

void GameModel::initPieces()
{
	int row = 0, col = 0;
	int offset = 0;
	for(;row < 2; row++)
	{
		for(col = 0;col + offset < board.numCols; col += 2)
		{
			board.cells[col+offset][row].piece = new StandardPieceModel(player1, &board);
		}
		offset = 1 - offset;
	}
	offset =1;
	for(row = board.numRows - 1;row > board.numRows - 3; row--)
	{
		for(col = 0; col + offset < board.numCols; col += 2)
		{
			board.cells[col+offset][row].piece = new StandardPieceModel(player2, &board);
		}
		offset = 1 - offset;
	}
}

void GameModel::GameStart()
{
	int pturn = player1->number;
//	InterfaceControl Ui(BoardModel );

//
	Coord co;
//	std::cout << cell1.x << cell1.y << std::endl;

//	do
	{
//		co = Ui.RequestCoord();

	}
//	while (board.CellValid(co) == false);



}

int GameModel::GetActivePlayer()
{

	return (activePlayer->number);
}

bool GameModel::switchActivePlayer()
{
	if(activePlayer == player1)
	{
		activePlayer = player2;
		return true;
	}
	else if (activePlayer == player2)
	{
		activePlayer = player1;
		return true;
	}
	throw "Error: Couldn't change active player.";
}

bool GameModel::CoordContainsPlayerPiece(Coord co, int pn)
{
	if(!board.CellValid(co)) return false;
	PieceModel * p = board.GetPiece(co);
	return (p != nullptr && p->player->number == pn);
}

bool GameModel::CoordContainsPiece(Coord co)
{
	if(!board.CellValid(co)) return false;
	PieceModel * p = board.GetPiece(co);
	return (p != nullptr);
}

bool GameModel::isMoveValid(Coord co1, Coord co2)
{
	return board.GetPiece(co1)->canMove(co1,co2);
}

bool GameModel::doMove(Coord co1, Coord co2)
{
	if (isMoveValid(co1, co2) == false) throw "Error: Executing Invalid Move";
	autosave->addMove(co1,co2);
	//Moves initial piece from coord 1 to coord 2
	board.SetPiece(co2, board.GetPiece(co1));
	board.SetPiece(co1, nullptr); 

	if(co2.y == 0 || co2.y == board.numRows-1) //Checks if piece at ends of row and promotes
	{
		removedPieces.push_back(board.GetPiece(co2));
		board.SetPiece(co2, new KingPieceModel(board.GetPiece(co2)->player, &board));
	}

	if(co2.x - co1.x == 2 || co2.x - co1.x == -2) //Checks if jump, if so capture
	{
		Coord nco;
		nco.x = (co1.x + co2.x) /2;
		nco.y = (co1.y + co2.y) /2;
		removedPieces.push_back(board.GetPiece(nco));
		board.SetPiece(nco, nullptr);
		return canJumpAgain(co2);
	}
	switchActivePlayer();
	return false;

}

bool GameModel::canJumpAgain(Coord co)
{
		Coord coTL;
	coTL.x = co.x - 2;
	coTL.y = co.y + 2;
		Coord coTR;
	coTR.x = co.x + 2;
	coTR.y = co.y + 2;
		Coord coBL;
	coBL.x = co.x - 2;
	coBL.y = co.y - 2;
		Coord coBR;
	coBR.x = co.x + 2;
	coBR.y = co.y - 2;
	PieceModel* p = board.GetPiece(co);
	return ( p->canMove(co,coTL) //Checks If any direction is jumpable
		|| p->canMove(co,coBL)
		|| p->canMove(co,coBR)
		|| p->canMove(co,coTR));
}