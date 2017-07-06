#pragma once
#include "GamePath.h"
class CGamePathArc :
	public CGamePath
{
protected:
	int r;
public:
	CGamePathArc();
	void getPosition(int & x, int & y, const int & x0, const int & y0, const double & offset, const int & s);
	virtual ~CGamePathArc();
};

