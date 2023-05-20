#pragma once
#include "MyListener.h"
class ValueListener :
	public Listener
{
public:
	ValueListener(MyFrame* f);
	virtual void processButtonEvent(MyWindows*);
protected:
	MyFrame* m_frame;
};

