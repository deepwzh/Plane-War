#pragma once
#include "CommonFun.h"
class CGameManager;
class CGameObject : public CObject
{
public:
	CGameObject(CGameManager* manager, int, int);
	virtual ~CGameObject();
protected:
	CGameManager * manager;
	CPoint point;
	int height;
	int width;
public:
	// 获取对象的所在区域
	CRect getRect() const{
		return CRect(point, CPoint(point.x + width, point.y + height));
	}
	// 碰撞操作
	virtual BOOL Collided(POSITION pos) = 0;
	// 绘制对象
	virtual BOOL draw(CDC* pDC) = 0;
	// 初始化对象
	virtual BOOL Initial() = 0;

};

