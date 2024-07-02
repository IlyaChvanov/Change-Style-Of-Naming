//
// Created by user on 02.07.2024.
//

#ifndef CHANGE_STYLE_OF_NAMING_INCLUDE_HELPINGFUNCTIONS_H_
#define CHANGE_STYLE_OF_NAMING_INCLUDE_HELPINGFUNCTIONS_H_

#include "text.h"

class HelpingFunctions {
 public:
  static Text MakeTextObject(std::string& file_path) {
    try {
      return {file_path};
    } catch (UI::IncorrectInput&) {
      std::cout << "file doesn't exist" << '\n';
      UI::AskFilePath();
      file_path = UI::ReadPath();
      return MakeTextObject(file_path);
    }
  }
};
#endif //CHANGE_STYLE_OF_NAMING_INCLUDE_HELPINGFUNCTIONS_H_
