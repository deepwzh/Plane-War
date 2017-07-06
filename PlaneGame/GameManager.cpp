#include "stdafx.h"
#include "GameManager.h" 
CGameManager::CGameManager(int width , int height) : width(width), height(height)
{
	shoot_mode = 1;
	m_ObjList = new CObList[4];
	CPlane::LoadImages();
	CBomb::LoadImages();
	myPlane = new CPlane(this,width/2,height/2,6);
	//启动游戏
	myPlane->Initial();
}
void CGameManager::draw(CDC * m_pMemDC) {
	//TRACE("%d %d\n", game_manager->getWidth(), game_manager->getHeight());
	//m_pMemDC->FillSolidRect(0, 0, getWidth(), getHeight(), RGB(84, 142, 239));

	CBitmap   bitmap;

	bitmap.LoadBitmap(IDB_BG1);   //这个IDB_BITMAP1要自己添加

	CBrush   brush;
	
	brush.CreatePatternBrush(&bitmap);

	CBrush*   pOldBrush = m_pMemDC->SelectObject(&brush);

	m_pMemDC->Rectangle(0, 0, width, height);  // 这些参数可以调整图片添加位置和大小

	m_pMemDC->SelectObject(pOldBrush);


	//CClientDC pDC(this);
	myPlane->draw(m_pMemDC);
	if (!is_InRange(myPlane)) {
		//	//Out of range
	}

	POSITION mPos = NULL, _mPos = NULL;
	CObList* list = getList();
	for (mPos = list[enBomb].GetHeadPosition(); (_mPos = mPos) != NULL; ) {
		CBomb * pBomb = (CBomb*)list[enBomb].GetNext(mPos);
		//CRect brect = pBomb->getRect();
		if (is_InRange(pBomb)) {
			list[enBomb].RemoveAt(_mPos);
 			delete pBomb;
		}
		else
			pBomb->draw(m_pMemDC);
	}
}
void CGameManager::switchPlane() {
}

void CGameManager::HandleKeyMap()
{
	int dir = is_InRange(myPlane);
	if (GetKeyState(VK_LEFT) < 0) {
		if (!(dir & CCommonFun::L))
			myPlane->move(CCommonFun::L);
	}
	if (GetKeyState(VK_RIGHT) < 0) {
		if (!(dir & CCommonFun::R))
			myPlane->move(CCommonFun::R);
	}
	if (GetKeyState(VK_UP) < 0) {
		if (!(dir & CCommonFun::U))
			myPlane->move(CCommonFun::U);
	}
	if (GetKeyState(VK_DOWN) < 0) {
		if (!(dir & CCommonFun::D))
			myPlane->move(CCommonFun::D);
	}
	if (GetKeyState(VK_TAB) < 0) {
		switchPlane();
	}
	if (GetKeyState(VK_SPACE) < 0) {
		myPlane->attack(5);
	}
}
// 判断是否在屏幕区域内
int CGameManager::is_InRange(CGameObject* ob)
{
	int res = 0;
	CRect& rect = ob->getRect();
	if (rect.right > width) res |= CCommonFun::R;
	if (rect.left < 0)res |= CCommonFun::L;
	if (rect.top < 0)res |= CCommonFun::U;
	if (rect.bottom > height)res |= CCommonFun::D;
	return res;
}

void CGameManager::setRect(int w, int h)
{
	width = w;
	height = h;
}

CGameManager::~CGameManager()
{
}


int CGameManager::getHeight()
{
	return height;
}


int CGameManager::getWidth()
{
	return width;
}
