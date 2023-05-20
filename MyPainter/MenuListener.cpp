#include "MenuListener.h"
#include "MyFrame.h"
#include "MyWindows.h"
MenuListener::MenuListener(MyFrame* f) :m_frame(f) {
}


void MenuListener::processButtonEvent(MyWindows* w) {
	//버튼을 클릭한것에 따라 값을 지정합니다.
	std::string btn_name = w->getTitle();

	if (btn_name == "저장") {
		m_frame->save_dir->callDialogue(130, 130);
	}
	else if (btn_name == "열기") {
		m_frame->load_dir->callDialogue(150, 150);
	}
	else if (btn_name == "새로 만들기") {
		m_frame->clearAction();
	}
	else if (btn_name == "사용법") {
		m_frame->help_dir->callDialogue(150, 100);
	}
	else if (btn_name == "종료") {
		exit(1);
	}
}