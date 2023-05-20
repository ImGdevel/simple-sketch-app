#include "MyLine.h"
using namespace std;
MyLine::MyLine(HDC hdc, int l, int r, int t, int b) :MyShape(hdc, l, r, t, b) { }

MyShape* MyLine::CapyShape() {
	MyShape* temp_ = new MyLine(hdc_, x1_, y1_, x2_, y2_);
	temp_->setColar(Pen_color_, Brush_color_,line_ttick);
	return temp_;
}

void MyLine::SaveShape(FILE* fp) {
	fprintf(fp, "%c ", 'L');  //타입저장
	MyShape::SaveShape(fp);
}

void MyLine::repaint() {
	HPEN oldPen = (HPEN)SelectObject(hdc_, thePen_);
	HBRUSH oldbrush = (HBRUSH)SelectObject(hdc_, theBrush_);
	::MoveToEx(hdc_, x1_, y1_,NULL);
	::LineTo(hdc_, x2_, y2_);
	SelectObject(hdc_, oldPen);
	SelectObject(hdc_, oldbrush);
}
