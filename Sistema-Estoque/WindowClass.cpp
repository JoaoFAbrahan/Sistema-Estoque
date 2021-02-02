#include "WindowClass.h"


//Ponteio global da classe
WindowClass* window = nullptr;


LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_CREATE:
		window->create_Window();

		break;
	case WM_DESTROY:
		window->destroy_Window();
		PostQuitMessage(0);

		break;
	}

	return DefWindowProc(hwnd, msg, wparam, lparam);
}

void WindowClass::init_Window()
{
	//Cria um nome para servir como identificador da classe
	LPCWSTR windowClassName = L"WindowClass";

	//Instancia classe da janela
	this->wc.style = CS_DBLCLKS;
	this->wc.lpfnWndProc = &WindowProcedure;
	this->wc.hInstance = NULL;
	this->wc.lpszClassName = windowClassName;

	//Registra a classe no sistema
	RegisterClass(&this->wc);
	window = this;

	//Cria a janela
	this->hwnd = CreateWindowExW(
		0,
		windowClassName,
		L"Teste janela",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		nullptr,
		nullptr,
		nullptr,
		this
	);

	//Apresenta a janela
	ShowWindow(this->hwnd, SW_SHOW);
	UpdateWindow(this->hwnd);

	//Loop da janela
	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void WindowClass::finish_Window()
{
	UnregisterClass(this->wc.lpszClassName, this->wc.hInstance);
}
