#pragma once
#include "Bar.h"
#include "ButtonLib.h"
class MenuBar :
	public Bar
{
public:
	//맴버 함수
	MenuBar(HDC);
	virtual bool processMessage(MyEvent);
	virtual void addWindow(MyWindows* w); //버튼 위치 지정
protected:
};