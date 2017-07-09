#pragma once
#include "Bomb.h"
class CMyBomb :
	public CBomb
{
protected:
	static CImageList m_Images;
public:
	virtual ~CMyBomb();
	CMyBomb(CGameManager * manager, int x = 0, int y = 0, int speed = 6, double offset = 0);
	virtual BOOL Collided(POSITION pos);
	virtual BOOL draw(CDC * pDC);
	static BOOL LoadImages();
	BOOL Initial();
};

