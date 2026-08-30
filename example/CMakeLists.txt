# CMakeList.txt: example 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

# 将源代码添加到此项目的可执行文件。
add_executable (example WIN32 "example.cpp")

target_sources(example
	PRIVATE
	FILE_SET CXX_MODULES
		FILES "glob.ixx"
)

set_property(TARGET example PROPERTY CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)

target_link_libraries(example PRIVATE std)
target_link_libraries(example PRIVATE IrisWin)