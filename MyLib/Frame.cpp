#include "Frame.h"
//전역변수(포인터)
static Frame* globalFrame = NULL;  // 다른 파일에서는 사용할 수 없다.

// 전역함수로는 윈도 메시지 처리 함수가 있다.
LRESULT CALLBACK WndProc(HWND Hw, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{	
	case WM_CREATE:
	{
		if (globalFrame)
			globalFrame->setHwnd(Hw);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN: case WM_LBUTTONDBLCLK: case WM_LBUTTONUP:
	case WM_RBUTTONDOWN: case WM_RBUTTONDBLCLK: case WM_RBUTTONUP:
	case WM_CHAR:        case WM_SIZE:          case WM_MOUSEMOVE:
	//case WM_KEYDOWN:     case WM_KEYUP:
	{
		//프로세스 메세지 실행
		if (globalFrame)
			globalFrame->processMessage(MyEvent(Msg, wParam, lParam));
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(Hw, &ps);
		if (globalFrame)
			globalFrame->repaint();
		EndPaint(Hw, &ps);
	}
	break;
	default: return DefWindowProc(Hw, Msg, wParam, lParam);
	}
}

////////////////////Frmae 함수를 정의합니다.////////////////////////////
Frame::Frame(std::wstring title, int width, int height) {
	hInst_ = GetModuleHandle(NULL);
	FreeConsole(); // No console
	// Register win class
	WNDCLASSEX Wc;

	Wc.cbSize = sizeof(WNDCLASSEX);
	Wc.style = CS_HREDRAW | CS_VREDRAW;
	Wc.lpfnWndProc = WndProc;
	Wc.cbClsExtra = 0;
	Wc.cbWndExtra = 0;
	Wc.hInstance = hInst_;
	Wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	Wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	Wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	Wc.lpszMenuName = NULL;
	Wc.lpszClassName = L"MyWin";
	Wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&Wc);

	hWnd_ = CreateWindowExW(WS_EX_TOPMOST, L"MyWIn", (WCHAR*)title.c_str(),
		WS_OVERLAPPED |
		WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | // 종료 최소화 최대화 아이콘
		WS_THICKFRAME,  // resize가 가능하게
		50, 50, width, height, // x, y, width, height
		NULL, NULL, hInst_, NULL);  // Parent, Menu, instance handle, lpParam
	if (!hWnd_) throw 0;

	ShowWindow(hWnd_, SW_SHOW);
	UpdateWindow(hWnd_); 
	SetFocus(hWnd_);
}

Frame::Frame(std::wstring title) {
	globalFrame = this;
	Frame(title, 900, 600);
	hdc_ = GetDC(hWnd_);
}

void Frame::run() {
	HACCEL hAccelTable = LoadAccelerators(hInst_, MAKEINTRESOURCE(IDI_APPLICATION));
	MSG msg;

	// 기본 메시지 루프입니다:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}
////////////////////////////////////////////////////////////////////////
bool Frame::processMessage(MyEvent e) {
	if (e.event_type_ == WM_SIZE) { //윈도우의 크기 지정
		RECT rect;
		GetClientRect(hWnd_, &rect);
		widht_ = rect.right; hight_ = rect.bottom;
		arrangeLayout();
	}
	return Container::processMessage(e);
}

void Frame::processButtonEvent(Button* b) {
	repaintAll();
}

void Frame::setFont(int size, COLORREF c) { //글자크기, 폰트색
	HFONT font = CreateFont(size, 0, 0, 0, FW_BOLD, 0, 0, 0, HANGEUL_CHARSET,
		10, 10, 10, 0, L"바탕");
	::SelectObject(hdc_, font);
	::SetTextColor(hdc_, c);           //글자 색
	::SetBkMode(hdc_, TRANSPARENT);    //폰트 색
}

void Frame::repaint() {
	PaintColorB();
	Container::repaint();
	PaintColorA();
}

HDC GetHDC() {
	return globalFrame->getHdc();
}