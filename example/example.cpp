#include <Windows.h>

int WinMain(
	_In_ HINSTANCE hIns,
	_In_opt_ HINSTANCE hPreIns,
	_In_ LPSTR lpCmdLine,
	_In_ int ncmdshow)
{
	MessageBox(nullptr, "这个是新版的吗？", "想要个新版的", MB_ICONWARNING);
	
}