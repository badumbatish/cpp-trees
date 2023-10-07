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
    std::unique_ptr<binary_tree_node<K, V>> n;
public:
    void insert(K key, V value);

    bool contains(K key);

    std::optional<V> find(K key);

    int64_t size();

    std::optional<V> erase(K key);
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
    return n ? n->size() : 0;
}

template<typename K, typename V>
void binary_tree<K, V>::insert(K key, V value) {
    if (this->n == nullptr) {
        this->n = std::make_unique<binary_tree_node<K,V>>(key, value);
        return;
    }
    return n->insert(key, value);
}

template<typename K, typename V>
bool binary_tree<K, V>::contains(K key) {
    return n ? n->contains(key) : false;
}

template<typename K, typename V>
std::optional<V> binary_tree<K, V>::find(K key) {
    return n ? n->find(key) : std::nullopt;
}

template<typename K, typename V>
std::optional<V> binary_tree<K, V>::erase(K key) {
    return binary_tree_node<K,V>::erase(n, key);
}


#endif //CPP_TREES_BINARY_TREE_H
