#include "TextDialogue.h"
TextDialogue::TextDialogue(HDC hdc, std::string str, int w, int h)
	: Dialogue(hdc, str, w, h) {
};

void TextDialogue::enterText(const char* s) {
	content_[line++] = s;
}

void TextDialogue::repaint() {
	if (State_) {
		Dialogue::repaint();
		int y = y_ + 40;
		for (int i = 0; i < line; i++) {
			TextOutA(hdc_, x_ + 20, y, content_[i], strlen(content_[i]));
			y += 25;
		}
	}
}