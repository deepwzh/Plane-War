#pragma once
#include "CommonFun.h"
#include "GameObject.h"
#include "Plane.h"
#include "resource.h"
#include "EnemyPlane.h"
#define enPlane 0
#define enBomb 1
class CGameManager
{
public:
	CGameManager(int width = 0, int height = 0);
	enum GameState {
		Start = 1,
		End = 2,
		Pause = 3,
		GodStart = 4

	};
	void AI();
	void switchPlane();
	void HandleKeyMap();
	// 判断是否在屏幕区域内
	int is_InRange(CGameObject* ob);
	void setRect(int width, int height);
	void registerObject(CString type, CGameObject* ob) {
		if(type == "Bomb")
			m_ObjList[enBomb].AddTail(ob);
		else if (type == "Plane") {
			m_ObjList[enPlane].AddTail(ob);
		}
	}
	void removeObject(CString type, POSITION ob) {
		if (type == "Bomb")
			m_ObjList[enBomb].RemoveAt(ob);
		else if (type == "Plane") {
			m_ObjList[enPlane].RemoveAt(ob);
		}
	}
	CObList* getList() {
		return m_ObjList;
	}
	void draw(CDC *m_pMemDC);
	~CGameManager();
protected:
	int is_god;
	GameState state;
	int shoot_mode;
	CObList* m_ObjList;
	int height;
	int width;
	int cnt;
	CPlane * myPlane;
//	CPoint point;
public:
	GameState getState();
	void setState(GameState state);
	int getHeight();
	int getWidth();
	int StartGame(bool is_god);
	bool PauseGame();
	bool StopGame();
};
