#pragma once
#include "GameFactory.h"

#include "MyPlane.h"
class CGameMyPlaneFactory :
	public CGameFactory
{
protected:
public:

	CGameMyPlaneFactory(CGameManager* manager, CLevel* level);
	virtual ~CGameMyPlaneFactory();

	// 通过 CGameFactory 继承
	virtual CGameObject * createObject(int x, int y) override;

	CGameObject * createObject(CGameObject * obj);

	// 通过 CGameFactory 继承
	virtual int getCount() override;
};

