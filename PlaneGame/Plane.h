#pragma once
#include "GameObject.h"
#include "BombRight.h"
#include "GamePathArc.h"
#include "GamePathLine.h"
class  CPlane :
	public CGameObject
{
public:
	CPlane(CGameManager* manager, int x = 0, int y = 0, int speed = 6);
	virtual ~CPlane();
	virtual BOOL move(CCommonFun::Direction direct);

	// 通过 CGameObject 继承
	virtual BOOL Collided() const override;
	// 通过 CGameObject 继承
	virtual BOOL draw(CDC* pDC) override;
protected:
	static CImageList m_Images;
	int speed;
	bool is_fired;
	int flood;
	int team;
	int id;


public:
	// 设置飞机所使用的炸弹
	virtual BOOL set_bomb(CBomb bomb);
protected:
	CBomb bomb;
public:
	// 发动攻击
	virtual BOOL attack();
	virtual BOOL attack(int n);

	// 通过 CGameObject 继承
	static  BOOL LoadImages();

	// 通过 CGameObject 继承
	virtual BOOL Initial() override;
};

