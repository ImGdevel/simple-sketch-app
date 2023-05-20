#include "Dialogue.h"
#include "Button.h"
#include "TextButton.h"
//다이얼로그 1차 완성////////////////
Dialogue::Dialogue(HDC hdc, std::string str, int w, int h)
	: MyWindows(hdc,str,w,h) {
	UiUpdate();
}    //다이얼로그의 기본 형태
void Dialogue::UiUpdate() {
	off_btn = new TextButton(hdc_, "X", x_ + widht_ - 5, y_, 25, 25);
	off_btn->setParents(this);
	move_bar = new TextButton(hdc_, title_, x_, y_, widht_-25, 25);
	move_bar->setParents(this);
}

bool Dialogue::processMessage(MyEvent e) {
	if (!e.isMouseEvent())
		return FALSE;

	/* 이동 _____ */
	if (move_action && e.event_type_ != WM_MOUSEMOVE) { //바를 눌렀다면  후
		movePlace(start_x, start_y, e.x_, e.y_);
		move_action = FALSE;
		return TRUE;
	}
	else if (State_ && move_bar->processMessage(e)) { //바를 눌렀을때  선
		move_action = TRUE;
		start_x = e.x_;  start_y = e.y_;
		return TRUE;
	}
	/* 다이얼 로그 액션 ______________ */
	if (isAccess(e) && State_) {
		int select_b = FALSE;	
		for (int i = 0; i < btn_num;i++) { //만약 다이얼로그의 버튼을 눌렀다면
			select_b = select_btn[i]->processMessage(e);
			if (select_b == TRUE)
				break;
		}
		if (select_b == FALSE) {  //취소 버튼을 눌렀다면
			select_b = off_btn->processMessage(e);
		}
		if (select_b && e.event_type_ == WM_LBUTTONUP) { //디이얼 로그 종료 
			State_ = FALSE;
		}
		else { //아니라면 액션
			DialogueAction();
		}
		return TRUE;
	}
	return FALSE;
}

void Dialogue::callDialogue(int x,int y) {  //지정 위치에 다이얼 로그 call
	State_ = TRUE;
	x_ = x;   y_ = y;
}

void Dialogue::addWorkButton(Button* w) { // 기본 버튼을 추가합니다.
	select_btn[btn_num++] = w;
	w->setParents(this);
}

void Dialogue::DialogueAction() {  // 다이얼 로그의 액션입니다.
	//비어있음
}

void Dialogue::arrangeDialogue() {
	// X버튼 위치, bar 위치
	off_btn->setPointX(x_ + widht_ - 25);   off_btn->setPointY(y_);
	move_bar->setPointX(x_);  move_bar->setPointY(y_);

	// 작업 버튼 위치
	if (select_btn[0] != nullptr) {
		int y_val = (y_ + hight_ - (select_btn[0]->getHight() + 5));
		int x_val = (x_ + widht_ - (select_btn[0]->getWidth() + 5));
		for (int i = 0; i < btn_num; i++) {
			select_btn[i]->setPointX(x_val);
			select_btn[i]->setPointY(y_val);
			x_val -= (select_btn[i]->getWidth() + 10);
		}
	}
}

void Dialogue::repaint() {                  // 출력합니다.
	arrangeDialogue();
	if (State_) {
		::Rectangle(hdc_, x_, y_, x_ + widht_, y_ + hight_);
		::TextOutA(hdc_, x_ + 5, y_ + 5, title_.c_str(), strlen(title_.c_str()));
		off_btn->repaint();
		move_bar->repaint();
		for (int i = 0; i < btn_num; i++) {
			select_btn[i]->repaint();
		}
	}
}