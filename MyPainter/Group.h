#pragma once
#include "MyEvent.h"
#include "MyShape.h"
#include <list>
class Group :public MyShape
{
public:
	Group();
	void AddGroup(MyShape*);
	void MoveShape(int, int, int, int);     //도형을 움직입니다.
	void SetArea(int,int,int,int);          //그룹의 범위를 지정합니다.
	MyShape* CapyShape();
	void SaveShape(FILE*);
	void repaint();

	std::list<MyShape*>* List_;   //그룹 리스트입니다.
};