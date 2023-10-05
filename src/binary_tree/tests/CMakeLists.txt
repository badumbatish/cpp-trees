# Test-only file

add_executable(tests ${CMAKE_CURRENT_LIST_DIR}/simple_test.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test_insert.cpp
        ${CMAKE_CURRENT_LIST_DIR}/test_deletion.cpp)

target_include_directories(tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(tests
        GTest::gtest_main
        binary_tree)
gtest_discover_tests(tests)