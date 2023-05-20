#pragma once
#include "MyShape.h"
class MyCircle :
	public MyShape
{
public:
	MyCircle(HDC, int, int, int, int);
	virtual MyShape* CapyShape();
	virtual void SaveShape(FILE*);
	virtual void repaint();
};
