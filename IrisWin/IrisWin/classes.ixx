// IrisWin的子模块，用于重命名原有类
// IrisWin's child module, using for
// renaming initial classes
module;
#include <Windows.h>
export module IrisWin_classes;

export namespace IrisWin
{
	typedef HBRUSH		IHBrush;
	typedef HCURSOR		IHCursor;
	typedef HICON		IHIcon;
	typedef HINSTANCE	IHInstance;
	using ILpCStr =	LPCSTR;
	using ILpStr =	LPSTR;
	typedef WNDPROC		IWndProc;

}