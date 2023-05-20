#pragma once
#include "Listener.h"
#include <Windows.h>
#include <iostream>
class MyFrame;
class MyListener :
	public Listener
{
public:
	virtual void processButtonEvent(MyWindows*) = 0;

};

