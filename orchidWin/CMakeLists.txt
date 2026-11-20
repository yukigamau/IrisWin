# CMakeLists: orchidWin CMake

project ("orchidWin")
add_library (orchidWin)
target_sources (orchidWin
	PUBLIC
		FILE_SET CXX_MODULES FILES
			"orchidWin.ixx"
			"Win/hinstance.ixx" "Win/mutex.ixx" "Win/text.ixx"
			"App.ixx"
)

target_compile_definitions (orchidWin PRIVATE UNICODE _UNICODE)
target_compile_features (orchidWin PRIVATE cxx_std_23)