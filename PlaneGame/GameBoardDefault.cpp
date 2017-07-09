#include "stdafx.h"
#include "GameBoardDefault.h"

CGameBoardDefault::CGameBoardDefault(CPoint point, int width, int height): CGameBoard(point,width,height)

{

}


CGameBoardDefault::~CGameBoardDefault()
{
}

void CGameBoardDefault::draw(CDC * pDC)
{
	pDC->SetTextColor(RGB(255, 255, 255));
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->TextOutW(point.x, point.y, L"HELLO", 5);

}

void CGameBoardDefault::update(int n, ...) {
	va_list pvar;
	va_start(pvar, n);
	int t = va_arg(pvar, int);
	va_end(pvar);
}