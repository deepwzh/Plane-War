#include "stdafx.h"
#include "EnemyPlane.h"
#include "GameManager.h"
CImageList CEnemyPlane::m_Images;
CEnemyPlane::CEnemyPlane(CGameManager* manager, int x, int y, int speed): CPlane(manager,x,y, speed)
{
	this->bomb = new CEnemyBomb(manager);

}
BOOL CEnemyPlane::draw(CDC* pDC)
{
	point.y += speed;
	//TRACE("%d %d\n", width, height);
	CBrush wbrush(RGB(255, 255, 255));
	CBrush * bold = pDC->SelectObject(&wbrush);
	pDC->Rectangle(this->getRect().left , this->getRect().top, this->getRect().right, this->getRect().top + 5);
	CBrush brush(RGB(255, 0, 0));
	pDC->SelectObject(&brush);
	pDC->Rectangle(this->getRect().left , this->getRect().top, this->getRect().left + 1.0*getHP() / 100 * (width), this->getRect().top + 5);
	pDC->SelectObject(&bold);
	m_Images.Draw(pDC, 0, point, ILD_TRANSPARENT);

	return TRUE;
}
BOOL CEnemyPlane::Collided(POSITION pos)
{
	if (!this->setHP(-50)) {
		manager->removeObject(L"enPlane", pos);
		return 1;
	}
	return 0;
	
}
BOOL CEnemyPlane::attack(int n = 1)
{
	cnt++;
	if (cnt % 30 == 0) {
		cnt = 0;
		this->bomb->setPoint(CPoint(point));
		double offset = -0.5 - 0.5 / n;
		for (int i = 0; i < n; i++) {
			offset += (1.0 / n);
			CBomb* bomb1 = new CEnemyBomb(manager, bomb->getRect().left + 20, bomb->getRect().top, 20, offset);
			bomb1->Initial();
			bomb1->setPath(new CGameEnemyPath());
			manager->registerObject(L"enBomb", bomb1);
		}
	}
	return 0;
}
BOOL CEnemyPlane::LoadImages()
{
	CCommonFun::LoadImage(m_Images, IDB_Enemy, RGB(0, 0, 0), 2);
	return 0;
}
CEnemyPlane::~CEnemyPlane()
{
}
BOOL CEnemyPlane::Initial()
{
	CCommonFun::GetImageListInfo(m_Images, width, height);
	return 0;
}