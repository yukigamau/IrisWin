module;
#include <Windows.h>
export module IrisWin_HINSTANCE;

export namespace IrisWin
{
	HINSTANCE getHIns()noexcept
	{
		return (HINSTANCE)GetModuleHandle(NULL);
	}
}