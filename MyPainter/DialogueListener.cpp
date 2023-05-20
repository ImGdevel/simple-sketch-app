#include "DialogueListener.h"
#include "MyFrame.h"
#include "MyWindows.h"
DialogueListener::DialogueListener(MyFrame* f) :m_frame(f) {
}


void DialogueListener::processButtonEvent(MyWindows* w) {
	//버튼을 클릭한것에 따라 값을 지정합니다.
	std::string btn_name = w->getTitle();
	if (btn_name == "저장하기") {
		m_frame->saveObject();
	}
	else if (btn_name == "불러오기") {
		m_frame->clearAction();
		m_frame->loadObject();
	}
	m_frame->repaintAll();
}