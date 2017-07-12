#pragma once
#include "GameFactory.h"

#include "MyBomb.h"
class CGameMyBombFactory :
	public CGameFactory
{
protected:
	PlaneInfo pInfo;
public:
	CGameMyBombFactory(CGameManager* manager, CLevel* level, int pindex);
	virtual ~CGameMyBombFactory();
	virtual int getCount();
	virtual CGameObject * createObject(int x, int y, double offset = 0);
	virtual CGameObject * createObject(CGameObject * obj);
};

