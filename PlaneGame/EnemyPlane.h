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
	BOOL draw(CDC * pDC);
	BOOL attack(int n);
	BOOL Initial();
	static BOOL LoadImages();
	~CEnemyPlane();
};

