//
// Created by Jasmine Tang on 9/29/23.
//
#ifndef CPP_TREES_BINARY_TREE_H
#define CPP_TREES_BINARY_TREE_H

#include <optional>
#include <memory>

#include <binary_tree_node.h>

template<typename K, typename V>
class binary_tree {


private:
    std::shared_ptr<binary_tree_node<K, V>> n;
public:
    binary_tree<K, V>();

    ~binary_tree<K, V>();

    void insert(K key, V value);

    bool contains(K key);

    std::optional<V> find(K key);

    int64_t size();
};

/*
 * PRIVATE METHOD
 *
 */


/*
 * PUBLIC METHOD
 *
 */
template<typename K, typename V>
int64_t binary_tree<K, V>::size() {
    return binary_tree_node<K, V>::size(n);
}

template<typename K, typename V>
binary_tree<K, V>::binary_tree() {
    this->n = std::make_shared<binary_tree_node<K, V>>();
}

template<typename K, typename V>
void binary_tree<K, V>::insert(K key, V value) {
    return binary_tree_node<K, V>::insert(n, key, value);
}

template<typename K, typename V>
bool binary_tree<K, V>::contains(K key) {
    return binary_tree_node<K, V>::contains(n, key);
}

template<typename K, typename V>
std::optional<V> binary_tree<K, V>::find(K key) {
    return binary_tree_node<K, V>::find(n, key);
}

template<typename K, typename V>
binary_tree<K, V>::~binary_tree() {

}

#endif //CPP_TREES_BINARY_TREE_H
