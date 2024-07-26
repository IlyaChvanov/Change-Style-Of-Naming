#include "change.h"
#include "helpingFunctions.h"

Change::Change(Project& project) : project_(project) {
  for (auto& old_name : project_.GetObjectsToChange()) {
    std::string new_name = Rename(SplitWords(old_name));
    old_new_names[old_name] = new_name;
  }
  ChangeProject();
}

std::vector<std::string> Change::SplitWords(std::string_view str) const {
  if (project_.GetOriginalStyle() == snake_case) {
    return HelpingFunctions::SplitWordsSnakeCase(str);
  }
  return HelpingFunctions::SplitWordsPascalOrCamel(str);
}
void Change::ChangeProject() {
  for (auto& text : project_.GetTexts()) {
    // разбить строку на слова и проверять каждое словно на вхождение в old_new_names
  }

}
