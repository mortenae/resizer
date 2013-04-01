/*
	The MIT License

	Copyright (c) 2013 Morten A. Erlandsen <animorten@gmail.com>

	Permission is hereby granted, free of charge, to any person obtaining a copy of
	this software and associated documentation files (the "Software"), to deal in
	the Software without restriction, including without limitation the rights to
	use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
	the Software, and to permit persons to whom the Software is furnished to do so,
	subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
	FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
	COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
	IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
	CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <stdio.h>
#include <windows.h>

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND handle;
	RECT desktop;
	int desktop_x, desktop_y, desktop_width, desktop_height;
	int window_x, window_y, window_width, window_height;

	Sleep(1000);
	handle = GetForegroundWindow();

	if(handle == NULL)
	{
		MessageBeep(MB_ICONERROR);
		return 1;
	}

	SystemParametersInfo(SPI_GETWORKAREA, 0, &desktop, 0);

	desktop_width = desktop.right - desktop.left;
	desktop_height = desktop.bottom - desktop.top;
	desktop_x = desktop.left;
	desktop_y = desktop.top;

	window_width = desktop_width * 3 / 4;
	window_height = desktop_height * 3 / 4;
	window_x = desktop_x + (desktop_width - window_width) / 2;
	window_y = desktop_y + (desktop_height - window_height) / 2;

	SetWindowPos(handle, HWND_DESKTOP, window_x, window_y, window_width, window_height, 0);

	return 0;
}
