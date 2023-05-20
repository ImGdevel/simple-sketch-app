#include "TextLabel.h"
TextLabel::TextLabel(HDC hdc, std::string str, int w, int h)
	: MyWindows(hdc, str, w, h) {}

TextLabel::TextLabel(HDC hdc, std::string str, int w, int h,int m)
	: MyWindows(hdc, str, w, h),Mode_(m) {}

bool TextLabel::processMessage(MyEvent e) {
	return MyWindows::isAccess(e);
}

void TextLabel::repaint() {
	PaintColorB();
	::Rectangle(hdc_, x_, y_, x_ + widht_, y_ + hight_);
	//숫자 출력
	if (Mode_ == INTMODE) {
		std::string num = Comma(value_);
		::TextOutA(hdc_, x_ + 8, y_ + hight_ / 2 - 7,
			num.c_str(), strlen(num.c_str()));
	}
	else if (Mode_== DOUBLEMODE) {
		char buf[124];
		sprintf_s(buf, "%lf", valued_);
		::TextOutA(hdc_, x_ + 8, y_ + hight_ / 2 - 7,
			buf, strlen(buf));
	}
	else if (Mode_ == TEXTMODE) {
		::TextOutA(hdc_, x_ + 8, y_ + hight_ / 2 - 7,
			title_.c_str(), strlen(title_.c_str()));
	}
	PaintColorA();
}

/* __엑세서/set 함수_____________________________________________________*/
void TextLabel::setMode(int m) {
	Mode_ = m;
}

void TextLabel::setValued(long double num) {
	valued_ = num;
}

void TextLabel::setValue(long long int num) {
	value_ = num;
}

long long int TextLabel::getValue()const {
	return value_;
}

long double TextLabel::getValued()const {
	return valued_;
}