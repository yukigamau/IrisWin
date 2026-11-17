# CMakeLists: IrisWin CMake
cmake_minimum_required (VERSION 4.3.0)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)


project ("IrisWin")
add_library (IrisWin)
target_sources (IrisWin
	PUBLIC
		FILE_SET CXX_MODULES FILES
			"IrisWin.ixx"
			"Win/HINSTANCE.ixx" "Win/Mutex.ixx" "Win/Text.ixx"
			"App.ixx"
)

target_compile_definitions (IrisWin PRIVATE UNICODE _UNICODE)

target_link_libraries (IrisWin PRIVATE std)