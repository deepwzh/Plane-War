#pragma once
#include "Level.h"

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
	void setLevel(CLevel * level);
	virtual int switchObject();
	virtual int switchNthObject(int index);
	virtual ~CGameFactory();
	virtual CGameObject* createObject(int x, int y) { return NULL; }
	virtual CGameObject* createObject(CGameObject *obj) = 0;
};

