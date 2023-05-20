#pragma once
#include "MyEvent.h"
#include <string>
class Frame;
class ToolBar;
class Button;
class MyWindows
{
public:
	MyWindows();
	MyWindows(HDC, std::string, int, int);
	MyWindows(HDC, std::string, int, int, COLORREF, COLORREF);
	MyWindows(HDC, std::string, int, int, int, int);
	virtual bool processMessage(MyEvent);       // 메세지를 처리합니다.
	virtual bool isAccess(MyEvent);             // 엑세스 정보를 처리합니다.
	virtual void processButtonEvent(Button* b); // 버튼에 이벤트를 처리합니다.
	virtual void repaint() = 0;                 // 출력합니다.
	virtual void setParents(MyWindows*);        // 상위 포인터를 지정합니다.
	virtual void movePlace(int, int, int, int); // 객체를 위치를 변경합니다.
	/*__ 엑세서 함수, set함수 __________________________________________*/
	virtual int getWidth()const;  virtual int getHight()const;
	virtual int getPointX()const; virtual int getPointY()const;
	virtual void setWidth(int);   virtual void setHight(int);
	virtual void setPointX(int);  virtual void setPointY(int);
	virtual int getState()const;  virtual void setState(int);
	virtual void setTitle(std::string s);
	virtual std::string getTitle() const;
	virtual void setColor(COLORREF, COLORREF);
	virtual void PaintColorB();   virtual void PaintColorA();
	virtual COLORREF getColor();
	virtual void repaintAll();
	virtual HWND getHwnd()const;  virtual HDC getHdc()const;
	virtual void setHwnd(HWND);
	
	
	MyWindows* pressed_ = FALSE;  //버튼 Up/Down
protected:
	MyWindows* parents_; //상위 포인터
	std::string title_;  //이름
	int x_, y_;			 //x, y 좌표
	int widht_, hight_;  //너비,높이
	int State_ = FALSE;  //상태
	COLORREF Pen_color_ = RGB(0,0,0);        //태두리색
	COLORREF Brush_color_ = RGB(255,255,255);//내부색
	HPEN oldPen_, newPen_;
	HBRUSH oldBrush_, newBrush_;


	//핸들
	HINSTANCE hInst_;
	HWND hWnd_ = NULL;
	HDC hdc_ = NULL;
};
