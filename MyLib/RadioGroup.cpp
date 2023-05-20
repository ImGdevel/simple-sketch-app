#include "RadioGroup.h"
#include "Button.h"
#include "HorizontalLayout.h"
RadioGroup::RadioGroup() {
	addLayout(new HorizontalLayout(this));
}

void RadioGroup::addWindow(Button* w) {
	hight_ = max(w->getHight(), hight_);
	widht_ += w->getWidth();
	Container::addWindow(w);
}

void RadioGroup::processButtonEvent(Button* b) {
	for (auto wl : *winList_) {
		wl->setState(FALSE);
	}
	b->setState(TRUE); //클릭된 것만 State 1;
	MyWindows::processButtonEvent(b);
}
