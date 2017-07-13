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
	virtual BOOL draw(CDC * pDC, int hp);
	// Í¨¹ý CSurroundInterface ¼Ì³Ð
	virtual void updatePosition(CPoint newpoint) override;
};

