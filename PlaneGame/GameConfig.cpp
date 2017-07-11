#include "stdafx.h"
#include "GameConfig.h"

CGameConfig::CGameConfig(CString file)
{
	std::ifstream config_doc(file, std::ifstream::binary);
	config_doc >> root;
}
//读取背景配置
Info::BackgroundInfo CGameConfig::GetBackGroundConfig(const int& index ) {
	Json::Value v = root["Backgrounds"];
	ASSERT(index <= v.size());
	Info::BackgroundInfo info;
	info.speed = v["speed"].asInt();
	info.BK_ID = v["BK_ID"].asInt();
	return info;
}
//读取路径配置
Info::PathInfo CGameConfig::GetPathConfig(const int& index) {
	Json::Value v = root["Paths"];
	ASSERT(index <= v.size());
	v = v[index];
	Info::PathInfo info;
	info.id = v["id"].asInt();
	info.Name = v["Name"].asString();
	return info;
}
//读取炸弹配置
Info::BombInfo  CGameConfig::GetBombConfig(const int& index) {
	Json::Value v = root["Bombs"];
	ASSERT(index <= v.size());
	Info::BombInfo info;
	v = v[index];

	info.id = v["id"].asInt();
	info.Name = v["Name"].asString();
	info.speed = v["speed"].asInt();
	info.attack = v["attack"].asInt();
	info.Hitrate = v["Hitrate"].asDouble();
	Json::Value idinfo = v["pathID"];
	for (int i = 0; i < idinfo.size();i++)
		info.pathID.push_back(idinfo[i].asInt());
	return info;
}
//读取飞机配置
Info::PlaneInfo  CGameConfig::GetPlaneConfig(const int& index) {
	Json::Value v = root["MyPlanes"];
	ASSERT(index <= v.size());
	v = v[index];
	Info::PlaneInfo info;
	info.id = v["id"].asInt();
	info.HP = v["HP"].asInt();
	info.speed = v["speed"].asInt();
	info.attack = v["attack"].asInt();
	Json::Value b = v["Bombs"];
	for (int i = 0; i < b.size(); i++) {
		info.bombs.push_back(b[i].asInt());
	}
	return info;
}
//读取敌机配置
Info::PlaneInfo  CGameConfig::GetEnemyConfig(const int& index) {
	Json::Value v = root["Enemys"];
	ASSERT(index <= v.size());
	v = v[index];
	Info::PlaneInfo info;
	info.id = v["id"].asInt();
	info.HP = v["HP"].asInt();
	info.speed = v["speed"].asInt();
	info.attack = v["attack"].asInt();
	Json::Value b = v["Bombs"];
	for (int i = 0; i < b.size(); i++) {
		info.bombs.push_back(b[i].asInt());
	}
	return info;
}
//读取BOSS配置，index从1开始
Info::PlaneInfo  CGameConfig::GetBossConfig(const int& index) {
	Json::Value v = root["Bosses"];
	ASSERT(index <= v.size());
	v = v[index];
	Info::PlaneInfo info;
	info.id = v["id"].asInt();
	info.HP = v["HP"].asInt();
	info.speed = v["speed"].asInt();
	info.attack = v["attack"].asInt();
	Json::Value b = v["Bombs"];
	for (int i = 0; i < b.size(); i++) {
		info.bombs.push_back(b[i].asInt());
	}
	return info;
}

//读取等级配置
Info::LevelInfo CGameConfig::GetLevelConfig(int index)
{
	Json::Value levels = root["Levels"]; //读取等级配置数组
	ASSERT(index - 1 <= levels.size());
	Json::Value &level = levels[index - 1];
	Info::LevelInfo info;
	info.backinfo = GetBackGroundConfig(level["Background"].asInt());
	Json::Value a = level["MyPlaneID"];
	for (int i = 0; i < a.size(); i++) {
		info.myplaneID.push_back(a[i].asInt());
	}
	Json::Value b = level["EnemysID"];
	for (int i = 0; i < b.size(); i++) {
		info.enemyIDs.push_back(b[i].asInt());
	}
	Json::Value bosses = level["BossID"];
	for (int i = 0; i < bosses.size(); i++) {
		info.bossID.push_back(bosses[i].asInt());
		return info;
	}
	return info;
}


CGameConfig::~CGameConfig()
{

}
