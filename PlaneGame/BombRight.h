#pragma once
#include "Bomb.h"
class CBombRight :
	public CBomb
{
public:
	CBombRight(CGameManager* manager, int x = 0, int y = 0, int speed = 6);
	~CBombRight();
};

