#include "InterfaceControl.h"
#include <iostream>

using namespace std;

InterfaceControl::InterfaceControl(GameModel * _gm)
{
	gm = _gm;
}

Coord InterfaceControl::RequestCoord(std::string p) // Temporary
{
	int x, y;
	std::cout << p << std::endl << "x:";
	std::cin >> x;
	std::cout << "y:";
	std::cin >> y;
	Coord xy;
	xy.x = x;
	xy.y = y;
	
	return (xy);
}

Coord InterfaceControl::RequestCoord() // Temporary
{
	int x, y;
	std::cout << "x:";
	std::cin >> x;
	std::cout << "y:";
	std::cin >> y;
	Coord xy;
	xy.x = x;
	xy.y = y;
	return (xy);
}

Coord InterfaceControl::RequestValidCoord()
{
		Coord co = RequestCoord("Enter Co-ord");


	while (gm->board.CellValid(co) == false)
	{
		cout << "Invalid Co-ordinate\n";
		co = RequestCoord();
	}
	return (co);
}

Coord InterfaceControl::RequestValidCoord(string p)
{
		Coord co = RequestCoord(p);


	while (gm->board.CellValid(co) == false)
	{
		cout << "Invalid Co-ordinate\n";
		co = RequestCoord();
	}
	return (co);
}


void InterfaceControl::GameLoop()
{
	try
	{
		while(true) //temp
		{
			gm->board.PrintBoardNorm();
			int pturn = gm->GetActivePlayer();
			cout << "Player " << pturn << " turn:\n";
		//	InterfaceControl Ui(BoardModel );

			Coord co1;
			Coord co2;
		//	std::cout << cell1.x << cell1.y << std::endl;
			do
			{
				co1 = RequestValidCoord("Enter Coord of piece:");
				while(!gm->CoordContainsPlayerPiece(co1, pturn))
				{
					cout << "No piece for player " << pturn << " exists for coord\n";
					co1 = RequestValidCoord();
				}

				co2 = RequestValidCoord("Enter move to Coord:");
				while(gm->CoordContainsPiece(co2))
				{
					cout << "Piece on Coord. Can't Move.\n";
					co2 = RequestValidCoord();
				}
			if(!gm->isMoveValid(co1, co2))
			{ cout << "Move not valid\n"; }
			}
			while(!gm->isMoveValid(co1, co2)); 
			while (gm->doMove(co1, co2)) //Returns true if piece captured
			{
				do
				{
						co1 = co2;
						co2 = RequestValidCoord("Enter move to Coord:");
					while(gm->CoordContainsPiece(co2))
					{
						cout << "Piece on Coord. Can't Move.\n";
						co2 = RequestValidCoord();
					}
					if(!gm->isMoveValid(co1, co2))
					{ cout << "Move not valid\n"; }
			
				}
				while(!gm->isMoveValid(co1, co2)); 
			}
		

			gm->board.PrintBoardNorm();
		}
	}
	catch(const char* msg)
	{
		cout << msg << endl;
	}
}