import IrisWin;

export module MyApp;
import std;

export namespace Example
{
	class MyApp :public IrisWin::App
	{
	public:
		auto createMutex(const std::wstring& name) { return App::createMutex(name); }
	};
}