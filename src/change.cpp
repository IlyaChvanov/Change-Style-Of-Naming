#include "change.h"
#include "helpingFunctions.h"

Change::Change(Project& project) : project_(project) {
  for (auto& old_name : project_.GetObjectsToChange()) {
    std::string new_name = Rename(old_name);
    old_new_names[old_name] = new_name;
  }
}

void Change::ChangeClasses() {

}
void Change::ChangeVariables() {

}
void Change::ChangeFunctions() {

}
std::vector<std::string> Change::SplitWords(std::string_view str) const {
  if (project_.GetOriginalStyle() == snake_case) {
    return HelpingFunctions::SplitWordsSnakeCase(str);
  }
  return HelpingFunctions::SplitWordsPascalOrCamel(str);
}
