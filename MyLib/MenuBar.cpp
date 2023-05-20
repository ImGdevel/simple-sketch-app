#include "MenuBar.h"
#include "HorizontalLayout.h"
#include "FlowLayout.h"
MenuBar::MenuBar(HDC hdc) {
	hdc_ = hdc;
	addLayout(new FlowLayout(this));
}

bool MenuBar::processMessage(MyEvent e) {
	if (e.event_type_ == WM_SIZE) {
		widht_ = parents_->getWidth();
	} //창크기에 따라 크기조절
	int Ma = FALSE;
	for (auto wl : *winList_) {
		if (wl->processMessage(e)) {
			Ma = TRUE;
		}
	}
	return Ma;
}

void MenuBar::addWindow(MyWindows* w) {
	hight_ = max(hight_, w->getHight());
	if (parents_ != nullptr)
		widht_ = parents_->getWidth();
	Container::addWindow(w);
}