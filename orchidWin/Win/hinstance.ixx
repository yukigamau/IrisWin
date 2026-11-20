module;
#include <Windows.h>
export module orchidWin_hinstance;

export namespace orchidWin
{
	HINSTANCE getHIns()noexcept
	{
		return (HINSTANCE)GetModuleHandle(NULL);
	}
}