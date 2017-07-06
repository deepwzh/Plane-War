#include "stdafx.h"
#include "Plane.h"
#include "resource.h"
#include "GameManager.h"

CPlane::CPlane(CGameManager* manager, int x, int y, int speed) : CGameObject(manager, x, y), speed(speed),bomb(manager)
{
	flood = 100;
	team = 0;
	id = 0;
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


BOOL CPlane::Collided() const
{
	return 0;
}

BOOL CPlane::draw(CDC* pDC)
{

	//TRACE("%d %d\n", width, height);
	m_Images.Draw(pDC, 0, point, ILD_TRANSPARENT);
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
	this->bomb.setPoint(CPoint(point));
	double offset = - 0.5 - 0.5/n;
	for (int i = 0; i < n; i++) {
		offset += (1.0 / n);
		CBomb* bomb1 = new CBomb(manager, bomb.getRect().left + 20 + n*20* offset, bomb.getRect().top,1,offset);
		bomb1->setPath(new CGamePathArc());
		manager->registerObject(L"Bomb", bomb1);
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