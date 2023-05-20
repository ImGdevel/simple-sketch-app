#include "ColorBox.h"
ColorBox::ColorBox(HDC hdc, int w, int h)
	:Button(hdc, "ColorBox", w, h) { }
ColorBox::ColorBox(HDC hdc, int w, int h, COLORREF b)
	: Button(hdc, "ColorBox", w, h) {
	Brush_color_ = b;
	brsh = CreateSolidBrush(RGB(GetRValue(b), GetGValue(b), GetBValue(b)));
}
ColorBox::ColorBox(HDC hdc,std::string str , int w, int h, COLORREF b)
	: Button(hdc, str, w, h) {
	Brush_color_ = b;
	brsh = CreateSolidBrush(RGB(GetRValue(b), GetGValue(b), GetBValue(b)));
}
ColorBox::ColorBox(HDC hdc, int w, int h, COLORREF b,Listener* lis)
	: Button(hdc, "ColorBox", w, h,RGB(0,0,0),b,lis) {
	brsh = CreateSolidBrush(RGB(GetRValue(b), GetGValue(b), GetBValue(b)));
}
void ColorBox::repaint() {
	HBRUSH oldbrush = (HBRUSH)SelectObject(hdc_, brsh);
	::Rectangle(hdc_, x_, y_, x_ + widht_, y_ + hight_);
	SelectObject(hdc_, oldbrush);
}

void ColorBox::setColor(COLORREF b) {
	Brush_color_ = b;
	brsh = CreateSolidBrush(RGB(GetRValue(b), GetGValue(b), GetBValue(b)));
}

COLORREF ColorBox::getColor() {
	return Brush_color_;
}