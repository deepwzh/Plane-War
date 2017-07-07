#pragma once
#include "GamePath.h"
class CGamePathDefault :
	public CGamePath
{
public:
	CGamePathDefault();
	~CGamePathDefault();

	// Í¨¹ý CGamePath ¼Ì³Ð
	virtual void getPosition(int & x, int & y, const int & x0, const int & y0, const double & offset, const int & s) override;
};

