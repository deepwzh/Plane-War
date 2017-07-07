#include "stdafx.h"
#include "EnemyPlane.h"
#include "GameManager.h"
CImageList CEnemyPlane::m_Images;
CEnemyPlane::CEnemyPlane(CGameManager* manager, int x, int y, int speed): CPlane(manager,x,y, speed)
{

}
BOOL CEnemyPlane::draw(CDC* pDC)
{
	point.y += speed;
	//TRACE("%d %d\n", width, height);
	m_Images.Draw(pDC, 0, point, ILD_TRANSPARENT);
	return TRUE;
}
BOOL CEnemyPlane::attack(int n = 1)
{
	this->bomb.setPoint(CPoint(point));
	double offset = -0.5 - 0.5 / n;
	for (int i = 0; i < n; i++) {
		offset += (1.0 / n);
		CBomb* bomb1 = new CBomb(manager, bomb.getRect().left + 20, bomb.getRect().top, 1, offset);
		bomb1->setPath(new CGameEnemyPath());
		manager->registerObject(L"Bomb", bomb1);
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