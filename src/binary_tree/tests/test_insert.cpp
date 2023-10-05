//
// Created by Jasmine Tang on 10/4/23.
//

#include "gtest/gtest.h"
#include "binary_tree.h"

TEST(INSERTION, basic_insert) {
    binary_tree basic_tree = binary_tree<int, int>();
    basic_tree.insert(1 ,1);
    ASSERT_EQ(basic_tree.contains(1), true);
    ASSERT_EQ(basic_tree.find(1), 1);
}

TEST(INSERTION, automatic_identity_insert) {
    binary_tree basic_tree = binary_tree<int, int>();
    for (int i = 0; i < 1000; i++) {
        basic_tree.insert(i, i);
        ASSERT_EQ(basic_tree.contains(i), true);
        ASSERT_EQ(basic_tree.find(i).value(), i);
    }

    ASSERT_EQ(basic_tree.size(), 1000);
}

TEST(INSERTION, automatic_randomized_insert) {
    binary_tree basic_tree = binary_tree<int, int>();
    for (int i = 0; i < 100000; i++) {
        int random_num = rand() % 100000;
        basic_tree.insert(random_num, i);
        ASSERT_EQ(basic_tree.contains(random_num), true);
        ASSERT_EQ(basic_tree.find(random_num).value(), i);
    }

}