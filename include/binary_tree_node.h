//
// Created by Jasmine Tang on 10/5/23.
//

#ifndef CPP_TREES_BINARY_TREE_NODE_H
#define CPP_TREES_BINARY_TREE_NODE_H

#include <optional>
#include <memory>

template<typename K, typename V>
class binary_tree_node {
    std::optional<K> key;
    std::optional<V> value;
    std::shared_ptr<binary_tree_node> left_tree, right_tree;
public:
    static void insert(std::shared_ptr<binary_tree_node> &n, K key, V value);

    static bool contains(const std::shared_ptr<binary_tree_node> &n, K key);

    static std::optional<V> find(const std::shared_ptr<binary_tree_node> &n, K key);

    static int64_t size(std::shared_ptr<binary_tree_node> n);

    static std::optional<V> erase(std::shared_ptr<binary_tree_node> &n, K key);
private:
    static std::shared_ptr<binary_tree_node> find_right_node_smallest(const std::shared_ptr<binary_tree_node> &n);
};

/*
 * PUBLIC METHOD
 */

template<typename K, typename V>
int64_t binary_tree_node<K, V>::size(std::shared_ptr<binary_tree_node> n) {
    int64_t tempSize{};
    if (n == nullptr) return 0;
    if (n->key.has_value()) tempSize += 1;
    tempSize += size(n->left_tree);
    tempSize += size(n->right_tree);

    return tempSize;
}

template<typename K, typename V>
std::optional<V> binary_tree_node<K, V>::find(const std::shared_ptr<binary_tree_node> &n, K key) {
    if (n == nullptr || n->key == std::nullopt) {
        return std::nullopt;
    } else if (n->key.value() == key) {
        return n->value;
    } else if (n->key.value() < key) {
        return find(n->left_tree, key);
    } else {
        return find(n->right_tree, key);
    }
}

template<typename K, typename V>
bool binary_tree_node<K, V>::contains(const std::shared_ptr<binary_tree_node> &n, K key) {
    if (n == nullptr || n->key == std::nullopt) {
        return false;
    } else if (n->key.value() == key) {
        return true;
    } else if (n->key.value() < key) {
        return contains(n->left_tree, key);
    } else {
        return contains(n->right_tree, key);
    }
}

template<typename K, typename V>
void binary_tree_node<K, V>::insert(std::shared_ptr<binary_tree_node>  &n, K key, V value) {
    if (n == nullptr) {
        n = std::make_shared<binary_tree_node<K, V>>();
    }
    if (n->key == std::nullopt || n->key.value() == key) {
        n->key = std::make_optional(key);
        n->value = value;
    } else if (n->key.value() < key) {
        insert(n->left_tree, key, value);
    } else {
        insert(n->right_tree, key, value);
    }
}

template<typename K, typename V>
std::optional<V> binary_tree_node<K, V>::erase(std::shared_ptr<binary_tree_node> &n, K key) {
    std::optional<V> res;
    if (n->left_tree == nullptr && n->right_tree == nullptr) {
        res = n->value;
        n.reset();
        return res;
    } else if ((n->left_tree == nullptr && n->right_tree != nullptr) ||
            (n->left_tree != nullptr && n->right_tree == nullptr)) {
        if (n->left_tree != nullptr) {
            res = n->value;
            n = n->right_tree;
            return res;
        } else {
            res = n->value;
            auto tempNode = n;
            n = n->left_tree;

            tempNode.reset();
            return res;
        }
    } else {
        return {};
    }
    return std::optional<V>();
}

template<typename K, typename V>

static std::shared_ptr<binary_tree_node<K, V>> find_right_node_smallest(const std::shared_ptr<binary_tree_node<K, V>> &n) {
    if ( n->right_tree == nullptr) {
        return nullptr;
    } else {
        auto ptr = n->right_tree;

        while(ptr->left_tree != nullptr) {
            ptr = ptr->left_tree;
        }
        return ptr;
    }
}
#endif //CPP_TREES_BINARY_TREE_NODE_H
