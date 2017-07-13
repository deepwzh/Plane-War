#include "stdafx.h"
#include "DataModel.h"


CDataModel::CDataModel()
{
	data.score = 0;
	data.HP = 0;
	data.MP = 0;
	data.mode = 0;
	data.level = 1;
	data.arms = 0;
	data.sleep_time = 0;
}
//void CDataModel::SetBoard(CGameBoard * board) {
//	this->board = board;
//}

CDataModel::~CDataModel()
{
}
