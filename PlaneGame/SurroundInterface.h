#pragma once
class CSurroundInterface
{
public:
	CSurroundInterface();
	virtual void updatePosition(CPoint newpoint) = 0;
	virtual ~CSurroundInterface();
};

