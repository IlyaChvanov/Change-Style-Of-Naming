#ifndef CHANGE_STYLE_OF_NAMING_INCLUDE_HELPINGFUNCTIONS_H_
#define CHANGE_STYLE_OF_NAMING_INCLUDE_HELPINGFUNCTIONS_H_

#include "project.h"

#include <iostream>

class HelpingFunctions {
 public:
  static void LogForFindings(const std::sregex_iterator& it, int pos_of_pushing);
  static void LogForWordsSpliting(const std::vector<std::string>& words,
                                  const std::string_view str);
  static std::string GetTextFromFile(const std::string& file_path);
  static std::string GetExtension(const std::string& file);
  static bool IsProgrammingFile(const std::string& file);
  static Texts MakeTextsFromFiles(const std::vector<std::string>& files);
  static void GetFiles(std::string& root,
                       std::vector<std::string>& files);
  static std::vector<std::string> SplitWordsSnakeCase(std::string_view str);
  static std::vector<std::string> SplitWordsPascalOrCamel(std::string_view str);
  static std::string MakeNewName(const std::vector<std::string>& splited, Style style);
};
#endif //CHANGE_STYLE_OF_NAMING_INCLUDE_HELPINGFUNCTIONS_H_
