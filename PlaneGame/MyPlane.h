#pragma once
#include "Plane.h"
#include "MyBloodBar.h"
#include "resource.h"
#include "GameMyBombFactory.h"
class CMyPlane :
	public CPlane
{
protected:
	static CImageList m_Images;
	CGameMyBombFactory * fact;
public:
	CMyPlane(CGameManager * manager, int x, int y, int speed, int blood, int attack_value);
	virtual BOOL Collided(POSITION pos, CGameObject* obj);
	virtual BOOL draw(CDC * pDC);
	virtual BOOL attack(int n);
	static BOOL LoadImages();
	BOOL Initial();
	virtual ~CMyPlane();

	// Í¨¹ý CPlane ¼Ì³Ð
	virtual BOOL switch_bomb() override;
	virtual BOOL switch_nth_bomb() override;
};

