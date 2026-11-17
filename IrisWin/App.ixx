module;
#include <Windows.h>
export module IrisWin_App;

import std;
import IrisWin_HINSTANCE;
import IrisWin_Mutex;

export namespace IrisWin
{
	// 一个程序的入口
	// 实际使用时，应当对其进行继承，定制一个App类
	class App
	{
	protected:
		const HINSTANCE hIns;
		NamedMutex nm;

	public:
		App();

#pragma region mutex的处理
	public:
		CreateMutexRes createMutex(const std::wstring& name);
#pragma endregion

	};
}

IrisWin::App::App()
	:hIns{ getHIns() }
{
}

IrisWin::CreateMutexRes IrisWin::App::createMutex(const std::wstring& name)
{
	return nm.create(name);
}
