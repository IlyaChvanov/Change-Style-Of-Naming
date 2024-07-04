#ifndef CHANGE_STYLE_OF_NAMING_TEXT_H
#define CHANGE_STYLE_OF_NAMING_TEXT_H

#include "UI.h"

#include "algorithm"
#include "unordered_set"
#include <filesystem>
#include <fstream>
#include <vector>
#include <regex>
#include <string>
#include <iostream>

struct ObjectsToChange {
  std::unordered_set<std::string> variables_;
  std::unordered_set<std::string> functions_;
  std::unordered_set<std::string> classes_;
};

class Text {
 public:
  Text(const std::string& path);
  std::vector<std::string> strings_;
 private:
  void SetTextFromFile(const std::string& path);
};

using Texts = std::vector<Text>;
class Project {
 public:
  Project(std::string& path);
  void FindAndSetVariables();
  void FindAndSetFunctions();
  void FindAndSetClasses();
 private:
  ObjectsToChange objects_;
  Texts texts_from_files_;
};


#endif //CHANGE_STYLE_OF_NAMING_TEXT_H
