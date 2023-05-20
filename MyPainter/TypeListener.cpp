#include "TypeListener.h"
#include "MyFrame.h"
#include "MyWindows.h"
TypeListener::TypeListener(MyFrame* f) :m_frame(f) {
}


void TypeListener::processButtonEvent(MyWindows* w) {
	//버튼을 클릭한것에 따라 타입을 지정합니다.
	std::string btn_name = w->getTitle();

	if (btn_name == "사각형" || btn_name == "원" || btn_name == "선분" || btn_name == "펜") {
		m_frame->PaintingType = btn_name;
	}
	else if (btn_name == "채우기색") {
		m_frame->ColorType = 0;
	}
	else if (btn_name == "선색") {
		m_frame->ColorType = 1;
	}
	else if (btn_name == "지우기") {
		m_frame->clearAction();
		m_frame->repaintAll();
	}
	m_frame->repaint();
}