#pragma once
#include <Windows.h>
#include "MyEvent.h"
#include <string>

class MyShape
{
public:
	MyShape();
	MyShape(HDC, int, int, int, int);
	virtual void SetArea(int, int, int, int);       //범위 설정
	virtual bool isShapeArea(MyEvent);              //도형 내부인지 판단합니다.
	virtual bool isSelectShape(int, int, int, int); //도형을 선택합니다.
	virtual void MoveShape(int, int, int, int);     //도형을 움직입니다.
	virtual void setColar(COLORREF, COLORREF, int n = 1); //도형색을 지정합니다.
	virtual void SaveShape(FILE*);                  //도형을 저장합니다.
	virtual MyShape* CapyShape() = 0;               //도형을 복사합니다.
	virtual void repaint() = 0;

	int left_ , top_ , right_ , buttom_ ;       //도형의 범위
protected:
	int x1_ = 0, x2_ = 0, y1_ = 0, y2_ = 0;     //좌표값
	int line_ttick = 1;
	COLORREF Pen_color_;  COLORREF Brush_color_;//색값


	HDC hdc_;
	HPEN thePen_;     //선색
	HBRUSH theBrush_; //내부색
};
