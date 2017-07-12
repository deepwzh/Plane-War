#include "stdafx.h"
#include "MyPlane.h"
#include "GameManager.h"
CMyPlane::CMyPlane(CGameManager* manager, int x, int y, int speed, int blood, int attack_value) : CPlane(manager, attack_value, x, y, speed, blood) {
	this->attack_value = attack_value;
}
CImageList CMyPlane::m_Images;
BOOL CMyPlane::Collided(POSITION pos, CGameObject* obj)
{
	if (obj == NULL) return 1;
	if (!this->setHP(-obj->get_attack()))
		return 1;
	return 0;
}
BOOL CMyPlane::draw(CDC* pDC)
{
	//TRACE("%d %d\n", width, height);
	m_Images.Draw(pDC, index, point, ILD_TRANSPARENT);
	//blood
	bloodbar->updatePosition(point);
	bloodbar->draw(pDC, getHP());
	return TRUE;
}
// ·¢¶¯¹¥»÷
BOOL CMyPlane::attack(int n = 1)
{
	cnt++;
	if (cnt % 4 == 0) {
		cnt = 0;
		double offset = -0.5 - 0.5 / n;
		for (int i = 0; i < n; i++) {
			offset += (1.0 / n);
			
			CBomb* bomb1 = (CMyBomb*)fact->createObject(int(point.x + 20 + offset * 50), point.y, offset );
			bomb1->setPath(new CGamePathArc());
			manager->registerObject(L"mineBomb", bomb1);
			//CBomb* bomb2 = (CMyBomb*)fact->createObject(bomb->getRect().left + 20 + offset * 50, bomb->getRect().top, offset);
			//bomb2->setPath(new CGamePathArc());
			//manager->registerObject(L"mineBomb", bomb2);
		}
	}
	return 0;
}
BOOL CMyPlane::LoadImages()
{
	CCommonFun::LoadImage(m_Images, IDB_MyPlanes, RGB(0, 0, 0), 4);
	return 0;
}
BOOL CMyPlane::Initial()
{
	CCommonFun::GetImageListInfo(m_Images, width, height);
	height /= 2;
	bloodbar = new CMyBloodBar(width, 5, point, 3);
	fact = new CGameMyBombFactory(manager, manager->getLevel(), index);

	return 0;
}
CMyPlane::~CMyPlane()
{
}

BOOL CMyPlane::switch_bomb()
{
	fact->switchObject();
	return 0;
}

BOOL CMyPlane::switch_nth_bomb()
{
	return 0;
}
