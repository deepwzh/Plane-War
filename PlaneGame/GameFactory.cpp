#include "stdafx.h"
#include "GameFactory.h"

CGameFactory::CGameFactory(CGameManager* manager, const CLevel* level) : level(level),manager(manager)
{
	index = 0;
}
int CGameFactory::switchObject() {
	this->index++;
	index %= getCount();
	return index;
}
int CGameFactory::switchNthObject(int index) {
	if (index > getCount())return -1;
	this->index = index;
	return index;
}
CGameFactory::~CGameFactory()
{
}
