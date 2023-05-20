#include "TextPutDialogue.h"
#include "TextLabel.h"
TextPutDialogue::TextPutDialogue(HDC hdc, std::string str, int w, int h)
	: TextDialogue(hdc, str, w, h) {
	
}

bool TextPutDialogue::processMessage(MyEvent e) {
	if (State_) {
		if (e.event_type_ == WM_LBUTTONDOWN && text_lab->processMessage(e)) { //텍스트 눌렀으면 입력 모드
			Mode_text = TRUE;
		}
		else if (e.wParam_ == VK_RETURN) {
			Mode_text = FALSE;
		}
		else if (e.wParam_ == VK_BACK) {
			if (str_num >0) {
				str_[--str_num] = 0;
				text_lab->setTitle(str_);
				text_lab->repaint();
			}
		}
		else if (Mode_text && e.event_type_ == WM_CHAR) {
			str_[str_num++] = e.kepPressed();
			text_lab->setTitle(str_);
			text_lab->repaint();
		}
	}
	return TextDialogue::processMessage(e);
}

void TextPutDialogue::addTextLabel(TextLabel* p) {
	text_lab = p;
}

std::string TextPutDialogue::getTitle() {
	return text_lab->getTitle();
}

void TextPutDialogue::repaint() {
	if (State_) {
		TextDialogue::repaint();
		text_lab->setPointX(x_ + 30);  text_lab->setPointY(y_ + hight_ - 80);
		text_lab->repaint();
	}
}

