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
    if (path == project_.GetFilePathToChange()) {
      std::string new_file_path = path.parent_path().string() + "/" +
          path.stem().string() + "_changed" + path.extension().string();
      std::ofstream file(new_file_path);
      file << text;
      break;
    }
  }
}
void Save::ChangeFile() {
  for (auto& [path, text] : project_.GetTexts()) {
    if (path == project_.GetFilePathToChange()) {
      std::ofstream file(path);
      file << text;
      break;
    }
  }
}
