#include "stdafx.h"
#include "DataModel.h"


CDataModel::CDataModel(CGameBoard * board): board(board)
{

}
void CDataModel::SetBoard(CGameBoard * board) {
	this->board = board;
}

CDataModel::~CDataModel()
{
}
