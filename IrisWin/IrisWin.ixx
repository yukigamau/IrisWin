module;
export module IrisWin;
export import IrisWin_classes;
export import IrisWin_define_enum;
export import IrisWin_window;

#pragma warning(push)
#pragma warning(disable : 5244)

// 方便随时用windows.h的东西
// convenient using sth in windows.h
#include <Windows.h>

export namespace IrisWin
{
	// 封装windows常用参数
	// encapsulate windows common used parameters
	struct IWinParam
	{
	public:
		HWND hWnd;		// 窗口句柄		handle to window
		UINT uMsg;		// 消息标识符	message identifier
		WPARAM wParam;	// 第一消息参数	first message parameter
		LPARAM lParam;	// 第二消息参数	second message parameter
	};
}

#pragma warning(pop)