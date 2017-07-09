#include "stdafx.h"
#include "Plane.h"
#include "resource.h"
#include "GameManager.h"

CPlane::CPlane(CGameManager* manager, int x, int y, int speed) : CGameObject(manager, x, y), speed(speed)
{

	blood = 100;
	team = 0;
	id = 0;
	cnt = 0;
}
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
// 设置飞机所使用的炸弹
BOOL CPlane::set_bomb(CBomb * bomb)
{
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
	if (blood <= 0) {
		blood = 0;
		return false;
	}
	return true;
}

