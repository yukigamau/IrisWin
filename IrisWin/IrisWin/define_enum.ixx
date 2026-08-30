// 将宏转换为枚举
// transform #define to enum
module;
#include <Windows.h>
export module IrisWin_define_enum;
import std;
import std_extra;
using std::initializer_list, std::uint;
using std::is_same_v;

export namespace IrisWin
{
	enum class EClassStyle :uint
	{
		vRedraw = CS_VREDRAW,
		hRedraw = CS_HREDRAW,

		// 允许双击
		// enable double-clicks
		DblClks = CS_DBLCLKS,

		// 拥有独立DC
		// have self DC
		ownDC = CS_OWNDC,
		// 整个类共享DC
		// all window under this
		// class using same DC
		classDC = CS_CLASSDC,
		// 继承父窗口DC
		// inherit parent window DC
		parentDC = CS_PARENTDC,

		noClose = CS_NOCLOSE,

		// 保存被遮挡区域的位图
		// save hidden area's bitmaps
		saveBits = CS_SAVEBITS,

		// 将窗口客户区在水平方向上以双字像素为边界对齐
		// align client part with 2 words pixels at horizontal direction
		byteAlignClient = CS_BYTEALIGNCLIENT,
		// 将整个窗口在水平方向上以双字像素为边界对齐
		// align window with 2 words pixels at horizontal direction
		byteAlignWindow = CS_BYTEALIGNWINDOW,

		// 让DLL的窗口类可以被其他程序使用
		// make window class in dll can be used by other programs
		globalClass = CS_GLOBALCLASS
	};

	class ClassStyle
	{
	public:
		template<typename... Enums>
		ClassStyle(Enums... args);

	private:
		uint style = 0x0;

	public:
		uint get() { return style; }
	};
}

template<typename... Enums>
IrisWin::ClassStyle::ClassStyle(Enums... args)
{
	static_assert((is_same_v<Enums, EClassStyle>&&...), "All arguments must be EClassStyle");

	style = 0x0;
	((style |= (uint)args), ...);

	if (!style)
		style |= (uint)EClassStyle::vRedraw | (uint)EClassStyle::hRedraw;
}