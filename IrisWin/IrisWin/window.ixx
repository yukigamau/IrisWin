// IrisWin的子模块，用于处理窗口相关类
// IrisWin's child module, using for
// handle classes of window.
module;
#include <Windows.h>
export module IrisWin_window;
import IrisWin_classes;
import IrisWin_define_enum;
import std_extra;

export namespace IrisWin
{
	// 用于窗口类处理
	// using for WNDCLASS
	class IWndCls
	{
	public:
		IWndCls(IHInstance hInstance, ILpCStr lpszClassName);

	private:
		// 注册后所有的操作将修改
		// if registed, all operations
		// will be changed
		bool ifRegisted = false;

		// WNDCLASS参数
		// WNDCLASS parameters
		ClassStyle style;
		IWndProc lpfnWndProc;
		int cbClsExtra = 0;
		int cbWndExtra = 0;
		IHInstance hInstance = nullptr;
		IHIcon hIcon = nullptr;
		IHCursor hCursor = LoadCursor(NULL, IDC_CROSS);
		IHBrush hbrBackground = (IHBrush)GetStockObject(WHITE_BRUSH);
		ILpCStr lpszMenuName = NULL;
		ILpCStr lpszClassName;

	public:
		int regist();
	};
}

using namespace IrisWin;

IrisWin::IWndCls::IWndCls(IHInstance hInstance, ILpCStr lpszClassName)
	:hInstance{ hInstance }, lpszClassName{ lpszClassName }
{
}

int IrisWin::IWndCls::regist()
{
	WNDCLASS wndcls;
	wndcls.cbClsExtra = cbClsExtra;
	wndcls.cbWndExtra = cbWndExtra;
	wndcls.hbrBackground = hbrBackground;
	wndcls.hCursor = hCursor;
	wndcls.hIcon = hIcon;
	wndcls.hInstance = hInstance;	//应用程序实例句柄由WinMain 函数传进来
	wndcls.lpfnWndProc = lpfnWndProc;
	wndcls.lpszClassName = lpszClassName;
	wndcls.lpszMenuName = lpszMenuName;
	wndcls.style = style.get();
	return RegisterClass(&wndcls);
}