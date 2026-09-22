# CMakeList.txt: std 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

# 将源代码添加到此项目的可执行文件。
add_library (std)
target_sources(std
	PUBLIC
		FILE_SET CXX_MODULES FILES
		"std.ixx")

set_property(TARGET std PROPERTY CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_MODULE_STD 1)