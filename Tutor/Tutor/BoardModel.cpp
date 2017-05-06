#include "BoardModel.h"
#include <iostream>

BoardModel::BoardModel(int _numRows, int _numCols){

	numRows = _numRows;
	numCols = _numCols;

	bool colour = BLACK;
	//Initialises Cells
	for(int col = 0; col < numCols; col++)
	{
		vector<CellModel> newCol;
		for(int row = 0; row < numRows; row++)
		{
			newCol.push_back(CellModel(colour, col, row));
			colour = !colour;
		}
		cells.push_back(newCol);
		colour = !newCol[0].colour;
	}

	std::cout << "BoardModel created" << _numRows << " " << _numCols;
	//*/
}

void BoardModel::PrintBoard()
{
	// Prints Board
	std::cout << "\n";
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
//			std::cout << cells[col][row].colour; // Tell cell to display colour
			std::cout << cells[col][row].x << cells[col][row].y << " "; // Tell cell to display (x,y)
/*			if (cells[col][row].piece != NULL) // Tell cell to display if piece on it
			{
				std::cout << cells[col][row].piece->player->number << " ";
			}
			else
			{
				std::cout << "   ";
			}*/
		}
		std::cout << std::endl;
	}
}

void BoardModel::PrintBoardNorm()
{
	// Prints Board not upside down
	std::cout << "\n";
	for (int row = numRows - 1; row >= 0; row--)
	{
		for (int col = 0; col < numCols; col++)
		{
			std::cout << cells[col][row].colour;
			if (cells[col][row].piece != nullptr)
			{
				std::cout << cells[col][row].piece->player->number << " ";
			}
			else
			{
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}
}

bool BoardModel::CellValid(Coord c)
{
	try
	{
		cells.at(c.x).at(c.y);
	}
	catch(std::out_of_range& oor)
	{
		return false;

	}
	return true;
}

PieceModel * BoardModel::GetPiece(Coord c)
{
	return (cells[c.x][c.y].piece);
}

void BoardModel::SetPiece(Coord c, PieceModel * p)
{
	cells[c.x][c.y].piece = p;
}