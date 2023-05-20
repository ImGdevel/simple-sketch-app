#pragma once
#include "MyShape.h"
class MyLine :
	public MyShape
{
public:
	MyLine(HDC, int, int, int, int);
	virtual MyShape* CapyShape();
	virtual void SaveShape(FILE*);
	virtual void repaint();
};
