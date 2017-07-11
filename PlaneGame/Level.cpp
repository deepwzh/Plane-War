#include "stdafx.h"
#include "Level.h"
CLevel::CLevel(int index)
{
	config = new CGameConfig(L"data.json");
	levelInfo = config->GetLevelConfig(index);
}

CLevel::~CLevel()
{
	delete config;
}
