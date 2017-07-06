#pragma once
class CGamePath
{
public:
	CGamePath();
	virtual ~CGamePath();

protected:
public:
	virtual void getPosition(int& x, int& y, const int& x0, const int& y0, const double& offset, const int& s) = 0;
};

