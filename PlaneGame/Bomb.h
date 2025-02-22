#pragma once
#include "GameObject.h"
#include "GamePath.h"
class CBomb :
	public CGameObject
{
protected:
	int cnt;
	CPoint point0;
	static CImageList m_Images;
	int speed;
	CGamePath* path;
public:
	CBomb(CGameManager* manager, int attack_value, int x = 0, int y = 0, int speed = 6, double offset = 0);
	virtual ~CBomb();
	BOOL setPoint(CPoint point);
	BOOL Collided(POSITION pos, CGameObject* obj) = 0 ;
	// 通过 CGameObject 继承
	virtual BOOL draw(CDC * pDC) = 0;
	void setPath(CGamePath* path) {
		if (this->path != NULL)
			delete path;
		this->path = path;

	}
	virtual void getPath(int& x, int& y, const int& s);

	 // 通过 CGameObject 继承
	 virtual BOOL Initial() override = 0;
protected:
	double offset;
public:
	// 获取该炸弹的偏移度,用于改变炸弹轨迹
	double getOffset() {
		return offset;
	}

	void setOffset(double offset)
	{
		this->offset = offset;
	}
};


