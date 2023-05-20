#pragma once
#include <Windows.h>
#include <string>
#define TRUE 1
#define FALSE 0
class MyEvent{
public:
	MyEvent(UINT message, WPARAM wParam, LPARAM lParam);
	//맴버함수
	bool isContolPressed(); // Contol 클릭 
	bool isShiftPressed();  // Shift 클릭
	bool isMouseEvent();    // Event - 마우스 클릭
	char kepPressed();
	//맴버변수
	UINT event_type_;
	WPARAM lParam_;
	LPARAM wParam_;
	int x_, y_;
};

void Debug(int);
void Debug(int, int);
void Debug(int,int,int,int);

void Debug(const char*);
void Debug(int, const char*);
void Debug(const char* ,int, const char*);

std::string Comma(long long int);
std::string Comma(long double);
