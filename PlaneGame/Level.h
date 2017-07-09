#pragma once
#include "resource.h"
#include "CommonFun.h"
#include <map>

class CLevel
{
protected:
	int level;
	int myplane_speed;
	int enmey_speed;
	int bomb_speed;
	int scroll_speed;
	int BK_ID;
	std::map<CString, int> score_list; //得分列表
	std::map<CString, int> damage_list; //伤害列表
public:
	int getMyplaneSpeed() {
		return myplane_speed;
	}
	int getEnmeySpeed() {
		return enmey_speed;
	}
	int getBombSpeed() {
		return bomb_speed;
	}
	int getScrollSpeed() {
		return scroll_speed;
	}
	virtual int getLevelName() {
		return level;
	}
	CLevel();
	virtual ~CLevel();
};

