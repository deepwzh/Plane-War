#pragma once
#include "Plane.h"
class CTwoShootPlane :
	public CPlane
{
public:
	CTwoShootPlane(CGameManager * manager, int x, int y, int speed);
	virtual BOOL attack();
	~CTwoShootPlane();
};

