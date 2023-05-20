#pragma once
#include "Layout.h"
class VerticalLayout : 
	public Layout
{
public:
	VerticalLayout(Container*); //수직정렬
	virtual void setPlace();
};

