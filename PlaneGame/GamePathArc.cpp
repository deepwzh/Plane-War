#include "stdafx.h"
#include "GamePathArc.h"


CGamePathArc::CGamePathArc()
{
	r = 1;
}

void CGamePathArc::getPosition(int & x, int& y, const int& x0, const int& y0, const double& offset, const int& s)
{
	//x = 0;
	
	//x += 10*offset;
	//y += 50*sqrt(r*r - offset*offset*100);
	x = 25 * r* offset / 1;
	y = 20 * r* sqrt(1 - offset*offset);
	if(s > 0)
		r += 0.05*s;
	else {
		r -= 0.05* s;
		y = -y;

	}
}


CGamePathArc::~CGamePathArc()
{
}
