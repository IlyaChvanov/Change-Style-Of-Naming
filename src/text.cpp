//
// Created by user on 27.05.2024.
//

#include "text.h"
#include "helpingfunctions.h"

Text::Text(const std::string& path) {
  SetTextFromFile(path);
}
void Text::SetTextFromFile(const std::string& path) {
    std::ifstream file(path);
    if (file.is_open()) {
      std::getline(file, text_, '\0');
    } else {
      throw UI::IncorrectInput();
    }
}
void GetObjectsToChange::TraverseDirectory(std::string& root,
                                           WhatToChange what_to_change,
                                           ObjectsToChange& objects_to_change) {
  std::vector<std::string> files;
  GetFiles(root, files);
  switch (what_to_change) {
    case variable_names: {
      break;
    }
    case function_names: {
      break;
    }
    case class_names: {
      break;
    }
    case all: {
      break;
    }
  }
}

void GetObjectsToChange::GetFiles(std::string& root,
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
