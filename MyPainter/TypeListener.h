#pragma once
#include "MyListener.h"
class TypeListener :
	public MyListener
{
public:
	TypeListener(MyFrame* f);
	virtual void processButtonEvent(MyWindows*);
protected:
	MyFrame* m_frame;
};

