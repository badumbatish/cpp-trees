//
// Created by Jasmine Tang on 9/29/23.
//
#ifndef CPP_TREES_BINARY_TREE_H
#define CPP_TREES_BINARY_TREE_H

template<typename K, typename V>
class binary_tree {
private:
    K key;
    V value;
    binary_tree<K, V> *left_tree, *right_tree;
public:
    binary_tree<K, V>();
    void insert(int key, int value);
    bool contains(int key);
    int find(int key);
};


#endif //CPP_TREES_BINARY_TREE_H
