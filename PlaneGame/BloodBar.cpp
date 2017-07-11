#include "stdafx.h"
#include "BloodBar.h"

CBloodBar::CBloodBar(int width, int height, CPoint point, int life) : width(width), height(height), point(point), life(life)
{
}


CBloodBar::~CBloodBar()
{
}


BOOL CBloodBar::draw(CDC * pDC, int hp)
{
	return 0;
}

void CBloodBar::updatePosition(CPoint newpoint)
{
	point = newpoint;
}