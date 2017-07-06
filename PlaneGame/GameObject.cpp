#include "stdafx.h"
#include "GameObject.h"
CGameObject::CGameObject(CGameManager* manager, int x, int y) : point(x, y), manager(manager)
{
	height = 0;
	width = 0;
}

CGameObject::~CGameObject()
{
}
// ╪стьм╪ф╛вйт╢





