#include "stdafx.h"
#include "MyBomb.h"
#include "resource.h"
#include "GameManager.h"

CImageList CMyBomb::m_Images;


CMyBomb::~CMyBomb()
{
}

CMyBomb::CMyBomb(CGameManager* manager, int x, int y, int speed, double offset, int attack_value) : CBomb(manager, attack_value,x, y, speed, offset )
{
	cnt = 0;
}

BOOL CMyBomb::Collided(POSITION pos, CGameObject* obj)
{

	manager->removeObject(L"mineBomb", pos);
	return 1;
}
BOOL CMyBomb::draw(CDC * pDC)
{
    int x0 = 0, y0 = 0;
	int x = point.x;
	int y = point.y;
	path->getPosition(x0, y0, point0.x, point0.y, offset, speed);
	point.y -= y0;
	point.x += x0;
	m_Images.Draw(pDC, 0, point, ILD_TRANSPARENT);
	TRACE("%d %d\n", width, height);
	return TRUE;
}

BOOL CMyBomb::LoadImages()
{
	CCommonFun::LoadImageW(m_Images, IDB_MyBalls, RGB(0, 0, 0), 18);
	return 0;
}
BOOL CMyBomb::Initial()
{
	//18   150*8=1200
	//30 150
  	CCommonFun::GetImageListInfo(m_Images, width, height);
	height = 60;
	return 0;
}