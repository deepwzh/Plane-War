#pragma once
#include "GameObject.h"
#include "CommonFun.h"
#include "SurroundInterface.h"
class CBloodBar : CSurroundInterface
{
protected:
	int width;
	int height;
	CPoint point;
	int life;
	int HP;
public:
	CBloodBar(int width, int height, CPoint point, int life);
	virtual ~CBloodBar();
	// 通过 CGameObject 继承
	virtual BOOL draw(CDC * pDC, int hp) = 0;

	// 通过 CSurroundInterface 继承
	virtual void updatePosition(CPoint newpoint) override;
};

