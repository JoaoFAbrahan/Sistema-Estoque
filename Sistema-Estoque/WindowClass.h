#pragma once
#include<Windows.h>

class WindowClass
{
public:
	virtual void create_Window() = 0;
	virtual void destroy_Window() = 0;

	void init_Window();
	void finish_Window();

protected:
	HWND hwnd;

private:
	WNDCLASS wc = {};
};

