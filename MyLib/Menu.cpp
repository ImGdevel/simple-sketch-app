#include "Menu.h"
#include "TextButton.h"
#include "VerticalLayout.h"
Menu::Menu(HDC hdc, std::string str, int w, int h)
	:Container(hdc, str, w, h) {
	addLayout(new VerticalLayout(this));          //수직 레이아웃
	mainButton = new TextButton(hdc, str, w, h);  //주가 되는 메인버튼 설치
	addWindow(mainButton);
}

Menu::Menu(HDC hdc, std::string str, int w, int h,COLORREF p, COLORREF b)
	:Container(hdc, str, w, h) {
	addLayout(new VerticalLayout(this));          //수직 레이아웃
	mainButton = new TextButton(hdc, str, w, h,p,b);  //주가 되는 메인버튼 설치
	addWindow(mainButton);
}

bool Menu::processMessage(MyEvent e) {
	if (mainButton->processMessage(e) && !State_) { //mainButton이 눌렸고 윈도우창이 안 열였다면
		if (e.event_type_ == WM_LBUTTONUP) {
			State_ = TRUE; //윈도우창 오픈
		}
		return TRUE;
	}
	else if (State_) { //윈도창이 열렸다면 부속 버튼의 프로세스 버튼 실행
		if (e.event_type_ == WM_LBUTTONUP) {
			repaintAll();
			State_ = !State_;
		}
		return Container::processMessage(e);
	}
	return FALSE;
}


void Menu::repaint() {
	arrangeLayout();
	mainButton->repaint();
	if (State_) {
		for (auto wl : *winList_) {
			wl->repaint();
		}
	}
}
