#include "stdafx.h"
#include "GameBoard.h"


CGameBoard::CGameBoard(CDataModel* model, CPoint point, int width, int height)
{
	this->model = model;

	height = 0;
	width = 0;
}


CGameBoard::~CGameBoard()
{
}
