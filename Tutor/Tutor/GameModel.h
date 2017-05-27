#pragma once
#include "BoardModel.h"
#include "PlayerModel.h"
#include "Coord.h"
#include <stddef.h>
#include "Autosave.h"
enum WinState { none, p1win, p2win };

class Autosave;

class GameModel
{
public:
	BoardModel board;
	vector<PieceModel*> removedPieces;
	GameModel(PlayerModel* p1, PlayerModel* p2, int _numRows, int _numCols, Autosave* _a);
	void initPieces();
	void GameStart();
	int GetActivePlayer();
	bool CoordContainsPlayerPiece(Coord co, int p);
	bool CoordContainsPiece(Coord co);
	bool isMoveValid(Coord co1, Coord co2);
	bool doMove(Coord co1, Coord co2);
	bool switchActivePlayer();
	bool canJumpAgain(Coord co);
    PieceModel * getPiece(int x, int y);
    WinState getWinner();
private:
	PlayerModel* player1;
	PlayerModel* player2;
	PlayerModel* activePlayer;
	Autosave* autosave;
};
