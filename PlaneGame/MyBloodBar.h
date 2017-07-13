#pragma once
#include "BloodBar.h"
class CMyBloodBar :
	public CBloodBar
{
public:
	CMyBloodBar(int width, int height, CPoint point, int life = 1);
	virtual ~CMyBloodBar();
	BOOL draw(CDC * pDC, int hp) override;
};

