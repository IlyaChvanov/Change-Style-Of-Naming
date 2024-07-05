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
//
void Project::FindAndSetClasses() {
std::regex class_regex("([A-Za-z0-9_ \\f\\n\\r\\t\\v]*)"
                      "(class )"
                      "([\\w-]+[\\s]*)"
                      "([{]*)"
                      "([\\w]*)([};]*)");
  for (const auto& strings : texts_from_files_) {
    for (const auto& str : strings.strings_) {
      std::cmatch result;
      if(std::regex_match(str.c_str(), result, class_regex)) {
        std::cout<<str<<' ' << result[3] << '\n';
        objects_.classes_.insert(result[3]);
      }
    }
  }
}

