#pragma once
#include "Container.h"
class Menu :
	public Container
{
public:
	Menu(HDC, std::string, int, int);
	Menu(HDC, std::string, int, int, COLORREF, COLORREF);
	virtual bool processMessage(MyEvent);
	virtual void repaint();
protected:
	Button* mainButton;
};
