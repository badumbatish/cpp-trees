//
// Created by Jasmine Tang on 10/5/23.
//

#ifndef CPP_TREES_BINARY_TREE_NODE_H
#define CPP_TREES_BINARY_TREE_NODE_H

#include <optional>
#include <memory>

template<typename K, typename V>
class binary_tree_node {
    K key;
    V value;
    std::unique_ptr<binary_tree_node> left_tree, right_tree;
public:
    binary_tree_node(K key, V value) : key(key), value(value) {}
    void insert(K key, V value);

    bool contains(K key);

    std::optional<V> find(K key);

    int64_t size();

    static std::optional<V> erase(std::unique_ptr<binary_tree_node<K, V>> &n, K key);
    static std::unique_ptr<binary_tree_node<K, V>> find_leftmost(std::unique_ptr<binary_tree_node<K, V>> &n);

private:

};

template<typename K, typename V>
std::unique_ptr<binary_tree_node<K, V>>
binary_tree_node<K, V>::find_leftmost(std::unique_ptr<binary_tree_node<K, V>> &n) {
    if (n == nullptr) return nullptr;
    else if (n->left_tree == nullptr) {
        if (n->right_tree != nullptr) {
            auto temp = std::move(n);
            n = std::move(n->right_tree);
            return temp;
        } else {
            return std::move(n);
        }

    }
    return find_leftmost(n->left_tree);
}
/*
 * PUBLIC METHOD
 */
template<typename K, typename V>
int64_t binary_tree_node<K, V>::size() {
    int64_t tempSize{1};

    tempSize += this->left_tree ? this->left_tree->size() : 0;
    tempSize += this->right_tree ? this->right_tree->size() : 0;

    return tempSize;
}

template<typename K, typename V>
std::optional<V> binary_tree_node<K, V>::find(K key) {
    if (this->key == key) {
        return this->value;
    } else if (this->key > key) {
        return this->left_tree ? this->left_tree->find(key) : std::nullopt;
    } else {
        return this->right_tree ? this->right_tree->find(key) : std::nullopt;
    }
}

template<typename K, typename V>
bool binary_tree_node<K, V>::contains(K key) {
    if (this->key == key) {
        return true;
    } else if (this->key > key) {
        return this->left_tree && this->left_tree->contains(key);
    } else {
        return this->right_tree && this->right_tree->contains(key);
    }
}

template<typename K, typename V>
void binary_tree_node<K, V>::insert(K key, V value) {
    if (this->key == key) {
        this->value = value;
    } else if (this->key > key) {
        if (this->left_tree == nullptr) {
            this->left_tree = std::make_unique<binary_tree_node<K, V>>(key, value);
        } else {
            this->left_tree->insert(key, value);
        }
    } else {
        if (this->right_tree == nullptr) {
            this->right_tree = std::make_unique<binary_tree_node<K, V>>(key, value);
        } else {
            this->right_tree->insert(key, value);
        }
    }
}

template<typename K, typename V>
std::optional<V> binary_tree_node<K, V>::erase(std::unique_ptr<binary_tree_node<K, V>> &n,K key) {
    if (n == nullptr) return {};
    if (n->key > key) {
        return erase(n->left_tree, key);
    } else if ((n->key < key)) {
        return erase(n->right_tree, key);
    } else {
        // Only 0 child
        if (n->left_tree == nullptr && n->right_tree == nullptr) {
            auto res = n->value;
            n.reset();
            return res;
        } else if ( n->left_tree == nullptr ^ n->right_tree == nullptr) {
            // Only 1 child
            auto res = n->value;

            if (n->left_tree)  n = std::move(n->left_tree);
            else n = std::move(n->right_tree);

            return res;
        } else {
            // Two children
            auto smallest = binary_tree_node<K,V>::find_leftmost(n->right_tree);

            auto res = n->value;
            n->key = std::move(smallest->key);
            n->value = std::move(smallest->value);

            smallest.reset();
            return res;
        }
    }
}
#endif //CPP_TREES_BINARY_TREE_NODE_H
