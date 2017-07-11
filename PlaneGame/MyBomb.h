#pragma once
#include "Bomb.h"
class CMyBomb :
	public CBomb
{
protected:
	static CImageList m_Images;
public:
	virtual ~CMyBomb();
	CMyBomb(CGameManager * manager, int x, int y, int speed, double offset, int attack_value);
	virtual BOOL Collided(POSITION pos, CGameObject* obj);
	virtual BOOL draw(CDC * pDC);
	static BOOL LoadImages();
	BOOL Initial();
};

