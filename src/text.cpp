#include "text.h"
#include "helpingFunctions.h"

Text::Text(const std::string& path) {
  SetTextFromFile(path);
}
void Text::SetTextFromFile(const std::string& path) {
    std::ifstream file(path);
    std::string str;
    if (file.is_open()) {
      while(std::getline(file, str, '\n'))
        strings_.push_back(str);
    } else {
      throw UI::IncorrectInput();
    }
}

Project::Project(std::string& path) {
  std::vector<std::string> files;
  HelpingFunctions::GetFiles(path, files);
  texts_from_files_ = HelpingFunctions::MakeTextsFromFiles(files);
}

void Project::FindAndPush(const std::regex& regex,
                          std::unordered_set<std::string>& where_push,
                          int pos_of_pushing) {

  for (const auto& strings : texts_from_files_) {
    for (const auto& str : strings.strings_) {
      std::cmatch result;
      if (std::regex_match(str.c_str(), result, regex)) {
        std::cout << str << ' ' << result[pos_of_pushing] << '\n';
        where_push.insert(result[pos_of_pushing]);
      }
    }
  }
}

void Project::FindAndPushClasses() {
  std::regex class_regex("([\\w-]*[\\s]*)"
                         "(class )"
                         "([\\w-]+[\\s]*)"
                         "([{]*)"
                         "([\\w]*)([};]*)");
  FindAndPush(class_regex, objects_.classes_, 3);
}

void Project::FindAndPushVariables() {
  std::regex var_regex("([\\s]*[\\w-]+[\\s]+)" // type
                       "([\\w]+)" // name
                       "(.*;)");
  FindAndPush(var_regex, objects_.variables_, 2);
}
void Project::FindAndPushFunctions() {
  std::regex function_regex("([\\s]*[\\w-]+[\\s]+)" // type
                       "([\\w]+)"
                       "([(]+.*[)]*)"
                       "[^;]");
  FindAndPush(function_regex, objects_.functions_, 3);
}
