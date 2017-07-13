#pragma once
#include "Bomb.h"
class GameExplosion;
class CEnemyBomb :
	public CBomb
{
protected:
	static CImageList m_Images;
public:
	virtual ~CEnemyBomb();
	BOOL Initial();
	CEnemyBomb(CGameManager * manager, int x, int y, int speed, double offset, int attack_value);
	virtual BOOL Collided(POSITION pos, CGameObject* obj);
	virtual BOOL draw(CDC * pDC);
	static BOOL LoadImages();
};

