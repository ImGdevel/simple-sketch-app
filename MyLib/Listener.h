#pragma once
class MyWindows;
class Listener
{
public:
	virtual void processButtonEvent(MyWindows*) = 0;
};

