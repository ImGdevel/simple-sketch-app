#include "HorizontalLayout.h"
#include "Container.h"
HorizontalLayout::HorizontalLayout(Container* p)
	:Layout(p) {}

void HorizontalLayout::setPlace() { //단순 수평정렬
	int x = pCtn->getPointX();
	int y = pCtn->getPointY();
	for (auto wl : *pCtn->getList())
	{
		wl->setPointX(x);  wl->setPointY(y);
		x += wl->getWidth();
	}
}