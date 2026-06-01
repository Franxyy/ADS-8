// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <iostream>
#include <algorithm>

template<typename T>
class BST {
private:
  struct Node {
    T key;
    int count;
    Node* left;
    Node* right;

    Node(const T& k) : key(k), count(1), left(nullptr), right(nullptr) {}
  };

  Node* root;

  void destroy(Node* node) {
    if (node) {
      destroy(node->left);
      destroy(node->right);
      delete node;
    }
  }

  void insert(Node*& node, const T& value) {
    if (!node) {
      node = new Node(value);
      return;
    }
    if (value < node->key) {
      insert(node->left, value);
    } else if (value > node->key) {
      insert(node->right, value);
    } else {
      node->count++;
    }
  }

  bool search(const Node* node, const T& value) const {
    if (!node) return false;
    if (value < node->key) {
      return search(node->left, value);
    } else if (value > node->key) {
      return search(node->right, value);
    } else {
      return true;
    }
  }

  int depth(const Node* node) const {
    if (!node) return 0;
    return 1 + std::max(depth(node->left), depth(node->right));
  }

  Node* copyTree(const Node* node) {
    if (!node) return nullptr;
    Node* newNode = new Node(node->key);
    newNode->count = node->count;
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);
    return newNode;
  }

  void inorder(const Node* node) const {
    if (node) {
      inorder(node->left);
      std::cout << node->key << ": " << node->count << std::endl;
      inorder(node->right);
    }
  }

  template<typename Func>
  void traverse(const Node* node, Func f) const {
    if (node) {
      traverse(node->left, f);
      f(node->key, node->count);
      traverse(node->right, f);
    }
  }

public:
  BST() : root(nullptr) {}
  
  ~BST() {
    destroy(root);
  }
  
  BST(const BST& other) : root(nullptr) {
    root = copyTree(other.root);
  }
  
  BST& operator=(const BST& other) {
    if (this != &other) {
      destroy(root);
      root = copyTree(other.root);
    }
    return *this;
  }

  void insert(const T& value) {
    insert(root, value);
  }

  bool search(const T& value) const {
    return search(root, value);
  }

  int depth() const {
    return depth(root);
  }

  bool isEmpty() const {
    return root == nullptr;
  }

  void printInOrder() const {
    inorder(root);
  }

  template<typename Func>
  void inorderTraverse(Func f) const {
    traverse(root, f);
  }
};

#endif  // INCLUDE_BST_H_
