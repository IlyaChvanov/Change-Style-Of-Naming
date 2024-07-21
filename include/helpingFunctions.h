#ifndef CHANGE_STYLE_OF_NAMING_INCLUDE_HELPINGFUNCTIONS_H_
#define CHANGE_STYLE_OF_NAMING_INCLUDE_HELPINGFUNCTIONS_H_

#include "project.h"

#include <iostream>

class HelpingFunctions {
 public:
  static void LogForFindings(std::sregex_iterator it, int pos_of_pushing);
  static std::string GetTextFromFile(const std::string& file_path);
  static std::string GetExtension(const std::string& file);
  static bool IsProgrammingFile(const std::string& file);
  static Texts MakeTextsFromFiles(const std::vector<std::string>& files);
  static void GetFiles(std::string& root,
                       std::vector<std::string>& files);
  static std::vector<std::string> SplitWordsSnakeCase(std::string_view);
  static std::vector<std::string> SplitWordsPascalOrCamel(std::string_view);
};
#endif //CHANGE_STYLE_OF_NAMING_INCLUDE_HELPINGFUNCTIONS_H_
