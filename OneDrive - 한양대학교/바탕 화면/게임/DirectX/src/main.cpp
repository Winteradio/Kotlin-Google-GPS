#include <windows.h>
#include "Log.h"

LRESULT CALLBACK WndProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
	switch( msg )
	{
		case WM_CLOSE :
		{
			PostQuitMessage( 69 );
			break;
		}

		case WM_KEYDOWN :
		{
			if ( wParam == 'F' )
			{
				SetWindowText( hWnd, "Respects");
			}
			break;
		}

		case WM_KEYUP :
		{
			if ( wParam == 'F' )
			{
				SetWindowText( hWnd, "Dangerfiled" );
			}
			break;
		}
	}
	return DefWindowProc( hWnd, msg, wParam, lParam );
}

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow )
{
	const char* pClassName = "Create Window";

	// Register window Class
	WNDCLASSEX wc = {0};
	wc.cbSize = sizeof( wc );
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;

	RegisterClassEx( &wc );

	// Create Window Instance
	HWND hWnd = CreateWindowEx(
		0, pClassName,
		"Happy Hard Window",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr
		);

	// Show the damn Window
	ShowWindow( hWnd, SW_SHOW );

	// Message pup
	MSG msg;
	BOOL gResult;
	while ( ( gResult = GetMessage( &msg, nullptr, 0, 0 ) )  > 0 )
	{
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}

	if ( gResult == -1 )
	{
		return -1;
	}
	else
	{
		msg.wParam;
	}

	printf(" Done \n");
	return 0;
}