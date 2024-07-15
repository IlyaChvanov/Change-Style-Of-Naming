#include "helpingFunctions.h"

std::string HelpingFunctions::GetTextFromFile(const std::string& file_path) {
    std::ifstream file(file_path);
    std::string to_return;
    std::getline(file, to_return, '\0');
    return to_return;
}
std::string HelpingFunctions::GetExtension(const std::string& file) {
  return file.substr(file.find_last_of('.') + 1);
}

//collects all, if necessary - create variants depending on programming language
bool HelpingFunctions::IsProgrammingFile(const std::string& file) {
  std::string fe = GetExtension(file);
  return (fe == "c" || fe == "cpp" || fe == "h" || fe == "hpp");
}

Texts HelpingFunctions::MakeTextsFromFiles(
    const std::vector<std::string>& files) {
  Texts texts;
  texts.reserve(files.size());
  for (auto& file : files) {
    texts.emplace_back(GetTextFromFile(file));
  }
  return texts;
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

