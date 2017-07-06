#include "stdafx.h"
#include "GamePathArc.h"


CGamePathArc::CGamePathArc()
{
	r = 1;
}

void CGamePathArc::getPosition(int & x, int& y, const int& x0, const int& y0, const double& offset, const int& s)
{
	x = 0;
	//x = 25 * r* offset / 1;
	y = 200 * r* sqrt(1 - offset*offset);
	r += s;
}


CGamePathArc::~CGamePathArc()
{
}
