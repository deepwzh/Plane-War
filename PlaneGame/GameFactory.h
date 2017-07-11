#pragma once
#include "Level.h"
#include "EnemyBomb.h"
#include "EnemyPlane.h"
#include "MyPlane.h"
#include "MyBomb.h"
using namespace Info;
class CGameFactory
{
protected:
	int index;
	CGameManager* manager;
	const CLevel * level;
public:
	virtual int getCount() = 0;
	CGameFactory(CGameManager* manager, const CLevel* level);
	virtual int switchObject() = 0;
	virtual int switchNthObject(int index) = 0;
	virtual ~CGameFactory();
	virtual CGameObject* createObject(int x, int y) = 0;
};

