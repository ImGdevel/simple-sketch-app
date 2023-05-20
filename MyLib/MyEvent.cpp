#include "MyEvent.h"
#include <string>
#include <stdio.h>
using namespace std;
MyEvent::MyEvent(UINT message, WPARAM wParam, LPARAM lParam)
	:event_type_(message), wParam_(wParam), lParam_(lParam){
	x_ = LOWORD(lParam_);
	y_ = HIWORD(lParam_);
}

bool MyEvent::isContolPressed() {
	return wParam_ & MK_CONTROL;
}

bool MyEvent::isShiftPressed() {
	return wParam_ & MK_SHIFT;
}

char MyEvent::kepPressed() {
	return (TCHAR)wParam_;
}

bool MyEvent::isMouseEvent() {
	return event_type_ == WM_LBUTTONDOWN
		|| event_type_ == WM_LBUTTONUP
		|| event_type_ == WM_LBUTTONDBLCLK
		|| event_type_ == WM_RBUTTONDOWN
		|| event_type_ == WM_RBUTTONUP
		|| event_type_ == WM_LBUTTONDBLCLK;
}


///////////////////////디버그 메세지//////////////////////
void Debug(const char* s) {
	//static int seq = 1;
	char buf[128];
	sprintf_s(buf, "%s", s);
	OutputDebugStringA(buf);
}
void Debug(int a, int b, int c, int d) {
	Debug(a); Debug(b); Debug(c); Debug(d);
}
void Debug(int a, int b) {
	Debug(a); Debug(b);
}
void Debug(int n) {
	char buf[128];
	sprintf_s(buf, "%d ", n);
	Debug(buf);
}
void Debug(int n,const char* s) {
	char buf1[128];
	sprintf_s(buf1, "%d ", n);
	Debug(buf1);
	char buf2[128];
	sprintf_s(buf2, "%s", s);
	Debug(buf2);
}
void Debug(const char* s, int n, const char* s2) {
	char buf2[128];
	sprintf_s(buf2, "%s ", s);
	Debug(buf2);
	char buf1[128];
	sprintf_s(buf1, "%d ", n);
	Debug(buf1);
	char buf3[128];
	sprintf_s(buf3, "%s\n", s2);
	Debug(buf2);
	
}
std::string Comma(long long int n) {
	long long int value = n;
	int def = 0;  int mine = 0;
	std::string str;
	if (value < 0) {
		value = -value;
		mine = 1;
	}
	if (value == 0) {
		str = "0";
	}
	///////////////////////////////////
	int com = 0;
	while (value>0) {
		com++;
		str = to_string(value % 10) + str;
		value /= 10;
		if (value == 0) {
			break;
		}
		if (com == 3) {
			str = "," + str;
			com = 0;
		}
	}
	if (mine == 1) {
		str = "-" + str;
	}
	return str;
}
std::string Comma(long double n) {
	long long int value = n;
	double def = 0;  int mine = 0;
	std::string str;
	if (value < 0) {
		value = -value;
		mine = 1;
	}
	if (value == 0) {
		str = "0";
	}
	int com = 0;
	while (value > 0) {
		com++;
		str = to_string(value % 10) + str;
		value /= 10;
		if (value == 0) {
			break;
		}
		if (com == 3) {
			str = "," + str;
			com = 0;
		}
	}
	if (mine == 1) {
		str = "-" + str;
	}
	return str;
}