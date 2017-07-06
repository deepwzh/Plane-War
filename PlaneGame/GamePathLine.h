#pragma once
#include "GamePath.h"
class CGamePathLine :
	public CGamePath
{
public:
	CGamePathLine();
	void getPosition(int & x, int & y, const int & x0, const int & y0, const double & offset, const int & s);
	virtual ~CGamePathLine();
};

