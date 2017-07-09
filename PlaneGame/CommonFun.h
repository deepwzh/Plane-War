#pragma once
#include "GameObject.h"

#define min3v(v1, v2, v3)   ((v1)>(v2)? ((v2)>(v3)?(v3):(v2)):((v1)>(v3)?(v3):(v2)))  
#define max3v(v1, v2, v3)   ((v1)<(v2)? ((v2)<(v3)?(v3):(v2)):((v1)<(v3)?(v3):(v1)))  

class CCommonFun
{
public:

	struct COLOR_RGB
	{
		int  red;              // [0,255]  
		int  green;            // [0,255]  
		int  blue;             // [0,255]
		COLOR_RGB(int red = 0, int green = 0, int blue = 0) : red(red), green(green), blue(blue) {}
	};

	struct COLOR_HSL
	{
		float hue;              // [0,360]  
		float saturation;       // [0,100]  
		float luminance;        // [0,100]
		COLOR_HSL(float hue = 0.0, float saturation = 0.0, float luminance = 0.0) : hue(hue), saturation(saturation), luminance(luminance) {}
	};

	enum Direction
	{
		U = 1,
		D = 2,
		L = 4,
		R = 8,
		None = 0
	};
	static void RGBtoHSL(const COLOR_RGB *rgb, COLOR_HSL *hsl);
	static void HSLtoRGB(const COLOR_HSL *hsl, COLOR_RGB *rgb);
	static BOOL CCommonFun::LoadImage(CImageList& imgList, UINT bmpID, COLORREF crMask, int nInitial);
	static int GetImageListInfo(const CImageList &m_Images, int& width, int& height);
};