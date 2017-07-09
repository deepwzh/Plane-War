#include "stdafx.h"
#include "MyBomb.h"
#include "resource.h"
#include "GameManager.h"

CImageList CMyBomb::m_Images;


CMyBomb::~CMyBomb()
{
}

CMyBomb::CMyBomb(CGameManager* manager, int x, int y, int speed, double offset) : CBomb(manager, x, y, speed, offset)
{
	cnt = 0;
}

BOOL CMyBomb::Collided(POSITION pos)
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
	CCommonFun::LoadImageW(m_Images, IDB_Bomb, RGB(0, 0, 0), 1);
	return 0;
}
BOOL CMyBomb::Initial()
{
	CCommonFun::GetImageListInfo(m_Images, width, height);
	return 0;
}