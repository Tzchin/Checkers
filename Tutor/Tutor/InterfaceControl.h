#pragma once
#include "GameModel.h"
#include "BoardModel.h"
#include <string>

class InterfaceControl
{
public:
	
	InterfaceControl(GameModel * _gm);
	void GameLoop();
private:
	GameModel * gm;
	Coord RequestCoord(std::string p);
	Coord RequestCoord();
	Coord RequestValidCoord();
	Coord RequestValidCoord(std::string p);
};