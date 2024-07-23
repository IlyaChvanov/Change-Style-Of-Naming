#ifndef CHANGE_STYLE_OF_NAMING_CHANGE_H
#define CHANGE_STYLE_OF_NAMING_CHANGE_H

#include "UI.h"
#include "project.h"

#include <string_view>

class Change {
 public:
  explicit Change(Project& project);
 private:
  Project& project_;
  void ChangeClasses();
  void ChangeVariables();
  void ChangeFunctions();
  std::vector<std::string> SplitWords(std::string_view) const;
  std::string Rename(const std::vector<std::string>& old_name) const;
  std::unordered_map<std::string_view, std::string> old_new_names;
};

#endif //CHANGE_STYLE_OF_NAMING_CHANGE_H
