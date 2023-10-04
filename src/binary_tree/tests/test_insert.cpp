//
// Created by Jasmine Tang on 10/4/23.
//

#include "gtest/gtest.h"
#include "binary_tree.h"
TEST(INSERTION, basic_insert) {
    binary_tree basic_tree = binary_tree();
    basic_tree.insert(1 ,1);
    ASSERT_EQ(basic_tree.contains(1), true);
}