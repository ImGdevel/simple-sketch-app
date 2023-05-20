#include "MyCircle.h"
using namespace std;
MyCircle::MyCircle(HDC hdc, int l, int r, int t, int b) :MyShape(hdc, l, r, t, b) { }

MyShape* MyCircle::CapyShape() {
	MyShape* temp_ = new MyCircle(hdc_, x1_, y1_, x2_, y2_);
	temp_->setColar(Pen_color_, Brush_color_,line_ttick);
	return temp_;
}

void MyCircle::SaveShape(FILE* fp) {
	fprintf(fp, "%c ", 'C');  //타입저장
	MyShape::SaveShape(fp);
}

void MyCircle::repaint() {
	HPEN oldPen = (HPEN)SelectObject(hdc_, thePen_);
	HBRUSH oldbrush = (HBRUSH)SelectObject(hdc_, theBrush_);
	::Ellipse(hdc_, x1_, y1_, x2_, y2_);
	SelectObject(hdc_, oldPen);
	SelectObject(hdc_, oldbrush);
}
