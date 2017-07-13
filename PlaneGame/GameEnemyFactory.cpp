#include "stdafx.h"
#include "GameEnemyFactory.h"


CGameEnemyFactory::CGameEnemyFactory(CGameManager* manager, CLevel* level) : CGameFactory(manager, level)
{
	index = 0;
}
CGameEnemyFactory::~CGameEnemyFactory()
{
}
int CGameEnemyFactory::getCount()
{
	return level->getLevelInfo().enemyIDs.size();
}

CGameObject * CGameEnemyFactory::createObject(int x, int y)
{
	if (index >= getCount())index = 0;
	LevelInfo lInfo = level->getLevelInfo();
	Info::PlaneInfo info = level->getEnemyInfo(lInfo.enemyIDs[index]);
	CEnemyPlane * plane = new CEnemyPlane(manager, x, y, info.speed, info.HP, info.attack);
	plane->setIndex(lInfo.enemyIDs[index]);
	plane->Initial();
	return plane;
}

CGameObject * CGameEnemyFactory::createObject(CGameObject * obj)
{
	if (index >= getCount())index = 0;
	LevelInfo lInfo = level->getLevelInfo();
	CEnemyPlane * plane = (CEnemyPlane*)obj;
	plane->setIndex(lInfo.enemyIDs[index]);
	return plane;
}
