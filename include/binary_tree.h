//
// Created by Jasmine Tang on 9/29/23.
//
#ifndef CPP_TREES_BINARY_TREE_H
#define CPP_TREES_BINARY_TREE_H
#include <optional>

template<typename K, typename V>
class binary_tree {
private:
    std::optional<K> key;
    std::optional<V> value;
    binary_tree<K, V> *left_tree, *right_tree;
public:
    binary_tree<K, V>();
    void insert(K key, V value);
    bool contains(K key);
    std::optional<V> find(K key);
};

template<typename K, typename V>
binary_tree<K, V>::binary_tree() {
    this->key = std::nullopt;
    this->value = std::nullopt;
    left_tree = nullptr;
    right_tree = nullptr;
}

template<typename K, typename V>
void binary_tree<K, V>::insert(K key, V value) {
    if (this->key == std::nullopt || this->key.value() == key) {
        this->key = std::make_optional(key);
        this->value = value;
    } else if (this->key.value() < key) {
        if (this->left_tree == nullptr) {
            this->left_tree = new binary_tree;
        }
        this->left_tree->insert(key, value);
    } else {
        if (this->right_tree == nullptr) {
            this->right_tree = new binary_tree;
        }
        this->right_tree->insert(key, value);
    }
}

template<typename K, typename V>
bool binary_tree<K, V>::contains(K key) {
    if (this->key == std::nullopt) {
        return false;
    } else if (this->key.value() == key) {
        return true;
    } else if (this->key.value() < key) {
        if (left_tree == nullptr) return false;
        return left_tree->contains(key);
    } else {
        if (right_tree == nullptr) return false;
        return right_tree->contains(key);
    }
}

template<typename K, typename V>
std::optional<V> binary_tree<K, V>::find(K key) {
    if (this->key == std::nullopt) {
        return std::nullopt;
    } else if (this->key.value() == key) {
        return this->value.value();
    }
    else if (this->key.value() < key) {
        if (left_tree == nullptr) return -1;
        return left_tree->find(key);
    } else {
        if (right_tree == nullptr) return -1;
        return right_tree->find(key);
    }
}

#endif //CPP_TREES_BINARY_TREE_H
