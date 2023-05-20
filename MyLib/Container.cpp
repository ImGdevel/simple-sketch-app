#include "Container.h"
Container::Container() {
	winList_ = new list<MyWindows*>;
}
Container::Container(HDC hdc, std::string str, int w, int h)
	:MyWindows(hdc, str,w,h){
	winList_ = new list<MyWindows*>;
}

bool Container::processMessage(MyEvent e) {  //winlsit의 프로세스를 불러 FALSE TURE를 판단
	for (auto list : *winList_) {
		if (list->processMessage(e)) {
			return TRUE;
		}
	} return FALSE;
}

void Container::addWindow(MyWindows* ob){	//윈도우 추가
	winList_->push_back(ob);
	ob->setParents(this);
}

void Container::arrangeLayout() {  //레이아웃 정렬
	if (layout_ != nullptr) {
		layout_->setPlace();
	}
}

void Container::repaint() {        //winlist내용을 출력합니다.
	arrangeLayout();
	for (auto wl = winList_->rbegin(); wl != winList_->rend(); wl++) {
		(*wl)->repaint();
	}
}

/*__ 엑세서 함수, set함수 __________________________________________*/
std::list<MyWindows*>* Container::getList(){
	return winList_;
}

void Container::addLayout(Layout* p) {
	layout_ = p;
}