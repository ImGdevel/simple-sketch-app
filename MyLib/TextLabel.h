#pragma once
#include "MyWindows.h"
#define TEXTMODE 0
#define INTMODE 1
#define DOUBLEMODE 2

class TextLabel :
	public MyWindows
{
public:
	TextLabel(HDC, std::string, int, int);  //기본 텍스트 라벨
	TextLabel(HDC, std::string, int, int, int); //모드에 따라 출력변환
	virtual bool processMessage(MyEvent);
	virtual void setMode(int);
	virtual void setValue(long long int);
	virtual void setValued(long double);
	virtual long long int getValue()const;
	virtual long double getValued()const;
	virtual void repaint();

protected:
	int Mode_ = 0; //모드에 따라 출력변환 [ 0 스트링 | 1 정수  | 2 실수 ]
	long long int value_;
	long double valued_;
};

