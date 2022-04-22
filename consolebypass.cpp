void ConsoleBypass(const char* Title) //get the console title
{
	DWORD Console;
	VirtualProtect((PVOID)& FreeConsole, 1, PAGE_EXECUTE_READWRITE, &Console); //read only
	*(BYTE*)(&FreeConsole) = 0xC3;
	AllocConsole(); //detach from current console
	SetConsoleTitleA(Title); //rename the console title
	freopen("CONOUT$", "w", stdout); //open
	freopen("CONIN$", "r", stdin);
	::SetWindowPos(ConsoleHandle, HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW); //settings for the console
	::ShowWindow(GetConsoleWindow(), SW_TOPMOST); //top most console and pause
}
