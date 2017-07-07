#include "stdafx.h"
#include "Plane.h"
#include "resource.h"
#include "GameManager.h"

CPlane::CPlane(CGameManager* manager, int x, int y, int speed) : CGameObject(manager, x, y), speed(speed),bomb(manager)
{
	blood = 100;
	team = 0;
	id = 0;
	cnt = 0;
}
CImageList CPlane::m_Images;

BOOL CPlane::move(CCommonFun::Direction direct) {
	switch (direct)
	{
	case CCommonFun::U:
		point.y -= speed;
		break;
	case CCommonFun::D:
		point.y += speed;
		break;
	case CCommonFun::L:
		point.x -= speed;
		break;
	case CCommonFun::R:
		point.x += speed;
		break;
	default:
		break;
	}
	return TRUE;
}
CPlane::~CPlane()
{
	//注意内存泄漏
}


BOOL CPlane::Collided(POSITION pos) 
{
	if (pos) {
		manager->removeObject(L"Plane", pos);
	}
	this->setHP(-5);
	return 1;
}

BOOL CPlane::draw(CDC* pDC)
{

	//TRACE("%d %d\n", width, height);
	m_Images.Draw(pDC, 0, point, ILD_TRANSPARENT);
	CBrush brush(RGB(255, 0, 0));
	pDC->Rectangle(this->getRect().left + 7, this->getRect().top, this->getRect().right - 7, this->getRect().top + 5);
	CBrush * bold = pDC->SelectObject(&brush);
	pDC->Rectangle(this->getRect().left + 7, this->getRect().top, this->getRect().left + 7 + 1.0*getHP()/ 100 * (width - 14), this->getRect().top + 5);
	pDC->SelectObject(bold);
	return TRUE;
}

// 设置飞机所使用的炸弹
BOOL CPlane::set_bomb(CBomb bomb)
{

	return 0;
}


// 发动攻击
BOOL CPlane::attack()
{
	this->bomb.setPoint(CPoint(point));
	bomb.setPath(new CGamePathArc());
	//注意内存泄漏
	CBomb* bomb1 = new CBomb(manager, bomb.getRect().left, bomb.getRect().top);
	bomb1->setPath(new CGamePathArc());
	manager->registerObject(L"Bomb",bomb1);
	this->bomb.setPoint(CPoint(point.x+50,point.y));
	CBomb* bomb2 = new CBombRight(manager, bomb.getRect().left, bomb.getRect().top);
	bomb2->setPath(new CGamePathArc());
	manager->registerObject(L"Bomb",bomb2);
	TRACE("%d\n", manager->getHeight());
	return 0;
}

BOOL CPlane::attack(int n = 1)
{
	cnt++;
	if (cnt % 4 == 0) {
		cnt = 0;
		this->bomb.setPoint(CPoint(point));
		double offset = - 0.5 - 0.5/n;
		for (int i = 0; i < n; i++) {
			offset += (1.0 / n);
			CBomb* bomb1 = new CBomb(manager, bomb.getRect().left + 20 + offset*50, bomb.getRect().top, 6, offset);
			bomb1->Initial();
			bomb1->setPath(new CGamePathArc());
			manager->registerObject(L"Bomb", bomb1);
			CBomb* bomb2 = new CBomb(manager, bomb.getRect().left + 20 + offset * 50, bomb.getRect().top, -6, offset);
			bomb2->setPath(new CGamePathLine());
			manager->registerObject(L"Bomb", bomb2);
		}
	}

	return 0;
}

BOOL CPlane::LoadImages()
{
	CCommonFun::LoadImage(m_Images, IDB_MyPlane, RGB(0, 0, 0), 1);
	return 0;
}

BOOL CPlane::Initial()
{
	CCommonFun::GetImageListInfo(m_Images, width, height);
	return 0;
}

int CPlane::getHP() const
{
	return blood;
}

//当血量小于0，返回false;
bool CPlane::setHP(int hp)
{
	blood += hp;
	return blood > 0;
}

