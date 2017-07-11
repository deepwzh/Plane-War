#pragma once
#include "GameFactory.h"
class CGameEnemyFactory :
	public CGameFactory
{
public:
	CGameEnemyFactory(CGameManager* manager, CLevel* level);
	virtual ~CGameEnemyFactory();

	virtual int getCount();

	// Í¨¹ý CGameFactory ¼Ì³Ð
	virtual int switchObject() override;
	virtual int switchNthObject(int index) override;
	virtual CGameObject * createObject(int x, int y) override;
};

