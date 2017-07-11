#pragma once
#include "resource.h"
#include "Plane.h"
#include "GameEnemyPath.h"
class CEnemyPlane :
	public CPlane
{
protected:
	static CImageList m_Images;
public:
	CEnemyPlane::CEnemyPlane(CGameManager* manager, int x, int y, int speed, int blood, int attack_value);
	virtual BOOL draw(CDC * pDC);
	virtual BOOL Collided(POSITION pos, CGameObject* obj) override;
	virtual BOOL attack(int n);
	BOOL Initial(); 
	static BOOL LoadImages();
	~CEnemyPlane();

	// Í¨¹ý CPlane ¼Ì³Ð
	virtual BOOL switch_bomb() override;
	virtual BOOL switch_nth_bomb() override;
};

