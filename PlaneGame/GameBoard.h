#pragma once
#include <stdarg.h>
#include "DataModel.h"
using namespace std;
class CGameBoard
{
public:
	CGameBoard(CDataModel* model, CPoint point, int width, int height);
	virtual ~CGameBoard();
	// »æÖÆÓÎÏ·µÄ°ñ
	virtual void draw(CDC * pDC) = 0;
protected:
	CDataModel * model;
	CPoint point;
	int height;
	int width;
};

