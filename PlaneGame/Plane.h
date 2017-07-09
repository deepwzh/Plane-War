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
	CPlane(CGameManager* manager, int x = 0, int y = 0, int speed = 6);
	virtual ~CPlane();
	virtual BOOL move(CCommonFun::Direction direct);

	// 通过 CGameObject 继承
	virtual BOOL Collided(POSITION pos)  override = 0;
	// 通过 CGameObject 继承
	virtual BOOL draw(CDC* pDC) override = 0;
protected:
	int speed;
	bool is_fired;
	int blood;
	int team;
	int id;
	int cnt;
	CBloodBar* bloodbar;
public:
	// 设置飞机所使用的炸弹
	virtual BOOL set_bomb(CBomb* bomb);
protected:
	CBomb* bomb;
public:
	// 发动攻击
	virtual BOOL attack(int n) = 0;
	// 通过 CGameObject 继承
	int getHP() const;
	bool setHP(int hp);

};

