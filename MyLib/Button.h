#pragma once
#include "MyEvent.h"
#include "MyWindows.h"
#include <string>
class Listener;
class Button
	:public MyWindows
{
public:
	Button(HDC, std::string, int, int);
	Button(HDC, std::string, int, int,int,int);
	Button(HDC, std::string, int, int, COLORREF, COLORREF);
	Button(HDC, std::string, int, int, COLORREF, COLORREF, Listener*);

	virtual bool processMessage(MyEvent);  //메세지를 처리합니다.
	virtual void repaint();
	virtual void ClickAction();             // 클릭 액션입니다.
	virtual void MouseOn(MyEvent);          // 마우스를 가져다 댔을때 액션입니다.
	virtual void setMouseOnColor(COLORREF); // 마우스 올려놓을때 색을 지정합니다.
	virtual bool ButtonState() const;       // 버튼의 상태를 리턴합니다.
	virtual void setsts(MyWindows*);
protected:
	HBRUSH mouse_on_brush;  // 마우스 올릴때 색
	HBRUSH mouse_off_brush; // 아닐때 색
	int on_State;           // 마우스를 올려놓으면 TRUE
	Listener* listen_;      // 리스너
	MyWindows* sts;
};