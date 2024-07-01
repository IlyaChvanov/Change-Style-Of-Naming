#include <iostream>
#include <string>

#include "UI.h"

using std::cin;
int main() {
  UI::AskDirectoryPath();
  std::string DirectoryPath = UI::ReadPath();

  UI::AskFilePath();
  std::string Filepath = UI::ReadPath();

  UI::AskWhatToChange();
  WhatToChange what_to_change = UI::ReadWhatToChange();

  UI::AskWhichStyleIsNeeded();
  Style necessary_style = UI::ReadStyle();

  UI::AskChangeOrCreateFile();
  UI::ReadChangeOrCreateFile();
  return 0;
}
