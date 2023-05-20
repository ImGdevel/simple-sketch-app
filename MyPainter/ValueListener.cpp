#include "ValueListener.h"
#include "MyFrame.h"
#include "MyWindows.h"
ValueListener::ValueListener(MyFrame* f):m_frame(f) {
}


void ValueListener::processButtonEvent(MyWindows* w) {
	//버튼을 클릭한것에 따라 값을 지정합니다.
	std::string btn_name = w->getTitle();
	if (btn_name == "ColorBox") {
		m_frame->select_color = w->getColor();
		if (m_frame->ColorType == 1) { //선색
			m_frame->Pen_color = m_frame->select_color;
			m_frame->pbox->setColor(m_frame->select_color);
		}
		else if ((m_frame->ColorType == 0)) { //채우기색
			m_frame->Brush_color = m_frame->select_color;
			m_frame->bbox->setColor(m_frame->select_color);
		}
	}
	else if (btn_name == "＋") {
		if (m_frame->Line_wid < 10) {
			m_frame->Line_wid++;
			(m_frame->wide_label)->setValue(m_frame->Line_wid);
		}
	}
	else if (btn_name == "－") {
		if (m_frame->Line_wid > 1) {
			m_frame->Line_wid--;
			(m_frame->wide_label)->setValue(m_frame->Line_wid);
		}
	}
	m_frame->repaint();
}