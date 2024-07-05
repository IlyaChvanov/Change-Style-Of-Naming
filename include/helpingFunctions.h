//
// Created by user on 02.07.2024.
//

#ifndef CHANGE_STYLE_OF_NAMING_INCLUDE_HELPINGFUNCTIONS_H_
#define CHANGE_STYLE_OF_NAMING_INCLUDE_HELPINGFUNCTIONS_H_

#include "text.h"

#include <iostream>

class HelpingFunctions {
 public:
  static Text MakeTextObject(std::string& file_path);
  static std::string GetExtension(const std::string& file);
  static bool IsProgrammingFile(const std::string& file);
  static Texts MakeTextsFromFiles(const std::vector<std::string>& files);
  static Texts GetTextsFromAllFiles(std::string& root);
  static void GetFiles(std::string& root,
                       std::vector<std::string>& files);
};
#endif //CHANGE_STYLE_OF_NAMING_INCLUDE_HELPINGFUNCTIONS_H_