#include "FlowLayout.h"
#include "Container.h"
FlowLayout::FlowLayout(Container* p) :Layout(p) {}
FlowLayout::FlowLayout(Container* p, int m) : Layout(p),arrange_mode(m) {}
FlowLayout::FlowLayout(Container* p, int x, int y) :Layout(p), x_dis(x), y_dis(y) {}
void FlowLayout::setPlace() {
	int x = pCtn->getPointX();
	int	y = pCtn->getPointY();
	int	hi = 0, wid = 0, all_high = 0;
	if (arrange_mode == HOR) { //플로우 레이아웃 수평정렬
		for (auto ob : *pCtn->getList())
		{
			if ((x + ob->getWidth()) > pCtn->getWidth()) {//만약 w가 창 크기보다 작다면    
				x = 0;	y += hi + y_dis; 
				all_high += hi;	hi = 0;
			}
			ob->setPointX(x);   ob->setPointY(y);
			x += ob->getWidth() + x_dis;
			hi = max(hi, ob->getHight());
		}
		
		pCtn->setHight(all_high+hi);
	}
	else { //플로우 레이아웃 수직정렬
		for (auto ob : *pCtn->getList())
		{
			if ((y + ob->getHight()) > pCtn->getHight()) {//만약 w가 창 크기보다 작다면    
				x = 0;	y += wid+x_dis;	wid = 0;
			}
			ob->setPointX(x);   ob->setPointY(y);
			y += ob->getHight()+y_dis;
			wid = max(wid, ob->getWidth());
		}
	}
}