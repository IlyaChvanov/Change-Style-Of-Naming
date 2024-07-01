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
  static void askPath();
  static void askWhatToChange();
  static void askWhichStyleIsNeeded();
  static void askChangeOrCreateFile();
  static std::string readPath();
  static WhatToChange readWhatToChange();

 private:
  class IncorrectInput {};
};

#endif //CHANGE_STYLE_OF_NAMING_UI_H
