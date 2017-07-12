#pragma once
#include "GameBoard.h"
class CGameBoardDefault :
	public CGameBoard
{
public:
	CGameBoardDefault(CDataModel* model, CPoint point, int width, int height);
	virtual ~CGameBoardDefault();
	virtual void setModel(CDataModel * model) { this->model = model; }
	// Í¨¹ý CGameBoard ¼Ì³Ð
	virtual void draw(CDC * pDC) override;
	// virtual void update(int n, ...) override;
};

