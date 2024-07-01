//
// Created by user on 27.05.2024.
//

#ifndef CHANGE_STYLE_OF_NAMING_TEXT_H
#define CHANGE_STYLE_OF_NAMING_TEXT_H

#include "UI.h"

#include "unordered_set"

class Text {
  Text(const std::string& path);
 private:
  std::string path;
  WhatToChange what_to_change_;
  std::unordered_set<std::string> variables;
  std::unordered_set<std::string> functions;
  std::unordered_set<std::string> classes;
  std::unordered_set<std::string> private_fields;
};

#endif //CHANGE_STYLE_OF_NAMING_TEXT_H
