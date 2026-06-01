// Copyright 2021 NNTU-CS
#include "bst.h"
#include <iostream>
#include <string>

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main() {
  BST<std::string> tree;

  makeTree(tree, "src/war_peace.txt");

  std::cout << "Tree depth: " << tree.depth() << std::endl;
  std::cout << "Search 'war': " << (tree.search("war") ? "found" : "not found") << std::endl;
  std::cout << "Search 'peace': " << (tree.search("peace") ? "found" : "not found") << std::endl;
  std::cout << "----------------------------------------" << std::endl;

  printFreq(tree);

  return 0;
}
