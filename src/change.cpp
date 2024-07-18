#include "change.h"

Change::Change(Project& project) : project_(project) {}

void Change::ChangeClasses() {

}
void Change::ChangeVariables() {

}
void Change::ChangeFunctions() {

}
using std::string_view;
std::vector<std::string> Change::SplitWords(std::string_view str) const {
  std::vector<std::string> words;
  std::string word;
  if (project_.GetOriginalStyle() == snake_case) {
    for (auto c : str) {
      if (c != '_') {
        word += c;
      } else {
        words.push_back(word);
        word.clear();
      }
    }
    if (!word.empty()) {
      words.push_back(word);
    }
  } else {
    for (auto it = str.begin(); it != str.end(); it++) {
      if (*it != tolower(*it) && it != str.begin()) {
        words.push_back(word);
        word.clear();
        word += tolower(*it);
        continue;
      }
      word += tolower(*it);
    }
    if (!word.empty()) {
      words.push_back(word);
    }
  }
  return words;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     }


