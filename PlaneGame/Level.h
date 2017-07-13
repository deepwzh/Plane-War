#pragma once
#include "resource.h"
#include "CommonFun.h"
#include <map>
#include "GameConfig.h"
using Info::LevelInfo;
using Info::BombInfo;
using Info::PlaneInfo;

class CLevel
{
public:
protected:
	CGameConfig* config;
	LevelInfo levelInfo;
	std::map<CString, int> score_list; //µÃ·Ö
	std::map<CString, int> damage_list; //ÉËº¦
public:
	int getMaxLevel() const {
		return config->level_max;
	}
	int isLevelUp(int score)const {
		return levelInfo.level < getMaxLevel() &&  score >= config->GetLevelConfig(levelInfo.level).Score;
	}
	Info::LevelInfo getLevelInfo()const {
		return levelInfo;
	}
	Info::BackgroundInfo getBackGroundInfo()const {
		return levelInfo.backinfo;
	}
	Info::PathInfo getPathInfo(int i)const {
		return config->GetPathConfig(i);
	}
	Info::BombInfo getBombInfo(int i) const {
		return config->GetBombConfig(i);
	}
	Info::PlaneInfo getMyPlaneInfo(int i) const {
		return config->GetPlaneConfig(i);
	}
	Info::PlaneInfo getEnemyInfo(int i) const {
		return config->GetEnemyConfig(i);
	}
	Info::PlaneInfo getBossInfo(int i) const {
		return config->GetBossConfig(i);
	}
	CLevel(int level);
	virtual ~CLevel();
};

