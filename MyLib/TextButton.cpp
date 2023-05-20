#include "TextButton.h"
#include "ToolBar.h"
TextButton::TextButton(HDC hdc, std::string str, int w, int h)
	:Button(hdc, str, w, h) {}

TextButton::TextButton(HDC hdc, std::string str,int x,int y, int w, int h)
	: Button(hdc, str, x,y,w, h) {}


TextButton::TextButton(HDC hdc, std::string str, int w, int h, COLORREF p, COLORREF b)
	: Button(hdc, str, w, h, p, b) {}

TextButton::TextButton(HDC hdc, std::string str, int w, int h, COLORREF p, COLORREF b, Listener* lis)
	: Button(hdc, str, w, h, p, b,lis) {}

void TextButton::repaint() {
	Button::repaint();
	::TextOutA(hdc_, x_ + (widht_ / 2 - (strlen(title_.c_str()) * 4)), y_ + (hight_ / 2-8),
		title_.c_str(), strlen(title_.c_str()));
}