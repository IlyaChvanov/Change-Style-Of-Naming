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
  std::vector<std::string> SplitWords(std::string_view) const;
  std::unordered_map<std::string_view, std::string> old_new_names;
  void ChangeProject();
  void FillStringWVector(std::string& old_str,
                         const std::vector<std::string>& new_str);
};

#endif //CHANGE_STYLE_OF_NAMING_CHANGE_H
