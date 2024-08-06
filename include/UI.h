#ifndef CHANGE_STYLE_OF_NAMING_UI_H
#define CHANGE_STYLE_OF_NAMING_UI_H

#include <string>
#include <unordered_map>
#include <iostream>

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

struct UserInput {
  std::string dir_path;
  std::string file_path;
  WhatToChange what_to_change;
  Style necessary_style;
  Style original_style;
  WorkWFile change_or_create;
};

class UI {
 public:
  static void AskFilePath();
  static void AskDirectoryPath();
  static void AskWhatToChange();
  static void AskWhichStyleIsNeeded();
  static void AskOriginalStyle();
  static void AskChangeOrCreateFile();
  static void AskIsCorrect(const UserInput&);

  static std::string ReadPath();
  static WhatToChange ReadWhatToChange();
  static Style ReadStyle();
  static WorkWFile ReadChangeOrCreateFile();

  static UserInput Begin();

  //anyway I have to catch (...)  in UI.cpp because there are several of them and I can't catch them by this and set necessary message
  class IncorrectInput : public std::exception {
   private:
    std::string message_ = "Incorrect input, try again";
   public:
    const char* what() const noexcept override { return message_.c_str(); }
  };

 private:
  static int AskAndGetNum();
  static void ChangeCorrectness(UserInput& input);

  static inline const std::unordered_map<WhatToChange, std::string> what_to_change_ = {
      {variable_names, "variable names"},
      {function_names, "function names"},
      {class_names, "class names"},
      {all, "all"}
  };

  static inline const std::unordered_map<Style, std::string> style_ = {
      {snake_case, "snake_case"},
      {camelCase, "camelCase"},
      {PascalCase, "PascalCase"}
  };

  static inline const std::unordered_map<WorkWFile, std::string> work_w_file_ = {
      {create_new, "create new file"},
      {change_current, "change current file"}
  };

  static void PrintEnum(WhatToChange enum_to_print) {
    std::cout << what_to_change_.at(enum_to_print);
  }
  static void PrintEnum(Style enum_to_print) {
    std::cout << style_.at(enum_to_print);
  }
  static void PrintEnum(WorkWFile enum_to_print) {
    std::cout << work_w_file_.at(enum_to_print);
  }
};

#endif //CHANGE_STYLE_OF_NAMING_UI_H
