#pragma once
#include "CommonFun.h"
class CGameManager;
class CGameObject : public CObject
{
public:
	CGameObject(CGameManager* manager, int, int, int);
	virtual ~CGameObject();
protected:
	int index;
	CGameManager * manager;
	CPoint point;
	int attack_value;
	int height;
	int width;
public:

	virtual int get_attack() {
		return attack_value;
	}
	// 获取对象的所在区域
	CRect getRect() const{
		return CRect(point, CPoint(point.x + width, point.y + height));
	}
	virtual void setIndex(int index) {
		this->index = index;
	}
	// 碰撞操作
	virtual BOOL Collided(POSITION pos, CGameObject *obj) = 0;
	// 绘制对象
	virtual BOOL draw(CDC* pDC) = 0;
	// 初始化对象
	virtual BOOL Initial() = 0;

};

