#pragma once
#include "Button.h"
class TextButton :
	public Button
{
public:
	TextButton(HDC, std::string, int, int);
	TextButton(HDC, std::string, int, int,int,int);
	TextButton(HDC, std::string, int, int, COLORREF, COLORREF);
	TextButton(HDC, std::string, int, int, COLORREF, COLORREF, Listener*);
	virtual void repaint();
};