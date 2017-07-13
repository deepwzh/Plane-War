#pragma once
#include "Level.h"
#include "SockConnect.h"
#include "DataModel.h"
#include "GameBoardDefault.h"
#include "CommonFun.h"
#include "GameObject.h"
#include "Plane.h"
#include "resource.h"
#include "EnemyPlane.h"
#include "MyPlane.h"
#include "GameMyPlaneFactory.h"
#include "GameEnemyFactory.h"
#include "GameExplosion.h"
#define enPlane 0
#define enBomb 1
#define minePlane 2
#define mineBomb 3
#define buff 4
#define explosion 5
using namespace Info;
class CGameManager
{
public:
	enum GameState {
		Start = 1,
		End = 2,
		Pause = 3,
		GodStart = 4
	};
protected:
	char buf[1024 + 1];
	CGameMyPlaneFactory* myplaneFactory;
	CGameEnemyFactory* enemyplaneFactory;
protected:
	int NN = 0;
	CDataModel* model;
	CGameBoard* board;
	CMyPlane * myPlane;
	CLevel *level;
	LevelInfo info;
	int is_god;
	GameState state;
	CObList* m_ObjList;
	int height;
	int width;
	int cnt;
public:
	bool is_ok() {

	}
	CLevel* getLevel() { return level; }
	LevelInfo getLevelInfo() { return info; }
	CGameManager(int width = 0, int height = 0);
	void InitConnect();
	void InitLevel(int index);
	void AI();
	void HandleKeyMap();
	// 判断是否在屏幕区域内
	int is_InRange(CGameObject* ob);
	void setRect(int width, int height);
	void registerObject(CString type, CGameObject* ob) {
		if(type == "enBomb")
			m_ObjList[enBomb].AddTail(ob);
		else if (type == "enPlane") {
			m_ObjList[enPlane].AddTail(ob);
		}
		else if (type == "mineBomb") {
			m_ObjList[mineBomb].AddTail(ob);
		}
		else if (type == "explosion") {
			m_ObjList[explosion].AddTail(ob);

		}
	}
	void removeObject(CString type, POSITION ob) {
		if (type == "enBomb")
			m_ObjList[enBomb].RemoveAt(ob);
		else if (type == "minePlane") {
			m_ObjList[minePlane].RemoveAt(ob);
		}
		else if (type == "enPlane")
			m_ObjList[enPlane].RemoveAt(ob);
		else if (type == "mineBomb")
			m_ObjList[mineBomb].RemoveAt(ob);
		else if (type == "explosion")
			m_ObjList[explosion].RemoveAt(ob);
	}
	CObList* getList() {
		return m_ObjList;
	}
	CSockConnect* aSocket;
	void draw(CDC *m_pMemDC);
	~CGameManager();
//	CPoint point;
public:
	CDataModel* getModel() { return model; }
	GameState getState();
	void setState(GameState state);

	int getHeight();
	int getWidth();
	int StartGame(bool is_god);
	bool PauseGame();
	void LevelUp();
	bool StopGame();
};
