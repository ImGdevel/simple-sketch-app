#pragma once
#include "Bar.h"
class RadioGroup :
	public Bar
{
public:
	RadioGroup();
	virtual void addWindow(Button*);
	virtual void processButtonEvent(Button*); //버튼에 이벤트를 처리합니다.
};

