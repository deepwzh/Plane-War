#pragma once
#include <stdarg.h>
using namespace std;
class CGameBoard
{
public:
	CGameBoard(CPoint point, int width, int height);
	virtual ~CGameBoard();
	// »æÖÆÓÎÏ·µÄ°ñ
	virtual void draw(CDC * pDC) = 0;
	virtual void update(int n, ...) = 0;
protected:
	CPoint point;
	int height;
	int width;
};

