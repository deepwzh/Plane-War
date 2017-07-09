#include "stdafx.h"
#include "MyPlane.h"
#include "GameManager.h"
CMyPlane::CMyPlane(CGameManager* manager, int x, int y, int speed) : CPlane(manager, x, y, speed) {
	bomb = new CEnemyBomb(manager);
	
	blood = 300;
}
CImageList CMyPlane::m_Images;
BOOL CMyPlane::Collided(POSITION pos)
{
	if (!this->setHP(-5))
		return 1;
	return 0;
}

BOOL CMyPlane::draw(CDC* pDC)
{
	//TRACE("%d %d\n", width, height);
	m_Images.Draw(pDC, 0, point, ILD_TRANSPARENT);
	//blood
	bloodbar->updatePosition(point);
	bloodbar->draw(pDC,getHP());
	return TRUE;
}


// ·¢¶¯¹¥»÷
BOOL CMyPlane::attack(int n = 1)
{
	cnt++;
	if (cnt % 4 == 0) {
		cnt = 0;
		this->bomb->setPoint(CPoint(point));
		double offset = -0.5 - 0.5 / n;
		for (int i = 0; i < n; i++) {
			offset += (1.0 / n);
			CBomb* bomb1 = new CMyBomb(manager, bomb->getRect().left + 20 + offset * 50, bomb->getRect().top, 6, offset);
			bomb1->Initial();
			bomb1->setPath(new CGamePathArc());
			manager->registerObject(L"mineBomb", bomb1);
			CBomb* bomb2 = new CMyBomb(manager, bomb->getRect().left + 20 + offset * 50, bomb->getRect().top, -6, offset);
			bomb2->setPath(new CGamePathArc());
			manager->registerObject(L"mineBomb", bomb2);
		}
	}
	return 0;
}
BOOL CMyPlane::LoadImages()
{
	CCommonFun::LoadImage(m_Images, IDB_MyPlane, RGB(0, 0, 0), 1);
	return 0;
}
BOOL CMyPlane::Initial()
{
	CCommonFun::GetImageListInfo(m_Images, width, height);
	bloodbar = new CMyBloodBar(width, 5, point, 3);
	return 0;
}
CMyPlane::~CMyPlane()
{
}
