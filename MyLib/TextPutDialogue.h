#pragma once
#include "TextDialogue.h"
class TextLabel;
class TextPutDialogue :
	public TextDialogue
{
public:
	TextPutDialogue(HDC, std::string, int, int);
	virtual bool processMessage(MyEvent);
	virtual void addTextLabel(TextLabel*);
	virtual std::string getTitle();
	virtual void repaint();

protected:
	char str_[128];
	int str_num = 0;
	int Mode_text = FALSE;
	TextLabel* text_lab;
};

