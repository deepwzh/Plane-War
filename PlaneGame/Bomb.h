#pragma once
#include "GameObject.h"
#include "GamePath.h"
class CBomb :
	public CGameObject
{
protected:
	CPoint point0;
	static CImageList m_Images;
	int speed;
	CGamePath* path;
public:
	CBomb(CGameManager* manager, int x = 0, int y = 0, int speed = 6, double offset = 0);
	virtual ~CBomb();
	BOOL setPoint(CPoint point);
	// 通过 CGameObject 继承
	virtual BOOL Collided() const override;
	virtual BOOL draw(CDC * pDC) override;
	void setPath(CGamePath* path) {
		if (this->path != NULL)
			delete path;
		this->path = path;

	}
	virtual void getPath(int& x, int& y, const int& s);
	// 通过 CGameObject 继承
	 static BOOL LoadImages();

	 // 通过 CGameObject 继承
	 virtual BOOL Initial() override;
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


