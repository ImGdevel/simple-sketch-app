#pragma once
#include "Layout.h"
#define HOR 0
#define VER 1
class FlowLayout :
	public Layout
{
public:
	FlowLayout(Container*);          //플로우 레이아웃
	FlowLayout(Container*,int);      //수직,수평정렬인지 가능
	FlowLayout(Container*,int, int); //간격 설정
	virtual void setPlace();
protected:
	int x_dis, y_dis;       //x,y간격
	int arrange_mode = HOR; //HOR은 수평, VER은 수직
};

