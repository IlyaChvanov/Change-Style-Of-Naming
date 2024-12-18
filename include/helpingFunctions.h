#ifndef CHANGE_STYLE_OF_NAMING_INCLUDE_HELPINGFUNCTIONS_H_
#define CHANGE_STYLE_OF_NAMING_INCLUDE_HELPINGFUNCTIONS_H_

#include "project.h"

#include <iostream>

namespace HF {

void LogForFindings(const std::sregex_iterator& it, int pos_of_pushing);
void LogForWordsSpliting(const std::vector<std::string>& words,
                         std::string_view str);

std::string GetTextFromFile(const std::filesystem::path& file_path);
bool IsProgrammingFile(const std::string& path);
bool IsSuitablePath(const  std::filesystem::directory_entry& file);
Texts MakeTextsFromFiles(const std::vector<std::filesystem::path>& files);
void GetFiles(std::string& root, std::vector<std::filesystem::path>& files);
std::vector<std::string> SplitWordsSnakeCase(std::string_view str);
std::vector<std::string> SplitWordsPascalOrCamel(std::string_view str);

std::string MakeNewName(const std::vector<std::string>& splited,
                        Style necessary_style);
std::string MakeSnakeCase(const std::vector<std::string>&);
std::string MakeCamelCase(const std::vector<std::string>&);
std::string MakePascalCase(const std::vector<std::string>&);
}
#endif //CHANGE_STYLE_OF_NAMING_INCLUDE_HELPINGFUNCTIONS_H_
