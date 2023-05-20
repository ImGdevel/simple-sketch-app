#pragma once
#include "Button.h"
class CheckBox :
	public Button
{
public:
	CheckBox(HDC, std::string, int, int);
	CheckBox(HDC, std::string, int, int, COLORREF, COLORREF);
	CheckBox(HDC, std::string, int, int, COLORREF, COLORREF, Listener*);
	virtual void ClickAction();            //클릭 액션입니다.
	virtual void repaint();
	virtual void isChecked();
	virtual bool ButtonState() const;      //현제 버튼 상태를 리턴합니다.
protected:
	std::string str_;
	int State = FALSE;   //  TRUE면 체크 & FALSE면 체크헤제
};
