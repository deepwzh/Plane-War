#include "stdafx.h"
#include "GameMyPlaneFactory.h"
CGameMyPlaneFactory::CGameMyPlaneFactory(CGameManager* manager, CLevel* level) : CGameFactory(manager,level)
{
	//level->getBombInfo(0);
}

CGameMyPlaneFactory::~CGameMyPlaneFactory()
{
}

CGameObject * CGameMyPlaneFactory::createObject(CGameObject * obj)
{
	Info::LevelInfo lInfo = level->getLevelInfo();
	CPlane* plane = (CMyPlane*)obj;
	plane->setIndex(lInfo.myplaneID[index]);
	return plane;
}
int CGameMyPlaneFactory::getCount()
{
	return level->getLevelInfo().myplaneID.size();
}
CGameObject * CGameMyPlaneFactory::createObject(int x, int y)
{
	Info::LevelInfo lInfo = level->getLevelInfo();
	Info::PlaneInfo info = level->getMyPlaneInfo(lInfo.myplaneID[index]);
	CPlane * plane = new CMyPlane(manager, x, y, info.speed,info.HP, info.attack);
	plane->setIndex(lInfo.myplaneID[index]);
	plane->Initial();
	return plane;
}
