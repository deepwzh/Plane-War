#pragma once
#include "GamePath.h"
class CGameEnemyPath :
	public CGamePath
{
protected:
	int r;
public:
	CGameEnemyPath();

	void getPosition(int & x, int & y, const int & x0, const int & y0, const double & offset, const int & s);
	~CGameEnemyPath();
};

