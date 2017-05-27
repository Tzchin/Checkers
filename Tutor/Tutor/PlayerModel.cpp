#include "PlayerModel.h"

PlayerModel::PlayerModel(int _num) : number(_num)
{
	if(number != 1)
	{
		direction = 1;
	}
	else direction = -1;
}

