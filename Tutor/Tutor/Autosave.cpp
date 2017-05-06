#include "Autosave.h"

Autosave::Autosave(int numRows, int numCols)
{
	save.open("autosave.txt", ios::trunc | ios:: out);
	save << numRows << endl
		<< numCols << endl;
}

void Autosave::addMove(Coord co1, Coord co2)
{
	save << co1.x << "," << co1.y << "-" << co2.x << "," << co2.y << endl;
	save.flush();
}

GameModel* Autosave::load(string filename)
{
	//Init.
	string line;
	fstream loader;
	loader.open(filename, ios::in);
	PlayerModel * p1 = new PlayerModel(1);
	PlayerModel * p2 = new PlayerModel(2);
	int numRows;
	int numCols;


	//Reads Rows and Cols from save
	getline(loader, line);
	numRows = std::atoi(line.c_str());
	getline(loader, line);
	numCols = std::atoi(line.c_str());
	Autosave* a = new Autosave(numRows, numCols);

	GameModel* loadedGame = new GameModel(p1, p2, numRows, numCols, a);

	loadedGame->initPieces();
	while(getline(loader, line, ','))
	{
	Coord co1;
	co1.x = std::atoi(line.c_str());
	getline(loader, line, '-');
	co1.y = std::atoi(line.c_str());
	Coord co2;
	getline(loader, line, ',');
	co2.x = std::atoi(line.c_str());
	getline(loader, line);
	co2.y = std::atoi(line.c_str());
	
	cout << co1 << endl
		<< co2 << endl;
	loadedGame->doMove(co1, co2);
	}
	return loadedGame;


}

