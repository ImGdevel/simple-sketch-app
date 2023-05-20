#pragma once
#include <Windows.h>
#include "MyEvent.h"
#include "FrameHader.h"
#include <string>
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
class Frame 
	:public Container{
public:
	// 기본 생성자
	Frame(std::wstring);
	Frame(std::wstring, int, int);
	// 맴버함수
	virtual void run();
	virtual bool processMessage(MyEvent e);
	virtual void processButtonEvent(Button*);
	virtual void setFont(int n = 0, COLORREF c = 0); //폰트를 지정합니다.
	virtual void repaint();

	
};

HDC GetHDC();