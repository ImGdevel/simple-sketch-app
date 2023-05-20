#include "Button.h"
#include "Frame.h"
#include "Listener.h"

Button::Button(HDC hdc, std::string str, int w, int h) 
	:MyWindows(hdc, str, w, h) {
	mouse_off_brush = newBrush_;
	setMouseOnColor(RGB(100, 100, 100));
}
Button::Button(HDC hdc, std::string str,int x,int y, int w, int h)
	: MyWindows(hdc, str, x,y,w, h) {
	mouse_off_brush = newBrush_;
	setMouseOnColor(RGB(100, 100, 100));
}
Button::Button(HDC hdc, std::string str, int w, int h, COLORREF p, COLORREF b)
	: MyWindows(hdc, str, w, h,p,b) {
	setMouseOnColor(RGB(100, 100, 100));
	mouse_off_brush = CreateSolidBrush(RGB(GetRValue(b), GetGValue(b), GetBValue(b)));
}
Button::Button(HDC hdc, std::string str, int w, int h, COLORREF p, COLORREF b,Listener* lis)
	: MyWindows(hdc, str, w, h, p, b), listen_(lis){
	setMouseOnColor(RGB(100, 100, 100));
	mouse_off_brush = CreateSolidBrush(RGB(GetRValue(b), GetGValue(b), GetBValue(b)));
}

bool Button::processMessage(MyEvent e) {
	if (e.event_type_ == WM_MOUSEMOVE) { //마우스 무브 액션
		MouseOn(e);
		return FALSE;
	}
	else if (isAccess(e)) {
		switch (e.event_type_) {
		case WM_LBUTTONDOWN:
		{
			parents_->pressed_ = this;
		} break;
		case WM_LBUTTONUP:
		{
			if (parents_->pressed_ == this) {       //일치하면 버튼이 눌려짐
				ClickAction();                      //클릭했을때 액션을 불러옵니다.
				if (listen_ != nullptr) {
					//리스너가 존재한다면 리스너로
					listen_->processButtonEvent((MyWindows*)this);
				}
				else {
					//없다면 콜백으로 실행합니다.
					parents_->processButtonEvent(this);
				}
			}
			parents_->pressed_ = FALSE;
		} break;
		default: break;
		}
		return TRUE;
	}
	return FALSE;
}

void Button::repaint() {
	PaintColorB();
	::Rectangle(hdc_, x_, y_, x_ + widht_, y_ + hight_);
	PaintColorA();
}

void Button::MouseOn(MyEvent e) {
	if (!on_State && isAccess(e)) {
		on_State = TRUE;
		newBrush_ = mouse_on_brush;
		if (sts == nullptr ||!sts->getState()) {
			repaint();
		}
	}
	else if (on_State && !isAccess(e)) {
		on_State = FALSE;
		newBrush_ = mouse_off_brush;
		if (sts==nullptr||!sts->getState()) {
			repaint();
		}
	}
}

void Button::setMouseOnColor(COLORREF m) {
	mouse_off_brush = newBrush_;
	mouse_on_brush = CreateSolidBrush(RGB(GetRValue(m), GetGValue(m), GetBValue(m)));
}

void Button::ClickAction() {

}

bool Button::ButtonState() const {
	return FALSE;
}

void Button::setsts(MyWindows* w) {
	sts = w;
}