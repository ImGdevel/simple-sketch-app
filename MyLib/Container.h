#pragma once
#include "MyWindows.h"
#include "MyEvent.h"
#include "Layout.h"
#include "FlowLayout.h"
#include <list>
using std::list;
class Container
	:public MyWindows
{
public:
	Container();
	Container(HDC, std::string, int, int);
	virtual bool processMessage(MyEvent);
	virtual void addWindow(MyWindows*);  // 윈도우 객체를 저장합니다.
	virtual void addLayout(Layout*);     // 레이아웃 추가
	virtual void arrangeLayout();        // 레이아웃 정렬
	virtual void repaint();              // 출력하는 repaint함수
	list<MyWindows*>* getList(); //엑세서

protected:
	list<MyWindows*>* winList_;  //윈도우 리스트
	Layout* layout_ = nullptr;
};