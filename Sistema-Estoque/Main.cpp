/*
	######################################################################
	##########                SISTEMA DE ESTOQUE                ##########
	######################################################################

	  Sistema de estoque em C++ desenvolvido com o objetivo de estudo de 
	Orienta��o a Objetos e utiliza��o de Interface Gr�fica da biblioteca
	<Windows.h>.

	DESENVOLVEDORES:		Jo�o Felipe Abrahan,
							Jorge Calligopoulo.

	DATA DESENVOLVIMENTO:	23/01/2021 at� XX/XX/2021.
	VERS�O DA LINGUAGEM:	C++17.
	TIPO DE LICEN�A:		MIT.
*/
#include"Headers.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow) 
{
	//Criar um objeto janela


	//Loop messege da janela
	MSG msg = {};

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

LRESULT CALLBACK WindowsProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		//Adicionar os botoes e etc

		break;
	case WM_COMMAND:
		//Verifica oque foi selecionado

		break;
	case WM_DESTROY:
		//Encerra o programa
		PostQuitMessage(0);

		break;
	case WM_PAINT:
		//Colore a janela
		PAINTSTRUCT paintWindow;
		HDC hdc = BeginPaint(hwnd, &paintWindow);

		FillRect(hdc, &paintWindow.rcPaint, (HBRUSH)(COLOR_WINDOW + 2)); //Pinta o interior da janela
		EndPaint(hwnd, &paintWindow);

		break;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}