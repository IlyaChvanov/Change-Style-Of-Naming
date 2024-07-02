#ifndef CHANGE_STYLE_OF_NAMING_TEXT_H
#define CHANGE_STYLE_OF_NAMING_TEXT_H

#include "UI.h"

#include "unordered_set"
#include "filesystem"

struct ObjectsToChange {
  std::unordered_set<std::string> variables_;
  std::unordered_set<std::string> functions_;
  std::unordered_set<std::string> classes_;
};

class Text {
 public:
  friend class GetObjectsToChange;
  Text(const std::string& path);
 private:
  std::string text_;
  std::string path_;
  ObjectsToChange objects_;
};

class GetObjectsToChange {
  static void Traverse(const std::string& root);
};


#endif //CHANGE_STYLE_OF_NAMING_TEXT_H
