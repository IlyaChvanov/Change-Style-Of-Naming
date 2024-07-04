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
        text_.push_back(str);
    } else {
      throw UI::IncorrectInput();
    }
}
//std::string::const_iterator Text::begin() const {
//  return text_.begin();
//}
//std::string::const_iterator Text::end() const {
//  return text_.end();
//}
//
Project::Project(std::string& path) {
  std::vector<std::string> files;
  HelpingFunctions::GetFiles(path, files);
  texts_from_files_ = HelpingFunctions::MakeTextsFromFiles(files);
}
//void Project::FindAndSetClasses() {
//  for (const auto& text : texts_from_files_) {
//    size_t last_positioin = 0;
//    while(text.text_.find("class ", last_positioin) != std::string::npos) {
//      last_positioin += 6;
//      size_t last_symbol_in_name = text.text_.find('{', last_positioin);
//      std::string class_name = text.text_.at(last_positioin)
//    }
//  }
//}
