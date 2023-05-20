#pragma once
#include "Layout.h"
class GridLayout :
	public Layout
{
public:
	GridLayout(Container*,int); // 그리드 레이아웃
	virtual void setPlace();

protected:
	int Line = 1;
};

