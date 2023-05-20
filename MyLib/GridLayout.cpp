#include "GridLayout.h"
#include "Container.h"
GridLayout::GridLayout(Container* p,int n) :Layout(p) {
	Line = n;
}

void GridLayout::setPlace() {
	int x = pCtn->getPointX();
	int	y = pCtn->getPointY();
	int hi = 0, wide = pCtn->getWidth() / Line;
	for (auto ob : *pCtn->getList())
	{
		if ((x + ob->getWidth()) > pCtn->getWidth()) {//만약 w가 창 크기보다 작다면
			x = 0;	y += hi;	hi = 0;
		}
		ob->setPointX(x);    ob->setPointY(y);
		int leght = x + ob->getWidth();
		for (int i = 0; i < Line; i++) {
			if (x < leght) {
				x += wide;
			}
		}
		hi = max(hi, ob->getHight());	
	}
}
