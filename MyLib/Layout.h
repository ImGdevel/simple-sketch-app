#pragma once
#include "MyEvent.h"
class Container;
class Layout
{
public:
	Layout(Container*);  //·¹ÀÌ¾Æ¿ô
	virtual void setPlace() = 0;
protected:
	Container* pCtn;
};

