#include <iostream>

#include "change.h"


using std::cin;
int main() {

  auto input = UI::Begin();
  auto pr = Project(input);
  pr.FindAndPushClasses();
  pr.FindAndPushFunctions();
  auto change = Change(pr);
  return 0;
}

//namespace HelpingFunctions {
//
//    std::string GetTextFromFile(const std::filesystem::path &file_path) {
//        std::ifstream file(file_path);
//        std::string to_return;
//        std::getline(file, to_return, '\0');
//        return to_return;
//    }
//
//    bool IsProgrammingFile(const std::filesystem::path &file) {
//        auto fe = file.extension();
//        return (fe == "c" || fe == "cpp" || fe == "h" || fe == "hpp");
//    }
//
//    Texts MakeTextsFromFiles(const std::vector<std::filesystem::path> &files) {
//        Texts texts;
//        texts.reserve(files.size());
//        for (auto &file: files) {
//            texts[file] = GetTextFromFile(file);
//        }
//        return texts;
//    }
//}