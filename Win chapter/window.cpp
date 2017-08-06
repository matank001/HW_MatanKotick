#include <iostream>
#include <string>
#include <Windows.h>

#define INFO_BUFFER_SIZE 50000
#define FILE_NAME "log.txt"
#define TIME_FORMAT "hh:mm:ss"

//the callback window function
LRESULT CALLBACK wndProc(HWND hand, UINT msg, WPARAM wParam, LPARAM lparam){
	
	//count clicks
	static int cnt = 0;

	//if left mouse button was clicked - PART 1
	if (msg == WM_LBUTTONDOWN){
		SetWindowText(hand, std::to_string(cnt).c_str());
	}
	//if right mouse button was clicked 
	if (msg == WM_RBUTTONDOWN){
		cnt++;
	}
	//if enter was clicked - PART 2
	if (msg == WM_KEYDOWN && wParam == VK_RETURN){

		//create(not exists)/open(exists) file
		HANDLE file_handle;
		file_handle = CreateFile(FILE_NAME, GENERIC_ALL, 0, NULL, OPEN_EXISTING, 0, NULL);
		if (file_handle == INVALID_HANDLE_VALUE){
			file_handle = CreateFile(FILE_NAME, GENERIC_ALL, 0, NULL, OPEN_ALWAYS, 0, NULL);
		}
		
		SetFilePointer(file_handle, 0, NULL, FILE_END); //write at end of file

		SYSTEMTIME LocalTime;
		GetLocalTime(&LocalTime);
		char buff[INFO_BUFFER_SIZE];
		int buff_length = (std::string(TIME_FORMAT)).length();
		GetTimeFormat(LOCALE_CUSTOM_DEFAULT, 0, &LocalTime, TIME_FORMAT, buff, buff_length); //enter time to buffer according to TIME_FORMAT
		LPDWORD byteW = NULL; //bytes that was written to file
		buff[buff_length] = '\r';
		buff[buff_length+1] = '\n'; //end of line
		WriteFile(file_handle, buff, buff_length+2, byteW, NULL);
		CloseHandle(file_handle);
	}
	//when window closes - PART 3
	if (msg == WM_DESTROY){
		char buff[INFO_BUFFER_SIZE];
		GetWindowsDirectory(buff, INFO_BUFFER_SIZE);
		MessageBox(NULL, buff, "found!", MB_OK | MB_ICONWARNING); //send the windows folder path
		PostQuitMessage(0); //quit window
	}
	return DefWindowProc(hand, msg, wParam, lparam);
}

int WINAPI WinMain(HINSTANCE h, HINSTANCE h2, LPSTR cmd, int cmdShow){
	WNDCLASS wc = { 0 };
	HWND window_h = NULL;
	MSG msg = { 0 };
	
	//class settings
	wc.style = 0;
	wc.lpfnWndProc = wndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszClassName = "window class";
	wc.lpszMenuName = NULL;
	wc.hInstance = h;

	int k = RegisterClass(&wc);
	window_h = CreateWindow("window class", "hello world", WS_OVERLAPPEDWINDOW, 0, 0, 300, 300, NULL, NULL, h, NULL);
	ShowWindow(window_h, cmdShow);

	//main event loop
	while (GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}