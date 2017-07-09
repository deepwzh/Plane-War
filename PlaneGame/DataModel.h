#pragma once
#include "GameBoard.h"
class CDataModel
{
protected:
	CGameBoard* board;
	int score;
	int HP;
public:
	int getScore() { return score; }
	void updateScore(int score) { this->score =  score; }
	int getHP() { return HP; }
	void updateHP(int delta) { this->HP = HP; }
	virtual void push() {
		board->update(2, getHP(), getScore());
	}
	CDataModel(CGameBoard * board);
	void SetBoard(CGameBoard * board);
	virtual ~CDataModel();
};

