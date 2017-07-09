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
	CEnemyPlane(CGameManager * manager, int x = 0, int y = 0, int speed = 6);
	virtual BOOL draw(CDC * pDC);
	virtual BOOL Collided(POSITION pos) override;
	virtual BOOL attack(int n);
	BOOL Initial();
	static BOOL LoadImages();
	~CEnemyPlane();
};

