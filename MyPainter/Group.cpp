#include "Group.h"
using namespace std;
Group::Group(){
	List_ = new list<MyShape*>; //초기화
}

void Group::AddGroup(MyShape* ob) {
	SetArea(ob->left_,ob->top_,ob->right_,ob->buttom_);
	List_->push_back(ob);         //리스트에 추가
}

void Group::SetArea(int x1, int y1, int x2, int y2) {      //그룹의 범위를 지정합니다.
	if (List_->empty()) { 
		left_ = x1; top_ = y1; right_ = x2; buttom_ = y2;
	}
	else {
		if (left_ >= x1) { left_ = x1; }
		if (top_ >= y1) { top_ = y1; }
		if (right_ <= x2) { right_ = x2; }
		if (buttom_ <= y2) { buttom_ = y2; }
	}
}

void Group::MoveShape(int x1, int y1, int x2, int y2) { //객체와 도형을 움직입니다.
	MyShape::MoveShape(x1, y1, x2, y2);
	for (auto it : *List_) {
		it->MoveShape(x1, y1, x2, y2);
	}
}

MyShape* Group::CapyShape() {
	Group* temp = new Group;
	for (auto lt : *List_) {
		temp->AddGroup(lt->CapyShape());
	}
	return temp;
}

void Group::SaveShape(FILE* fp) {
	fprintf(fp, "G [\n");   //색 저장
	for (auto it : *List_) {
		it->SaveShape(fp);
	}
	fprintf(fp, "G ]\n");   //색 저장
}


void Group::repaint() { //출력합니다.
	for (auto it: *List_) {
		it->repaint();
	}
}