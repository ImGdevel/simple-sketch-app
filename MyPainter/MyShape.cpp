#include "MyShape.h"
using namespace std;
MyShape::MyShape() {}

MyShape::MyShape(HDC hdc, int x1, int y1, int x2, int y2)
	: hdc_(hdc), x1_(x1), y1_(y1), x2_(x2), y2_(y2) {
	SetArea(x1, y1, x2, y2);
}

void MyShape::SetArea(int x1, int y1, int x2, int y2) { //범위를 지정합니다.
	if (x1_ < x2_) {   
		left_ = x1; right_ = x2;
	}
	else {
		left_ = x2; right_ = x1;
	}
	if (y1_ < y2_) {
		top_ = y1; buttom_ = y2;
	}
	else {
		top_ = y2; buttom_ = y1;
	}
}

bool MyShape::isShapeArea(MyEvent e) { //도형의 에어리어를 판단합니다.
	return e.x_ >= left_ && e.x_ <= right_
		&& e.y_ >= top_ && e.y_ <= buttom_;
}

bool MyShape::isSelectShape(int x1, int y1, int x2, int y2) { //도형이 선택됬는지 확인합니다.
	return x1 <= left_ && y1 <= top_
		&& x2 >= right_ && y2 >= buttom_;
}

void MyShape::setColar(COLORREF p, COLORREF b,int lt) {
	Pen_color_ = p;
	line_ttick = lt;
	thePen_ = CreatePen(PS_SOLID, lt, RGB(GetRValue(p), GetGValue(p), GetBValue(p)));
	Brush_color_ = b;
	theBrush_ = CreateSolidBrush(RGB(GetRValue(b), GetGValue(b), GetBValue(b)));
}

void MyShape::SaveShape(FILE* fp) {
	fprintf(fp, "%d ", x1_);   fprintf(fp, "%d ", y1_);  //좌표저장
	fprintf(fp, "%d ", x2_);   fprintf(fp, "%d ", y2_);
	fprintf(fp, "%d ", Pen_color_);   //색 저장
	fprintf(fp, "%d ", Brush_color_);
	fprintf(fp, "%d\n", line_ttick);
}

void MyShape::MoveShape(int x1, int y1, int x2, int y2) { //도형을 움직입니다.
	x1_ += (x2 - x1);   left_ += (x2 - x1);
	y1_ += (y2 - y1);   top_ += (y2 - y1);
	x2_ += (x2 - x1);   right_ += (x2 - x1);
	y2_ += (y2 - y1);   buttom_ += (y2 - y1);
}
