#include "stdafx.h"
#include "MyBloodBar.h"

CMyBloodBar::CMyBloodBar(int width, int height, CPoint point, int life) : CBloodBar(width, height, point, life)
{

}
CMyBloodBar::~CMyBloodBar()
{
}

BOOL CMyBloodBar::draw(CDC * pDC,int hp)
{
	int remaind_life = hp / 100;
	CCommonFun::COLOR_RGB * rgb_d = new CCommonFun::COLOR_RGB(255,255,255);
	CCommonFun::COLOR_RGB * rgb_u = new CCommonFun::COLOR_RGB(0, 100, 50);
	if(remaind_life >= 1)
		CCommonFun::HSLtoRGB(new CCommonFun::COLOR_HSL(double(remaind_life - 1) / life * 128, 100, 50), rgb_d);
	CBrush wbrush(RGB(rgb_d->red, rgb_d->green, rgb_d->blue));
	CCommonFun::HSLtoRGB(new CCommonFun::COLOR_HSL(double(remaind_life) / life * 128, 100, 50), rgb_u);

	CBrush * bold = pDC->SelectObject(&wbrush);
	pDC->Rectangle(point.x, point.y, point.x + width, point.y + height);
	CBrush brush(RGB(rgb_u->red, rgb_u->green, rgb_u->blue));
	//CBrush brush(RGB(255, 0, 0));
	pDC->SelectObject(&brush);
	pDC->Rectangle(point.x, point.y,
		point.x + width *(hp%100) / 100, point.y + height);
	pDC->SelectObject(bold);
	//128,255,128
	//0,255,128
	return 0;
}
