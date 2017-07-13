#pragma once
#include "SurroundInterface.h"
#include "GameObject.h"
#include "Resource.h"
class CGameExplosion :public CSurroundInterface, public CGameObject
{
protected:
	static CImageList m_Images;
public:
	CGameExplosion(CGameManager* manager, int, int);
	virtual ~CGameExplosion();

	// 通过 CSurroundInterface 继承
	virtual void updatePosition(CPoint newpoint) override;
	static BOOL LoadImages();
	// 通过 CGameObject 继承
	virtual BOOL Collided(POSITION pos, CGameObject * obj) override;
	virtual BOOL draw(CDC * pDC) override;
	virtual BOOL Initial() override;
};

