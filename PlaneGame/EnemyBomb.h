#pragma once
#include "Bomb.h"
class CEnemyBomb :
	public CBomb
{
protected:
	static CImageList m_Images;
public:
	virtual ~CEnemyBomb();
	BOOL Initial();
	CEnemyBomb(CGameManager * manager, int x = 0, int y = 0, int speed = 6, double offset = 0);
	virtual BOOL Collided(POSITION pos);
	virtual BOOL draw(CDC * pDC);
	static BOOL LoadImages();
};

