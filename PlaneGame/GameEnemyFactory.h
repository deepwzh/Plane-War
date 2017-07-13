#pragma once
#include "GameFactory.h"
#include "EnemyPlane.h"
class CGameEnemyFactory :
	public CGameFactory
{
public:
	CGameEnemyFactory(CGameManager* manager, CLevel* level);
	virtual ~CGameEnemyFactory();
	virtual int getCount();

	virtual CGameObject * createObject(int x, int y) override;

	// Í¨¹ý CGameFactory ¼Ì³Ð
	virtual CGameObject * createObject(CGameObject * obj) override;
};

