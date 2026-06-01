// Copyright 2021 NNTU-CS
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename) {
  std::ifstream file(filename);

  if (!file) {
    std::cout << "File error!" << std::endl;
    return;
  }

  std::string word;
  int ch;

  while ((ch = file.get()) != EOF) {
    if (std::isalpha(static_cast<unsigned char>(ch))) {
      word += std::tolower(static_cast<unsigned char>(ch));
    } else {
      if (!word.empty()) {
        tree.insert(word);
        word.clear();
      }
    }
  }

  if (!word.empty()) {
    tree.insert(word);
  }

  file.close();
}

void printFreq(BST<std::string>& tree) {
  std::vector<std::pair<std::string, int>> freq;

  tree.inorderTraverse([&freq](const std::string& key, int count) {
    freq.push_back(std::make_pair(key, count));
  });

  std::sort(freq.begin(), freq.end(),
            [](const std::pair<std::string, int>& a,
               const std::pair<std::string, int>& b) {
              if (a.second != b.second) {
                return a.second > b.second;
              }
              return a.first < b.first;
            });

  std::ofstream out("result/freq.txt");
  if (!out) {
    std::cout << "Cannot create result/freq.txt" << std::endl;
    return;
  }

  for (const auto& pair : freq) {
    std::cout << pair.first << " " << pair.second << std::endl;
    out << pair.first << " " << pair.second << std::endl;
  }

  out.close();
}
