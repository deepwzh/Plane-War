#pragma once
#include "Plane.h"
#include "MyBloodBar.h"
#include "resource.h"
#include "GameMyBombFactory.h"
class CMyPlane :
	public CPlane
{
protected:
	int sleep_time;
	static CImageList m_Images;
	CGameMyBombFactory * fact;
public:
	//CMyPlane(CMyPlane * plane) {
	//	//this->attack_value = plane->attack_value;
	//	//this->blood = plane->blood;
	//	//this->bloodbar = plane->bloodbar;
	//	//this->cnt = plane->cnt;
	//	//this->fact = plane->fact;
	//	//this->cnt = plane->cnt;
	//	//this->fact = plane->fact;
	//	//this->height = plane->height;
	//	//this->height = plane->;
	//}
	bool is_sleep() {
		if (sleep_time > 0)
			return 0;
		else
		{
			sleep_time = 100;
			return 1;
		}
	}
	CMyPlane(CGameManager * manager, int x, int y, int speed, int blood, int attack_value);
	virtual BOOL Collided(POSITION pos, CGameObject* obj);
	virtual BOOL draw(CDC * pDC);
	virtual BOOL attack(int n);
	static BOOL LoadImages();
	BOOL Initial();
	virtual ~CMyPlane();

	// Í¨¹ý CPlane ¼Ì³Ð
	virtual BOOL switch_bomb() override;
	virtual BOOL switch_nth_bomb() override;
};

