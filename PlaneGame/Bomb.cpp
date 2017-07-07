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
BOOL CBomb::Collided(POSITION pos)
{
	manager->removeObject(L"Bomb", pos);
	return 1;
}
void CBomb::getPath(int& x, int& y, const int& s) {

}

BOOL CBomb::draw(CDC * pDC)
{
	int x0 = 0, y0 = 0;
	int x = point.x;
	int y = point.y;
	//TRACE("#####%lf\n", offset);
	path->getPosition(x0, y0, point0.x, point0.y, offset, speed);
	point.y -= y0;
	point.x += x0;
	m_Images.Draw(pDC, 0, point, ILD_TRANSPARENT);
	TRACE("%d %d\n", width, height);
	return TRUE;
}

BOOL CBomb::LoadImages()
{
	CCommonFun::LoadImageW(m_Images, IDB_Bomb, RGB(0, 0, 0), 1);
	return 0;
}

BOOL CBomb::Initial()
{
	CCommonFun::GetImageListInfo(m_Images, width, height);
	return 0;
}


