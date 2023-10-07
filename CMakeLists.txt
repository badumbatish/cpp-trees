cmake_minimum_required(VERSION 3.14)
project(cpp_trees)

# Whenever we build shared libraries on Windows, we need this.
# https://stackoverflow.com/questions/1941443/cmake-linking-against-shared-library-on-windows-error-about-not-finding-lib-fi#comment85482727_1943631
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing() # Should only be in the root folder's CMakeLists.txt
include(GoogleTest) # Should only be in the root folder's CMakeLists.txt

include("${CMAKE_CURRENT_LIST_DIR}/src/CMakeLists.txt")
