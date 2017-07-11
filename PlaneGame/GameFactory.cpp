#include "stdafx.h"
#include "GameFactory.h"

CGameFactory::CGameFactory(CGameManager* manager, const CLevel* level) : level(level),manager(manager)
{
	index = 0;
}

CGameFactory::~CGameFactory()
{
}
