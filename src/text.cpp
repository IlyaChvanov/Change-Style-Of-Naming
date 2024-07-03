//
// Created by user on 27.05.2024.
//

#include "text.h"
#include "helpingFunctions.h"

Text::Text(const std::string& path) {
  SetTextFromFile(path);
}
void Text::SetTextFromFile(const std::string& path) {
    std::ifstream file(path);
    if (file.is_open()) {
      std::getline(file, text_, '\0');
    } else {
      throw UI::IncorrectInput();
    }
}

//GetObjectsToChange::GetObjectsToChange(Texts& texts) : texts_(texts){}
//GetObjectsToChange::GetObjectsToChange() {}
Project::Project(std::string& path) {
  std::vector<std::string> files;
  HelpingFunctions::GetFiles(path, files);
  texts_ = HelpingFunctions::MakeTextsFromFiles(files);
}
