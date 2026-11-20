import orchidWin;

export module MyApp;
import std;

export namespace Example
{
	class MyApp :public orchidWin::App
	{
	public:
		auto createMutex(const std::wstring& name) { return App::createMutex(name); }
	};
}