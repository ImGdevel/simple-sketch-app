#pragma once
#include "Bar.h"
class ToolBar
	:public Bar
{
public:
	//¸É¹ö ÇÔ¼ö
	ToolBar();
	virtual bool processMessage(MyEvent);
	virtual void addWindow(MyWindows* w);
};