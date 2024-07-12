#ifndef CHANGE_STYLE_OF_NAMING_INCLUDE_HELPINGFUNCTIONS_H_
#define CHANGE_STYLE_OF_NAMING_INCLUDE_HELPINGFUNCTIONS_H_

#include "project.h"

#include <iostream>

class HelpingFunctions {
 public:
  static std::string GetTextFromFile(const std::string& file_path);
  static std::string GetExtension(const std::string& file);
  static bool IsProgrammingFile(const std::string& file);
  static Texts MakeTextsFromFiles(const std::vector<std::string>& files);
  static Texts GetTextsFromAllFiles(std::string& root);
  static void GetFiles(std::string& root,
                       std::vector<std::string>& files);
};
#endif //CHANGE_STYLE_OF_NAMING_INCLUDE_HELPINGFUNCTIONS_H_
