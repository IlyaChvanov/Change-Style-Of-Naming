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
  std::vector<std::string>::iterator begin();
  std::vector<std::string>::iterator end();
 private:
  void SetTextFromFile(const std::string& path);
};

using Texts = std::vector<Text>;
class Project {
 public:
  Project(std::string& path);
  void ChangeClasses();
  void ChangeVariables();
  void ChangeFunctions();
 private:
  void FindAndPushVariables();
  void FindAndPushFunctions();
  void FindAndPushClasses();
  void FindAndPush(const std::regex& regex,
                   std::unordered_set<std::string>& where_push,
                   int pos_of_pushing);
  ObjectsToChange objects_;
  Texts texts_from_files_;
};


#endif //CHANGE_STYLE_OF_NAMING_TEXT_H
