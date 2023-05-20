#include "Bar.h"
#include "Frame.h"
Bar::Bar() {
}
Bar::Bar(HDC hdc, std::string str, int w, int h)
	:Container(hdc, str, w, h) { }

bool Bar::processMessage(MyEvent e) {
	if (!e.isMouseEvent() && e.event_type_ != WM_MOUSEMOVE)
		return FALSE;
	if (Container::processMessage(e) || pressed_) {
		if (e.event_type_ == WM_LBUTTONUP) {      //버튼을 땟을때 눌려진 상태를 초기화 합니다.
			pressed_ = FALSE;
		}
		return TRUE;
	}
	return FALSE;
}

void Bar::repaint() {
	HDC hdc_a = ::GetHDC();
	Rectangle(hdc_a, x_, y_, x_ + widht_, y_ + hight_);
	Container::repaint();
}