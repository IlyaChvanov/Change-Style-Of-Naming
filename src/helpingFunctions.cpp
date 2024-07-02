#include "helpingfunctions.h"

Text HelpingFunctions::MakeTextObject(std::string& file_path) {
  try {
    return {file_path};
  } catch (UI::IncorrectInput&) {
    std::cout << "file doesn't exist" << '\n';
    UI::AskFilePath();
    file_path = UI::ReadPath();
    return MakeTextObject(file_path);
  }
}
std::string HelpingFunctions::GetExtension(const std::string& file) {
  return file.substr(file.find_last_of('.') + 1);
}

//collects all, if necessary - create variants depending on programming language
bool HelpingFunctions::IsProgrammingFile(const std::string& file) {
  std::string fe = GetExtension(file);
  return (fe == "c" || fe == "cpp" || fe == "java" || fe == "py"
  || fe == "js" || fe == "ts" || fe == "cs" || fe == "pl"
  || fe == "dta" || fe == "sh" || fe == "h" || fe == "hpp");
}
