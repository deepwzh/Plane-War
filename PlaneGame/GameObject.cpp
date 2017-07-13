#include "stdafx.h"
#include "GameObject.h"
#include "GameManager.h"
CGameObject::CGameObject(CGameManager* manager, int x, int y, int attack_value) : point(x, y), manager(manager), attack_value(attack_value)
{
	height = 0;
	width = 0;
}

CGameObject::~CGameObject()
{
}
// ¼ÓÔØÍ¼Æ¬×ÊÔ´