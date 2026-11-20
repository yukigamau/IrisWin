// 命名互斥锁的处理
module;
#include <Windows.h>
export module orchidWin_mutex;
import std;

export namespace orchidWin
{
	enum class CreateMutexRes
	{
		FAILED = -1L,
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

orchidWin::NamedMutex::~NamedMutex()
{
	if (handle)
		CloseHandle(handle);
}

orchidWin::CreateMutexRes orchidWin::NamedMutex::create(const std::wstring& name)noexcept
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