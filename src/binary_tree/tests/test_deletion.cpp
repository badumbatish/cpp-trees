//
// Created by Jasmine Tang on 10/5/23.
//

#include "gtest/gtest.h"
#include "binary_tree.h"

TEST(DELETION, no_child_deletion) {
    binary_tree basic_tree = binary_tree<int, int>();
    basic_tree.insert(1 ,1);
    ASSERT_EQ(basic_tree.size(), 1);

    basic_tree.erase(1);
    ASSERT_EQ(basic_tree.size(), 0);

    basic_tree.insert(1, 1);
    basic_tree.insert(2, 2);
    ASSERT_EQ(basic_tree.size(), 2);
    basic_tree.erase(2);
    ASSERT_EQ(basic_tree.size(), 1);
}