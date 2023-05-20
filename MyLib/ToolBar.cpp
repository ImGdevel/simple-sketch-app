#include "ToolBar.h"
#include "HorizontalLayout.h"
#include "FlowLayout.h"
ToolBar::ToolBar(){
	addLayout(new FlowLayout(this));
}

bool ToolBar::processMessage(MyEvent e) {
	if (e.event_type_ == WM_SIZE) {
		widht_ = parents_->getWidth();
	}
	return Bar::processMessage(e);
}

void ToolBar::addWindow(MyWindows* w) {
	hight_ = max(hight_, w->getHight());   
	if (parents_ != nullptr) widht_ = parents_->getWidth();
	Container::addWindow(w);
}
