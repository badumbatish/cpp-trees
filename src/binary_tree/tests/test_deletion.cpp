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

    basic_tree.insert(1, 1);
    basic_tree.insert(2, 2);
    basic_tree.insert(3, 3);
    basic_tree.erase(2);
    basic_tree.erase(3);
    ASSERT_EQ(basic_tree.size(), 1);

    basic_tree.erase(2);
    ASSERT_EQ(basic_tree.size(), 1);
}

TEST(DELETION, full_child_deletion_simple) {
    binary_tree basic_tree = binary_tree<int, int>();
    basic_tree.insert(2 ,2);
    ASSERT_EQ(basic_tree.size(), 1);
    basic_tree.insert(1 ,1);
    basic_tree.insert(3 ,3);
    // 1 - 2 - 3

    ASSERT_EQ(basic_tree.erase(2), 2);
    ASSERT_EQ(basic_tree.size(), 2);

}

TEST(DELETION, full_child_deletion_size_4) {
    binary_tree basic_tree = binary_tree<int, int>();
    basic_tree.insert(2 ,2);
    ASSERT_EQ(basic_tree.size(), 1);
    basic_tree.insert(1 ,1);
    basic_tree.insert(4 ,4);
    basic_tree.insert(3, 3);
    // 1 - 2 - 4 - 3

    ASSERT_EQ(basic_tree.erase(2), 2);
    ASSERT_EQ(basic_tree.size(), 3);

}

TEST(DELETION, automatic_simple_deletion) {
    binary_tree basic_tree = binary_tree<int, int>();
    basic_tree.insert(1 ,1);
    ASSERT_EQ(basic_tree.size(), 1);

    for (int i = 2; i <= 100; i++) {
        basic_tree.insert(i ,i);
    }

    for (int i = 2; i <= 100; i++) {
        basic_tree.erase(i);
        ASSERT_EQ(basic_tree.size(), 100-i+1);
    }

    ASSERT_EQ(basic_tree.size(), 1);

}