#include "change.h"
#include "helpingFunctions.h"

Change::Change(Project& project) : project_(project) {}

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
