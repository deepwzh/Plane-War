#include "stdafx.h"
#include "EnemyBomb.h"
#include "resource.h"
#include "GameManager.h"
#include "GameExplosion.h"

CImageList CEnemyBomb::m_Images;


CEnemyBomb::~CEnemyBomb()
{
}
BOOL CEnemyBomb::Initial()
{
	CCommonFun::GetImageListInfo(m_Images, width, height);
	return 0;
}
CEnemyBomb::CEnemyBomb(CGameManager* manager, int x, int y, int speed, double offset, int attack_value) : CBomb(manager,attack_value, x, y, speed, offset )
{
	cnt = 0;
}

BOOL CEnemyBomb::Collided(POSITION pos, CGameObject* obj)
{
	manager->registerObject(L"explosion", new CGameExplosion(manager, point.x, point.y + 50));
	manager->removeObject(L"enBomb", pos);
	return 1;
}
BOOL CEnemyBomb::draw(CDC * pDC)
{
	int x0 = 0, y0 = 0;
 	int x = point.x;
	int y = point.y;
	//TRACE("#####%lf\n", offset);
	path->getPosition(x0, y0, point0.x, point0.y, offset, speed);
	point.y -= y0;
	point.x += x0;
	m_Images.Draw(pDC, 0, point, ILD_TRANSPARENT);
	//TRACE("%d %d\n", width, height);
	return TRUE;
}

BOOL CEnemyBomb::LoadImages()
{
	CCommonFun::LoadImageW(m_Images,IDB_EnemyBombs , RGB(0, 0, 0), 5);
	return 0;
}
