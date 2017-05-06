#include <iostream>
#include "BoardModel.h"
#include <stddef.h>
#include "GameModel.h"
#include "InterfaceControl.h"
#include "Autosave.h"

using namespace std;

int main()
{
//	InterfaceControl t; // For testing purposes
//	BoardModel bm(15,3);
	PlayerModel * p1 = new PlayerModel(1);
	PlayerModel * p2 = new PlayerModel(2);

	////Autosave autosave(8,8);
	//GameModel gm(p1,p2,8,8, &autosave);
	//gm.initPieces();

	GameModel* gm = Autosave::load("Save.txt");
	InterfaceControl ui(gm);

//	ui.gm.board.PrintBoard();
//	cout << endl << gm.board.CellValid(t.RequestCoord());
	ui.GameLoop();

	int x;
	cin >>x;
	delete(p1);
	delete(p2);
	return 0;
}