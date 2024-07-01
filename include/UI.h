//
// Created by user on 27.05.2024.
//

#ifndef CHANGE_STYLE_OF_NAMING_UI_H
#define CHANGE_STYLE_OF_NAMING_UI_H

#include <string>

enum WhatToChange {
  variable_names = 1,
  function_names,
  class_names,
  all
};

enum Style {
  snake_case = 1,
  camelCase,
  PascalCase
};

enum WorkWFile {
  create_new = 1,
  change_current
};

class UI {
 public:
  static void AskFilePath();
  static void AskDirectoryPath();
  static void AskWhatToChange();
  static void AskWhichStyleIsNeeded();
  static void AskChangeOrCreateFile();

  static std::string ReadPath();
  static WhatToChange ReadWhatToChange();
  static Style ReadStyle();
  static WorkWFile ReadChangeOrCreateFile();
  class IncorrectInput {};

 private:
  static int AskAndGetNum();
};

#endif //CHANGE_STYLE_OF_NAMING_UI_H
