#pragma once
#include "GameObject.h"
class CCommonFun
{
public:
	enum Direction
	{
		U = 1,
		D = 2,
		L = 4,
		R = 8,
		None = 0
	};
	static BOOL CCommonFun::LoadImage(CImageList& imgList, UINT bmpID, COLORREF crMask, int nInitial);
	static int GetImageListInfo(const CImageList &m_Images, int& width, int& height);
};