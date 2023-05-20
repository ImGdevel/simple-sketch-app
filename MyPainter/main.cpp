#include <iostream>
#include "Frame.h"
#include "MyFrame.h"

int main() {
	try {
		Frame* win = new MyFrame(L"샘플"); //윈도우 생성
		win->run(); //런타임 실행
	}
	catch (int n) {
		std::cerr << "Error" << std::endl;
	}
}
