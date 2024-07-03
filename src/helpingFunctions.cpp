#include "helpingFunctions.h"

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

Texts HelpingFunctions::MakeTextsFromFiles(
    const std::vector<std::string>& files) {
  Texts texts;
  texts.reserve(files.size());
  for (const auto& file : files) {
    texts.emplace_back(file);
  }
  return texts;
}

void HelpingFunctions::TraverseDirectory(std::string& root) {
  std::vector<std::string> files;
  GetFiles(root, files);
  Texts texts = HelpingFunctions::MakeTextsFromFiles(files);
}


void HelpingFunctions::GetFiles(std::string& root,
                                  std::vector<std::string>& files) {
  try {
    for (auto& file : std::filesystem::directory_iterator(root)) {
      if (std::filesystem::is_directory(file)) {
        std::string  fp =  file.path().string();
        GetFiles(fp, files);
      } else if (HelpingFunctions::IsProgrammingFile(file.path().string())) {
        files.emplace_back(file.path().string());
      }
    }
  } catch (std::filesystem::__cxx11::filesystem_error&) {
    std::cout << "incorrect path of project enter it again" << '\n';
    UI::AskDirectoryPath();
    root = UI::ReadPath();
    GetFiles(root, files);
  }
}

