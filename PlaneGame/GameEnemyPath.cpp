#include "stdafx.h"
#include "GameEnemyPath.h"


CGameEnemyPath::CGameEnemyPath()
{
	r = 0;
}
void CGameEnemyPath::getPosition(int & x, int& y, const int& x0, const int& y0, const double& offset, const int& s)
{
	x = 0;
	//x = 25 * r* offset / 1;
	y = -s;
	//r -= s;
}

CGameEnemyPath::~CGameEnemyPath()
{
}
