include("${CMAKE_CURRENT_SOURCE_DIR}/binary_tree/CMakeLists.txt")



# Just for testing a dummy file
enable_testing()

add_executable(
        hello_test
        src/hello_test.cpp
)
target_link_libraries(
        hello_test
        GTest::gtest_main
)


include(GoogleTest)
gtest_discover_tests(hello_test)