cmake_minimum_required (VERSION 3.30)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)

project ("example")
# need WIN32 to compile as a windows program
add_executable (example WIN32 "main.cpp")
target_sources(example
	PUBLIC
		FILE_SET CXX_MODULES FILES
            "MyApp.ixx"
)

# set ANSI or UNICODE
target_compile_definitions (example PRIVATE UNICODE _UNICODE)

# allow Chinese to be read correctly
if(MSVC)
    # tell MSVC we use utf-8
    target_compile_options(example PRIVATE /utf-8)
endif()

target_link_libraries (example PRIVATE IrisWin)