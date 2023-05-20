#pragma once
#include "MyListener.h"
class DialogueListener :
	public MyListener
{
public:
	DialogueListener(MyFrame*);
	virtual void processButtonEvent(MyWindows*);
protected:
	MyFrame* m_frame;
	
};

