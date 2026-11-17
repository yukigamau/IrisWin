// 命名互斥锁的处理
module;
#include <Windows.h>
export module IrisWin_Mutex;
import std;

export namespace IrisWin
{
	enum class CreateMutexRes
	{
		FAILED = -1,
		ALREADY_EXISTS = ERROR_ALREADY_EXISTS,
		SUCCESS = ERROR_SUCCESS
	};

	class NamedMutex
	{
		std::wstring name;
		HANDLE handle = nullptr;

	public:
		~NamedMutex();

	public:
		CreateMutexRes create(const std::wstring& name)noexcept;
	};
}

IrisWin::NamedMutex::~NamedMutex()
{
	if (handle)
		CloseHandle(handle);
}

IrisWin::CreateMutexRes IrisWin::NamedMutex::create(const std::wstring& name)noexcept
{
	this->name = name;

	handle = CreateMutexW(
		nullptr,
		FALSE,
		name.c_str()
	);

	if (handle == nullptr)
		return CreateMutexRes::FAILED;

	DWORD error = GetLastError();
	return CreateMutexRes(error);
}