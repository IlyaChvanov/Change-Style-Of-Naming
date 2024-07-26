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

using Texts = std::vector<std::string>;
class Project {
 public:
  Project(UserInput& input);
  void FindAndPushVariables();
  void FindAndPushFunctions();
  void FindAndPushClasses();
  void FindAndPush(const std::regex& regex,
                   std::unordered_set<std::string>& where_push,
                   int pos_of_pushing);
  Style GetOriginalStyle() const;
  Style GetNecessaryStyle() const;
  WhatToChange GetWhatToChange() const;
  WorkWFile GetWorkWFile() const;
  Texts& GetTexts();
  const std::unordered_set<std::string>& GetObjectsToChange() const;
 private:
  const UserInput& input_;
  ObjectsToChange objects_;
  Texts texts_from_files_;
};

#endif //CHANGE_STYLE_OF_NAMING_TEXT_H
