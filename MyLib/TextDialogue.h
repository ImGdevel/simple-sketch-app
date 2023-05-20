#pragma once
#include "Dialogue.h"
class TextDialogue :
	public Dialogue
{
public:
	TextDialogue(HDC, std::string, int, int);
	virtual void enterText(const char*);
	virtual void repaint();
protected:
	const char* content_[20];
	int line;
};