#pragma once
#include "Frame.h"
#include "Shapelib.h"
#include "TypeListener.h"
#include "ValueListener.h"
#include "DialogueListener.h"
#include "MenuListener.h"
#include <list>
#include <typeinfo>
#define DRAW_ACTION 0
#define MOVE_ACTION 1
#define CAPY_ACTION 2
using namespace std;
class MyFrame :
	public Frame
{
public:
	//생성자
	MyFrame(std::wstring);
	MyFrame(std::wstring, int, int);
	/*____맴버함수__________________________________________________*/
	virtual void run();
	virtual void InterfaceUpdate();           //초기 인터페이스를 업데이트합니다.
	virtual bool processMessage(MyEvent);
	virtual void processButtonEvent(Button*); //버튼 이밴트를 처리합니다.
	virtual void saveObject();  //저장
	virtual void loadObject();  //물로오기
	virtual void repaint();

	int MoveMode =0;
	  /*____Action _________________________________________________*/
	virtual void MoveAction(MyEvent);         //그림을 움직이는 액션입니다.
	virtual bool selectShape(MyEvent);        //도형을 선택합니다.
	virtual void capyAction(MyEvent);         //도형을 복사하는 액션입니다.
	virtual void drawAction(MyEvent);         //그림을 저장합니다.
	virtual void groupAction(MyEvent);        //도형을 그룹화 합니다.
	virtual void clearAction();


	list<MyShape*>* pShape_;
	list<MyShape*>::iterator pTemp; //임시 포인터
	Group* Pen_line;
	int startx = 0, starty = 0;
	/*__Type _______________________________________________________*/
	std::string PaintingType;
	std::string file_name;
	int InformState = FALSE;
	int SearchState = FALSE;
	int Action = DRAW_ACTION;
	int ColorType = 0;
	int PenType = FALSE;


	COLORREF select_color = RGB(255, 255, 255); //현제 선택된 컬러
	COLORREF Pen_color = RGB(0,0,0);            //팬 컬러
	COLORREF Brush_color = RGB(255,255,255);    //브러쉬 컬러
	int Line_wid = 1;
	/* ___버튼______________________________*/
	ColorBox* pbox;  //팬 현제컬러
	ColorBox* bbox;  //브러쉬 현제 컬러
	TextLabel* wide_label;

	/* __ 브러쉬 다이얼 로그______________________________*/
	TextPutDialogue* load_dir; //불러오기
	TextPutDialogue* save_dir; //저장
	TextDialogue* help_dir;    //사용법
	
	
};
