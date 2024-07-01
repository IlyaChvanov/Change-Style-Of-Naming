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
  all,
  underlines
};

class UI {
 public:
  static void AskPath();
  static void AskWhatToChange();
  static void AskWhichStyleIsNeeded();
  static void AskChangeOrCreateFile();
  static std::string ReadPath();
  static WhatToChange ReadWhatToChange();

  class IncorrectInput {};

 private:
};

#endif //CHANGE_STYLE_OF_NAMING_UI_H
