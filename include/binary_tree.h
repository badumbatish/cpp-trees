//
// Created by Jasmine Tang on 9/29/23.
//
#ifndef CPP_TREES_BINARY_TREE_H
#define CPP_TREES_BINARY_TREE_H


class binary_tree {
private:
    int key, value;
    binary_tree *left_tree, *right_tree;
public:
    binary_tree();
    void insert(int key, int value);
    bool contains(int key);
    int find(int key);
};


#endif //CPP_TREES_BINARY_TREE_H
