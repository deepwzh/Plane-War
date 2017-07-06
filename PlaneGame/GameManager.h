#pragma once
#include "CommonFun.h"
#include "GameObject.h"
#include "Plane.h"
#include "resource.h"

#define enPlane 0
#define enBomb 1
class CGameManager
{
public:
	CGameManager(int width = 0, int height = 0);
	void switchPlane();
	void HandleKeyMap();
	// 判断是否在屏幕区域内
	int is_InRange(CGameObject* ob);
	void setRect(int width, int height);
	void registerObject(CString type, CGameObject* ob) {
		if(type == "Bomb")
			m_ObjList[enBomb].AddTail(ob);
	}
	CObList* getList() {
		return m_ObjList;
	}
	void draw(CDC *m_pMemDC);
	~CGameManager();
protected:
	int shoot_mode;
	CObList* m_ObjList;
	int height;
	int width;
	CPlane * myPlane;
//	CPoint point;
public:
	int getHeight();
	int getWidth();
};
