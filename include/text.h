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


using Texts = std::vector<Text>;
class Project {
 public:
  Project(std::string& path);
  std::unordered_set<std::string> GetVariables();
  std::unordered_set<std::string> GetFunctions();
  std::unordered_set<std::string> Getclasses();
 private:
  Texts texts_;
};


#endif //CHANGE_STYLE_OF_NAMING_TEXT_H
