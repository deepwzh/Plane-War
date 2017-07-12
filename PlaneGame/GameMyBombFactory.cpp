#include "stdafx.h"
#include "GameMyBombFactory.h"


CGameMyBombFactory::CGameMyBombFactory(CGameManager* manager, CLevel* level, int pindex) : CGameFactory(manager, level)
{
	pInfo = level->getMyPlaneInfo(pindex);
	index = 0; //index代表资源的序号，图片的序号
}

CGameMyBombFactory::~CGameMyBombFactory()
{
}

int CGameMyBombFactory::getCount()
{
	return pInfo.bombs.size();
}


CGameObject * CGameMyBombFactory::createObject(int x, int y,double offset)
{
	Info::BombInfo info = level->getBombInfo(pInfo.bombs[index]);
	CBomb * bomb = new CMyBomb(manager, x, y, info.speed, offset, info.attack);
	bomb->setIndex(pInfo.bombs[index]);
	bomb->Initial();
	return bomb;
}

CGameObject * CGameMyBombFactory::createObject(CGameObject * obj)
{
	CBomb * bomb = (CBomb*)obj;
	bomb->setIndex(index);
	return bomb;
}

