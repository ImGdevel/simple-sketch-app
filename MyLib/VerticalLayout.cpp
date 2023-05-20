#include "VerticalLayout.h"
#include "Container.h"
VerticalLayout::VerticalLayout(Container* p)
	:Layout(p){}

void VerticalLayout::setPlace() { //단순 수직정렬
	int x = pCtn->getPointX();
	int y = pCtn->getPointY();
	for (auto wl : *pCtn->getList())
	{
		wl->setPointX(x);  wl->setPointY(y);
		y += wl->getHight();
	}
}