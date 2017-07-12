#pragma once
#include "GameObject.h"
#include "GamePathArc.h"
#include "GamePathLine.h"
#include "GamePathDefault.h"
#include "Bomb.h"
#include "MyBomb.h"
#include "EnemyBomb.h"
#include "BloodBar.h"
class  CPlane :
	public CGameObject
{
public:
	CPlane(CGameManager* manager, int attack_value, int x = 0, int y = 0, int speed = 6, int blood = 300);
	virtual ~CPlane();
	virtual BOOL move(CCommonFun::Direction direct);
	// 通过 CGameObject 继承
	virtual BOOL Collided(POSITION pos, CGameObject* obj)  override = 0;
	// 通过 CGameObject 继承
	virtual BOOL draw(CDC* pDC) override = 0;
protected:
	int speed;
	bool is_fired;
	int blood;
	int team;
	int cnt;
	CBloodBar* bloodbar;
public:
	// 设置飞机所使用的炸弹
	virtual BOOL switch_bomb() = 0;
	virtual BOOL switch_nth_bomb() = 0;
protected:
public:
	// 发动攻击
	virtual BOOL attack(int n) = 0;
	// 通过 CGameObject 继承
	int getHP() const;
	bool setHP(int hp);
};