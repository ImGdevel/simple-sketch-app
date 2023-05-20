#pragma once
#include "Button.h"
class ColorBox :
	public Button
{
public:
	ColorBox(HDC, int, int);
	ColorBox(HDC, int, int, COLORREF);
	ColorBox(HDC, std::string,int, int, COLORREF);
	ColorBox(HDC, int, int, COLORREF,Listener*);
	virtual void setColor(COLORREF);
	virtual COLORREF getColor();
	virtual void repaint();

	HBRUSH brsh;
};

