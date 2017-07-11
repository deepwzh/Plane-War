#pragma once
#include <fstream>
#include <vector>
#include "json\json.h"
namespace Info{
	struct BombInfo {
		int id;
		std::string Name;
		int speed;
		int attack;
		double Hitrate;
		std::vector<int> pathID;
	};
	struct BackgroundInfo {
		int speed;
		int BK_ID;
	};
	struct PlaneInfo {
		int id;
		int HP;
		int speed;
		int attack;
		std::vector<int> bombs;
	};
	struct PathInfo {
		int id;
		std::string Name;
	};
	struct LevelInfo {
		int level;
		BackgroundInfo backinfo;
		std::vector<int> myplaneID;
		std::vector<int> enemyIDs;
		std::vector<int> bossID;
	};
}
class CGameConfig
{
public:

protected:
	Json::Value root;
public:
	CGameConfig(CString file = L"data.json");
	Info::BackgroundInfo GetBackGroundConfig(const int & index);
	Info::PathInfo GetPathConfig(const int & index);
	Info::BombInfo GetBombConfig(const int & index);
	Info::PlaneInfo GetPlaneConfig(const int & index);
	Info::PlaneInfo GetEnemyConfig(const int & index);
	Info::PlaneInfo GetBossConfig(const int & index);
	Info::LevelInfo GetLevelConfig(int index);
	~CGameConfig();
};