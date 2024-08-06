#include "change.h"
#include "helpingFunctions.h"

Change::Change(Project& project) : project_(project) {
  for (auto& old_name : project_.GetObjectsToChange()) {
    std::string new_name = HF::MakeNewName(
        SplitWords(old_name),
        project_.GetNecessaryStyle());
    old_new_names[old_name] = new_name;
  }
  ChangeProject();
}

std::vector<std::string> Change::SplitWords(std::string_view str) const {
  if (project_.GetOriginalStyle() == snake_case) {
    return HF::SplitWordsSnakeCase(str);
  }
  return HF::SplitWordsPascalOrCamel(str);
}
void Change::ChangeProject() {
  for (auto& [file_path, text] : project_.GetTexts()) {
    std::vector<std::string> buf;
    auto l = text.begin();
    for (auto r = text.begin(); r != text.end(); r++) {
      if (*r == 45 || *r >= 65 && *r <= 90 || *r >= 97 && *r <= 122 || *r == 95) {
        continue;
      }
      buf.emplace_back(l,r);
      l = r;
      buf.emplace_back(std::string{*l});
      l++;
    }
    if (l != text.end()) {
      buf.emplace_back(l, text.end());
    }
    FillStringWVector(text, buf);
  }
}
void Change::FillStringWVector(std::string& old_str,
                               const std::vector<std::string>& new_str) {
  size_t prev_size = old_str.size();
  old_str.clear();
  old_str.reserve(prev_size);
  for (const auto& str : new_str) {
    if (old_new_names.contains(str)) {
      old_str += old_new_names[str];
    } else {
      old_str += str;
    }
  }
}

