module;
#include <Windows.h>
export module orchidWin_app;

import std;
import orchidWin_hinstance;
import orchidWin_mutex;

export namespace orchidWin
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

orchidWin::App::App()
	:hIns{ getHIns() }
{
}

orchidWin::CreateMutexRes orchidWin::App::createMutex(const std::wstring& name)
{
	return nm.create(name);
}
