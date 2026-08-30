# 项目介绍 Project Introduction
描述语言将以中文在上英语在下的方式呈现。  
Introduction will be presented by a way, Chinese on with English down.

这是一个以win32为基本框架的图形化封装库。  
This is a library based on win32 for GUI framework.

## IrisWin的设计目的 Design Orientation of IrisWin
IrisWin设计于简化Win32的开发，最终形成了一个新的开发框架，实现微小体积、简单画面的软件。  
IrisWin is design for ease the development of Win32, and evolve into a new framework, aiming at small size and simple interface softwares.

但这不是说IrisWin不能实现较大体积、精致画面的软件。但这更适合使用其他更成熟的图形库。  
But that not means IrisWin could not be used for big and beatiful software. Nevertheless, is better to use other stronger GUI libraries.

## 框架结构 Frame Structure
IApp为最高级框架，需要传入hIns、lpCmdLine、ncmdShow以实现初始化。  
The highest level of the structure is IApp, needing hIns, lpCmdLine, ncmdShow to initialize.

IApp是IWin的容器。IWin是最高级的显示单元，表现为一个窗口。  
IApp includes IWin. IWin is highest expressiong unit, showing as a window.

IWin的窗口内容为IPage，没有IPage的IWin无法显示出来。  
The context in IWin's window is IPage. Without IPage, IWin couldn't show out.

ILayout用于IPage的布局自动处理，是IrisWin引入的新控件，不使用句柄。  
ILayout is designed for auto control the layout in IPage, is a new control introduced by IrisWin, and doesn't use hWnd.

所有的控件放置在IPage上，如果要自绘标题栏，则意味着原来标题栏的控件放置在IPage上，而不是让IPage保留Windows的原生标题栏。  
All controls are put on IPage. If wanting to self-draw a title bar, should put controls for title bar on IPage, but not save initial title bar from Windows on IPage.
