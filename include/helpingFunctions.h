#ifndef CHANGE_STYLE_OF_NAMING_INCLUDE_HELPINGFUNCTIONS_H_
#define CHANGE_STYLE_OF_NAMING_INCLUDE_HELPINGFUNCTIONS_H_

#include "project.h"

#include <iostream>

class HelpingFunctions {
 public:
  static void LogForFindings(const std::sregex_iterator& it, int pos_of_pushing);
  static void LogForWordsSpliting(const std::vector<std::string>& words,
                                  std::string_view str);
  static std::string GetTextFromFile(std::string_view file_path);
  static std::string GetExtension(std::string_view file);
  static bool IsProgrammingFile(std::string_view file);
  static Texts MakeTextsFromFiles(const std::vector<std::string>& files);
  static void GetFiles(std::string& root,
                       std::vector<std::string>& files);
  static std::vector<std::string> SplitWordsSnakeCase(std::string_view str);
  static std::vector<std::string> SplitWordsPascalOrCamel(std::string_view str);
  static std::string MakeNewName(const std::vector<std::string>& splited,
                                 Style necessary_style);
  static std::string MakeSnakeCase(const std::vector<std::string>&);
  static  std::string MakeCamelCase(const std::vector<std::string>&);
  static  std::string MakePascalCase(const std::vector<std::string>&);
};
#endif //CHANGE_STYLE_OF_NAMING_INCLUDE_HELPINGFUNCTIONS_H_
