#pragma once
#include"WindowClass.h"
class App : virtual public WindowClass
{
	void create_Window() override;
	void destroy_Window() override;
};

