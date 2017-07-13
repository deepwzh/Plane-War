#include "stdafx.h"
#include "EnemyPlane.h"
#include "GameManager.h"
CImageList CEnemyPlane::m_Images;
CEnemyPlane::CEnemyPlane(CGameManager* manager, int x, int y, int speed, int blood, int attack_value): CPlane(manager, attack_value, x, y, speed, blood)
{
}

BOOL CEnemyPlane::draw(CDC* pDC)
{
	point.y += speed;
	//TRACE("%d %d\n", width, height);
	//CBrush wbrush(RGB(255, 255, 255));
	//CBrush * bold = pDC->SelectObject(&wbrush);
	//pDC->Rectangle(this->getRect().left , this->getRect().top, this->getRect().right, this->getRect().top + 5);
	//CBrush brush(RGB(255, 0, 0));
	//pDC->SelectObject(&brush);
	//pDC->Rectangle(this->getRect().left , this->getRect().top, this->getRect().left + 1.0*getHP() / 100 * (width), this->getRect().top + 5);
	//pDC->SelectObject(&bold);
	m_Images.Draw(pDC, index, point, ILD_TRANSPARENT);
	bloodbar->updatePosition(point);
	bloodbar->draw(pDC, getHP());

	return TRUE;
}
BOOL CEnemyPlane::Collided(POSITION pos, CGameObject* obj)
{
	if (obj == NULL) return 0;
	if (!this->setHP(-obj->get_attack())) {
		manager->removeObject(L"enPlane", pos);
		manager->getModel()->setScore(+this->attack_value*10);
		return 1;
	}
	return 0;
	
}
BOOL CEnemyPlane::attack(int n = 1)
{
	cnt++;
	if (cnt % 30 == 0) {
		cnt = 0;
		double offset = -0.5 - 0.5 / n;
		for (int i = 0; i < n; i++) {
			offset += (1.0 / n);
			CBomb* bomb1 = new CEnemyBomb(manager, point.x +50, point.y + 30, 20, offset,5);
			bomb1->Initial();
			bomb1->setPath(new CGameEnemyPath());
			manager->registerObject(L"enBomb", bomb1);
		}
	}
	return 0;
}
BOOL CEnemyPlane::LoadImages()
{
	
	CCommonFun::LoadImage(m_Images,IDB_Enemys , RGB(0, 0, 0), 5);
	return 0;
}
CEnemyPlane::~CEnemyPlane()
{
}
BOOL CEnemyPlane::switch_bomb()
{

	return 0;
}
BOOL CEnemyPlane::switch_nth_bomb()
{
	return 0;
}
BOOL CEnemyPlane::Initial()
{
	CCommonFun::GetImageListInfo(m_Images, width, height);
	height = 90;
	bloodbar = new CMyBloodBar(width, 5, point, 3);
	return 0;
}