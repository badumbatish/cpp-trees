# Test-only file

add_executable(tests ${CMAKE_CURRENT_LIST_DIR}/simple_test.cpp)


target_link_libraries(tests
        GTest::gtest_main)
gtest_discover_tests(tests)