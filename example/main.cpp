#include <Windows.h>
import IrisWin;
import MyApp;

int CALLBACK WinMain(
    _In_ HINSTANCE hIns,
    _In_opt_ HINSTANCE hPreIns,
    _In_ LPSTR lpCmdLine,
    _In_ int ncmdshow)
{
    Example::MyApp myApp;

    using IrisWin::CreateMutexRes;
    auto res = myApp.createMutex(L"Local\\IrisWin.Example.SingleInstance");

    switch (res)
    {
    case CreateMutexRes::SUCCESS:
        do
        {
        } while (0);
        break;

    case CreateMutexRes::ALREADY_EXISTS:
        do
        {
        } while (0);
        break;

    case CreateMutexRes::FAILED:
        do
        {
        } while (0);
        break;
    }

    return 0;
}