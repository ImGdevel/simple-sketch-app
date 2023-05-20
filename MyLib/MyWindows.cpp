#include "MyWindows.h"
MyWindows::MyWindows() {}
MyWindows::MyWindows(HDC hdc, std::string str, int w, int h)
	: hdc_(hdc), title_(str),x_(0),y_(0), widht_(w), hight_(h) { }
MyWindows::MyWindows(HDC hdc, std::string str, int w, int h,COLORREF p, COLORREF b)
	: hdc_(hdc), title_(str), x_(0), y_(0), widht_(w), hight_(h) { 
	setColor(p, b);
}
MyWindows::MyWindows(HDC hdc, std::string str, int l, int r, int t, int b)
	: hdc_(hdc), title_(str), x_(l), y_(r), widht_(t), hight_(b) { }

bool MyWindows::processMessage(MyEvent e) {
	return FALSE;
}

bool MyWindows::isAccess(MyEvent e) {
	return e.x_ >= x_ && e.x_ <= x_ + widht_
		&& e.y_ >= y_ && e.y_ <= y_ + hight_;
}

void MyWindows::setParents(MyWindows* win) {
	parents_ = win;
}

void MyWindows::processButtonEvent(Button* b) {
	parents_->processButtonEvent(b);
}

void MyWindows::movePlace(int x1, int y1, int x2, int y2) {
	x_ += (x2 - x1);
	y_ += (y2 - y1);
	repaintAll();
}

void MyWindows::repaintAll() {
	InvalidateRect(hWnd_, NULL, true);
}

/*__ 엑세서 함수, set함수 __________________________________________*/
HWND MyWindows::getHwnd()const{
	return hWnd_;
}
HDC MyWindows::getHdc()const{
	return hdc_;
}
void MyWindows::setHwnd(HWND hw) {
	hWnd_ = hw;
}
int MyWindows::getWidth()const {
	return widht_;
}
int MyWindows::getHight()const {
	return hight_;
}
int MyWindows::getPointX()const {
	return x_;
}
int MyWindows::getPointY()const {
	return y_;
}
void MyWindows::setPointX(int x){
	x_ = x;
}
void MyWindows::setPointY(int y){
	y_ = y;
}
void MyWindows::setWidth(int w) {
	widht_ = w;
}
void MyWindows::setHight(int h) {
	hight_ = h;
}
int MyWindows::getState()const {
	return State_;
}
void MyWindows::setState(int s) {
	State_ = s;
}
std::string MyWindows::getTitle() const {
	return title_;
}
void MyWindows::setColor(COLORREF p, COLORREF b) {
	Pen_color_ = p;
	newPen_ = CreatePen(PS_SOLID, 1, RGB(GetRValue(p), GetGValue(p), GetBValue(p)));
	Brush_color_ = b;
	newBrush_ = CreateSolidBrush(RGB(GetRValue(b), GetGValue(b), GetBValue(b)));
}
void MyWindows::PaintColorB() {
	oldPen_ = (HPEN)SelectObject(hdc_, newPen_);
	oldBrush_ = (HBRUSH)SelectObject(hdc_, newBrush_);
}
void MyWindows::PaintColorA() {
	SelectObject(hdc_, oldPen_);
	SelectObject(hdc_, oldBrush_);
}
COLORREF MyWindows::getColor() {
	return 0;
}
void MyWindows::setTitle(std::string s) {
	title_ = s;
}