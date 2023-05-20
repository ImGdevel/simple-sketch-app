#pragma once
#include "Layout.h"
class HorizontalLayout :
	public Layout
{
public:
	HorizontalLayout(Container*); //수평정렬
	virtual void setPlace();
};

