#pragma once
class CSurroundInterface
{
public:
	CSurroundInterface();
	//virtual void draw(CDC * pDC) = 0;
	virtual void updatePosition(CPoint newpoint) = 0;
	virtual ~CSurroundInterface();
};

