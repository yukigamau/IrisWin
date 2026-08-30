module;

#define _BUILD_STD_MODULE

// 传统C头文件

// <intrin.h>定义一些不属于extern "C"规范的东西

export module std;

// 防警告
#pragma warning(push)
#pragma warning(disable : 5244)

// C++头文件
#include <iostream>

// C++的C功能库

// 复原警告
#pragma warning(pop)