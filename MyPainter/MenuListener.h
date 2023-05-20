#pragma once
#include "MyListener.h"
class MenuListener :
	public Listener
{
public:
	MenuListener(MyFrame*);
	virtual void processButtonEvent(MyWindows*);
protected:
	MyFrame* m_frame;
};

