#pragma once
#include "MyShape.h"
class MyRect :
	public MyShape
{
public:
	MyRect(HDC, int, int, int, int);
	virtual MyShape* CapyShape();
	virtual void SaveShape(FILE*);
	virtual void repaint();
};
