cmake_minimum_required (VERSION 3.30)

add_executable (example WIN32)
target_sources(example
    PRIVATE
        "main.cpp"
	PUBLIC
		FILE_SET CXX_MODULES FILES
            "MyApp.ixx"
)

target_compile_definitions (example PRIVATE UNICODE _UNICODE)
target_compile_features (example PRIVATE cxx_std_23)

# allow Chinese to be read correctly
if(MSVC)
    # tell MSVC we use utf-8
    target_compile_options(example PRIVATE /utf-8)
endif()

target_link_libraries (example PRIVATE orchidWin)
