#pragma once
#include "MyWindows.h"
//다이얼로그를 컨테이너에 넣기는 개별적인 요소가 너무 많음
class Dialogue :
	public MyWindows
{
public:	
	Dialogue(HDC, std::string, int, int);    //다이얼로그의 기본 형태
	virtual void UiUpdate();                 //초기 다이얼로그
	virtual bool processMessage(MyEvent);
	virtual void addWorkButton(Button*);     // 기본 버튼을 추가합니다.
	virtual void DialogueAction();           // 다이얼 로그의 액션입니다.
	virtual void callDialogue(int,int);      // 다디얼로그를 지정 위치에 부릅니다.
	virtual void arrangeDialogue();          // 다이얼 로그 내부를 정렬합니다.
	virtual void repaint();                  // 출력합니다.

protected:
	Button* move_bar;      //다이얼로그를 움직일때 쓰는 바다.
	Button* off_btn;       //다이얼 로그를 닫는 버튼이다. //기본 셋팅
	Button* select_btn[3]; //취소, 확인, 등등이 들어간다.
	int btn_num;
	int move_action;
	int start_x, start_y;
};