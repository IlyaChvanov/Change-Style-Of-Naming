#ifndef CHANGE_STYLE_OF_NAMING_TEXT_H
#define CHANGE_STYLE_OF_NAMING_TEXT_H

#include "UI.h"

#include "unordered_set"
#include <filesystem>
#include <fstream>
#include <vector>

struct ObjectsToChange {
  std::unordered_set<std::string> variables_;
  std::unordered_set<std::string> functions_;
  std::unordered_set<std::string> classes_;
};

class Text {
 public:
  Text(const std::string& path);
 private:
  std::string text_;
  void SetTextFromFile(const std::string& path);
};

class GetObjectsToChange {
 public:
  static void TraverseDirectory(const std::string& root,
                                WhatToChange what_to_change,
                                ObjectsToChange& objects_to_change);
 private:
  static void GetFiles(const std::string& root,
                       std::vector<std::string>& files);

};


#endif //CHANGE_STYLE_OF_NAMING_TEXT_H
