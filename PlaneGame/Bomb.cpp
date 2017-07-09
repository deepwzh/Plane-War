#include "stdafx.h"
#include "Bomb.h"
#include "resource.h"
#include "GameManager.h"
CBomb::CBomb(CGameManager* manager,int x, int y, int speed, double offset) : CGameObject(manager, x, y),speed(speed) ,point0(x,y), offset(offset)
{
	cnt = 0;
}
CImageList CBomb::m_Images;

CBomb::~CBomb()
{

}
BOOL CBomb::setPoint(CPoint point) {
	this->point = point;
	return TRUE;
}

void CBomb::getPath(int& x, int& y, const int& s) {

}





