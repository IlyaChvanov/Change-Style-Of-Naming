#include "save.h"
Save::Save(Project& project) :project_(project) {
  if (project_.GetWorkWFile() == create_new) {
    MakeFile();
  } else {
    ChangeFile();
  }
}
void Save::MakeFile() {
  for (auto& [path, text] : project_.GetTexts()) {
    std::string new_file_path = path.string() + "_changed";
    std::ofstream file(new_file_path);
    file << text;
  }
}
void Save::ChangeFile() {
  for (auto& [path, text] : project_.GetTexts()) {
    std::ofstream file(path);
    file << text;
  }
}
