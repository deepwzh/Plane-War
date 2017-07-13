#include "stdafx.h"
#include "GameExplosion.h"
#include "GameManager.h"
CImageList CGameExplosion::m_Images;

CGameExplosion::CGameExplosion(CGameManager* manager, int x, int y) : CGameObject(manager,x,y,0)
{
	index = 0;
}

CGameExplosion::~CGameExplosion()
{
}

void CGameExplosion::updatePosition(CPoint newpoint)
{

}
BOOL CGameExplosion::LoadImages() {
	CCommonFun::LoadImage(m_Images, IDB_Explosions, RGB(0, 0, 0), 8);
	return 1;
}

BOOL CGameExplosion::Collided(POSITION pos, CGameObject * obj)
{
	return 0;
}

BOOL CGameExplosion::draw(CDC * pDC)
{
	if (index < 8) {
		index++;
		m_Images.Draw(pDC, index, point, ILD_TRANSPARENT);
		return 1;
	}
	return 0;
}

BOOL CGameExplosion::Initial()
{
	CCommonFun::GetImageListInfo(m_Images, width, height);
	return 0;
}
