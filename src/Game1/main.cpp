/*

Entry point to Game1 game
author: Travis Primm
*/
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include "..\ssyLib\Sys\ssyDefines.h"
#include "..\ssyLib\Managers\SSYGraphicsManager.h"

#ifdef RENDER_OPENGL
int main(int argc, char **argv)
{
	//Parse cmd args




	bool bQuitGame = false;

	SSY::SSYGraphicsManager::get().Setup();

	do
	{
		//Main game loop
	}while(!bQuitGame);
}

#endif




#ifdef RENDER_DX
//-----------------------------------------------------------------------------
// Name: MsgProc()
// Desc: The window's message handler
//-----------------------------------------------------------------------------
LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
		ValidateRect(hWnd, NULL);
		return 0;
	case WM_INPUT: 
	{
		UINT dwSize = 40;
		static BYTE lpb[40];
	
		GetRawInputData((HRAWINPUT)lParam, RID_INPUT, 
						lpb, &dwSize, sizeof(RAWINPUTHEADER));
	
		RAWINPUT* raw = (RAWINPUT*)lpb;
	
		if (raw->header.dwType == RIM_TYPEMOUSE) 
		{
			int xPosRelative = raw->data.mouse.lLastX;
			int yPosRelative = raw->data.mouse.lLastY;
			//ITP485::GraphicsDevice::get().GameCamera.OnMouseMovement(xPosRelative,yPosRelative);
		} 
		return 0;
	}
	case WM_ACTIVATE:
		//if(wParam==WA_INACTIVE)
		//{
		//	ITP485::GameWorld::get().SetPaused(true);
		//}
		//else
		//{
		//	ITP485::GameWorld::get().SetPaused(false);
		//}
		return 0;
	}


	return DefWindowProc(hWnd, msg, wParam, lParam);
}

INT WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, LPWSTR, INT)
{
		UNREFERENCED_PARAMETER(hInst);

	// Register the window class
	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		"ITP485 Game", NULL
	};
	RegisterClassEx(&wc);


	// Create the application's window
	HWND hWnd = CreateWindow("ITP485 Game", "ITP485 Game Engine",
		WS_OVERLAPPEDWINDOW, 100, 100, 1024, 768,
		NULL, NULL, wc.hInstance, NULL);

	// Register Mouse Device
	#ifndef HID_USAGE_PAGE_GENERIC
	#define HID_USAGE_PAGE_GENERIC         ((USHORT) 0x01)
	#endif
	#ifndef HID_USAGE_GENERIC_MOUSE
	#define HID_USAGE_GENERIC_MOUSE        ((USHORT) 0x02)
	#endif

	RAWINPUTDEVICE Rid[1];
	Rid[0].usUsagePage = HID_USAGE_PAGE_GENERIC; 
	Rid[0].usUsage = HID_USAGE_GENERIC_MOUSE; 
	Rid[0].dwFlags = RIDEV_INPUTSINK;   
	Rid[0].hwndTarget = hWnd;
	RegisterRawInputDevices(Rid, 1, sizeof(Rid[0]));

	// Setup our GameWorld and GraphicsDevice singletons
	//ITP485::GraphicsDevice::get().Setup(hWnd);
	//ITP485::GameWorld::get().Setup();
	//// Load Gameworld
	//ITP485::GameWorld::get().LoadLevel("level.ini");

	// Show the window
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);

	//Store Frequency of CPU
	LARGE_INTEGER freq,before,after;
//	float timestep;
	QueryPerformanceFrequency(&freq); // Store frequency in freq
	QueryPerformanceCounter(&before); // Store counter in before
	QueryPerformanceCounter(&after); // Store counter in after
	// enter the main game loop
	bool bQuit = false;
	int tempvalue = SOMEDLL; 
	while (!bQuit)
	{
		////calculate delta time and store in timestep
		//before = after;
		//QueryPerformanceCounter(&after); // Store counter in after
		//timestep = (after.QuadPart - before.QuadPart)/static_cast<float>(freq.QuadPart);

		//// Update the game world based on delta time
		//ITP485::GameWorld::get().Update(timestep);

		//// Render this frame
		//ITP485::GraphicsDevice::get().Render();

		//MSG msg;
		//while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
		//{
		//	TranslateMessage(&msg);
		//	DispatchMessage(&msg);
		//	if (msg.message == WM_QUIT)
		//	{
		//		bQuit = true;
		//		break;
		//	}
		//}
		break;
	}

	//// Cleanup the GameWorld and GraphicsDevice singletons
	//ITP485::GraphicsDevice::get().Cleanup();
	//ITP485::GameWorld::get().Cleanup();

	UnregisterClass("ITP485 Game", wc.hInstance);
	return 0;

}
#endif //RENDER_DX