add_library(binary_tree_node SHARED "${CMAKE_CURRENT_LIST_DIR}/binary_tree_node.cpp")
target_include_directories(binary_tree_node PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/")

add_library(binary_tree SHARED "${CMAKE_CURRENT_LIST_DIR}/binary_tree.cpp")
target_include_directories(binary_tree PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_link_libraries(binary_tree binary_tree_node)
