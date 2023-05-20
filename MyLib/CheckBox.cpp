#include "CheckBox.h"
#include "ToolBar.h"
CheckBox::CheckBox(HDC hdc, std::string str, int w, int h)
	: Button(hdc, str, w, h) {
	str_ = "□ " + str;
}
CheckBox::CheckBox(HDC hdc, std::string str, int w, int h, COLORREF p, COLORREF b)
	: Button(hdc, str, w, h, p, b) {
	str_ = "□ " + str;
}

CheckBox::CheckBox(HDC hdc, std::string str, int w, int h, COLORREF p, COLORREF b, Listener* lis)
	: Button(hdc, str, w, h, p, b,lis) {
	str_ = "□ " + str;
}

void CheckBox::ClickAction() {
	isChecked();
}

void CheckBox::isChecked(){
	//체크 박스의 상태에 따라 처리됩니다.
	(State == TRUE) ? State = FALSE : State = TRUE; //State Ture = 체크 False = 체크헤제
	if (State)
		str_ = "▣ " + title_;
	else
		str_ = "□ " + title_;
}

void CheckBox::repaint() {
	Button::repaint();
	::TextOutA(hdc_, x_+(widht_ / 2 - (strlen(str_.c_str()) * 4)), y_ + (hight_ / 2 - 8) ,
		str_.c_str(), strlen(str_.c_str()));
}

bool CheckBox::ButtonState() const {
	return State;
}
