add_library(Util STATIC Util.cpp)

target_include_directories(Util PUBLIC ${CMAKE_SOURCE_DIR})

target_compile_options(Util PRIVATE -Wall -Werror)