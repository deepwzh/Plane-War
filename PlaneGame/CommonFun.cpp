#include "stdafx.h"
#include "CommonFun.h"


// Converts RGB to HSL  
void CCommonFun::RGBtoHSL(const COLOR_RGB *rgb, COLOR_HSL *hsl)
{
	float h = 0, s = 0, l = 0;
	// normalizes red-green-blue values  
	float r = rgb->red / 255.0f;
	float g = rgb->green / 255.0f;
	float b = rgb->blue / 255.0f;
	float maxVal = max3v(r, g, b);
	float minVal = min3v(r, g, b);

	// hue  
	if (maxVal == minVal)
	{
		h = 0; // undefined  
	}
	else if (maxVal == r && g >= b)
	{
		h = 60.0f*(g - b) / (maxVal - minVal);
	}
	else if (maxVal == r && g<b)
	{
		h = 60.0f*(g - b) / (maxVal - minVal) + 360.0f;
	}
	else if (maxVal == g)
	{
		h = 60.0f*(b - r) / (maxVal - minVal) + 120.0f;
	}
	else if (maxVal == b)
	{
		h = 60.0f*(r - g) / (maxVal - minVal) + 240.0f;
	}

	// luminance  
	l = (maxVal + minVal) / 2.0f;

	// saturation  
	if (l == 0 || maxVal == minVal)
	{
		s = 0;
	}
	else if (0<l && l <= 0.5f)
	{
		s = (maxVal - minVal) / (maxVal + minVal);
	}
	else if (l>0.5f)
	{
		s = (maxVal - minVal) / (2 - (maxVal + minVal)); //(maxVal-minVal > 0)?  
	}

	hsl->hue = (h>360) ? 360 : ((h<0) ? 0 : h);
	hsl->saturation = ((s>1) ? 1 : ((s<0) ? 0 : s)) * 100;
	hsl->luminance = ((l>1) ? 1 : ((l<0) ? 0 : l)) * 100;
}


// Converts HSL to RGB  
void CCommonFun::HSLtoRGB(const COLOR_HSL *hsl, COLOR_RGB *rgb)
{
	float h = hsl->hue;                  // h must be [0, 360]  
	float s = hsl->saturation / 100.f; // s must be [0, 1]  
	float l = hsl->luminance / 100.f;      // l must be [0, 1]  
	float R, G, B;
	if (hsl->saturation == 0)
	{
		// achromatic color (gray scale)  
		R = G = B = l*255.0f;
	}
	else
	{
		float q = (l<0.5f) ? (l * (1.0f + s)) : (l + s - (l*s));
		float p = (2.0f * l) - q;
		float Hk = h / 360.0f;
		float T[3];
		T[0] = Hk + 0.3333333f; // Tr   0.3333333f=1.0/3.0  
		T[1] = Hk;              // Tb  
		T[2] = Hk - 0.3333333f; // Tg  
		for (int i = 0; i<3; i++)
		{
			if (T[i] < 0) T[i] += 1.0f;
			if (T[i] > 1) T[i] -= 1.0f;
			if ((T[i] * 6) < 1)
			{
				T[i] = p + ((q - p)*6.0f*T[i]);
			}
			else if ((T[i] * 2.0f) < 1) //(1.0/6.0)<=T[i] && T[i]<0.5  
			{
				T[i] = q;
			}
			else if ((T[i] * 3.0f) < 2) // 0.5<=T[i] && T[i]<(2.0/3.0)  
			{
				T[i] = p + (q - p) * ((2.0f / 3.0f) - T[i]) * 6.0f;
			}
			else T[i] = p;
		}
		R = T[0] * 255.0f;
		G = T[1] * 255.0f;
		B = T[2] * 255.0f;
	}

	rgb->red = (int)((R>255) ? 255 : ((R<0) ? 0 : R));
	rgb->green = (int)((G>255) ? 255 : ((G<0) ? 0 : G));
	rgb->blue = (int)((B>255) ? 255 : ((B<0) ? 0 : B));
}

// 在Windows系统下，HSL分量的范围是[0，240].参考“画笔”程序，可以看到RGB（红|绿|蓝）  
// 和HSL（色调|饱和度|亮度）的联系。  
// 下面的代码，把COLOR_HSL的分量值变为Windows的HSL分量，取值在[0，240]之间，需要：  
// 下面为COLOR_HSL到Windows的HSL的转换：  
// win_H = 240 * hsl.hue / 360.f;  
// win_S = 240 * hsl.saturation / 100.f;  
// win_L = 240 * hsl.luminance / 100.f;  
BOOL CCommonFun::LoadImage(CImageList& imgList, UINT bmpID, COLORREF crMask, int nInitial)
{
	CBitmap bmp;
	if (!bmp.LoadBitmap(bmpID))
		return FALSE;
	BITMAP bmpinfo;
	bmp.GetBitmap(&bmpinfo);
	int width = bmpinfo.bmWidth / nInitial;
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