// Copyright 2021 NNTU-CS
#include <string>
#include <iostream>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main() {
  BST<std::string> tree;

  makeTree(tree, "src/war_peace.txt");

  std::cout << "Tree depth: " << tree.depth() << std::endl;
  std::cout << "Search 'pierre': " << tree.search("pierre") << std::endl;
  std::cout << "Search 'natasha': " << tree.search("natasha") << std::endl;
  std::cout << "Search 'andrew': " << tree.search("andrew") << std::endl;
  std::cout << "----------------------------------------" << std::endl;

  printFreq(tree);

  return 0;
}
