#pragma once
#include "Container.h"
class Bar :
	public Container
{
public:
	Bar();
	Bar(HDC, std::string, int, int);
	virtual bool processMessage(MyEvent);
	virtual void repaint();
};

