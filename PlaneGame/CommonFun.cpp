#include "stdafx.h"
#include "CommonFun.h"


BOOL CCommonFun::LoadImage(CImageList& imgList, UINT bmpID, COLORREF crMask, int nInitial)
{
	CBitmap bmp;
	if (!bmp.LoadBitmap(bmpID))
		return FALSE;
	BITMAP bmpinfo;
	bmp.GetBitmap(&bmpinfo);
	int width = bmpinfo.bmWidth;
	int height = bmpinfo.bmHeight;
	if (!imgList.Create(width, height, ILC_COLOR32 | ILC_MASK, nInitial, 0))
		return FALSE;
	imgList.Add(&bmp, crMask);

	return TRUE;
}


int CCommonFun::GetImageListInfo(const CImageList &m_Images, int& width, int& height)
{
	IMAGEINFO info;
	m_Images.GetImageInfo(0, &info);
	//TRACE("%d \n", m_Images.GetImageCount());
	CBitmap img;
	BITMAP bmpinfo;
	img.Attach(info.hbmImage);
	img.GetBitmap(&bmpinfo);
	width = bmpinfo.bmWidth;
	height = bmpinfo.bmHeight / 4;
	return 0;
}
