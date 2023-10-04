//
// Created by Jasmine Tang on 9/29/23.
//

#include "binary_tree.h"

binary_tree::binary_tree() {
    this->key = -1;
    this->value = -1;
    left_tree = nullptr;
    right_tree = nullptr;
}

void binary_tree::insert(int key, int value) {
    if (this->key == -1 || this->key == key) {
        this->key = key;
        this->value = value;
    } else if (this->key < key) {
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

bool binary_tree::contains(int key) {
    if (this->key == -1) {
        return false;
    } else if (this->key == key) {
        return true;
    } else if (this->key < key) {
        if (left_tree == nullptr) return false;
        return left_tree->contains(key);
    } else {
        if (right_tree == nullptr) return false;
        return right_tree->contains(key);
    }
}

int binary_tree::find(int key) {
    if (this->key == -1) {
        return -1;
    } else if (this->key == key) {
        return this->value;
    }
    else if (this->key < key) {
        if (left_tree == nullptr) return -1;
        return left_tree->find(key);
    } else {
        if (right_tree == nullptr) return -1;
        return right_tree->find(key);
    }
}

