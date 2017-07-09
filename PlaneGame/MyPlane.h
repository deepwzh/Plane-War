#pragma once
#include "Plane.h"
#include "MyBloodBar.h"
#include "resource.h"
class CMyPlane :
	public CPlane
{
protected:
	static CImageList m_Images;
public:
	CMyPlane(CGameManager * manager, int x = 0, int y = 0, int speed = 6);
	virtual BOOL Collided(POSITION pos);
	virtual BOOL draw(CDC * pDC);
	virtual BOOL attack(int n);
	static BOOL LoadImages();
	BOOL Initial();
	virtual ~CMyPlane();
};

