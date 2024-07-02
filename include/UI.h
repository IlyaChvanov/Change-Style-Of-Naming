
#ifndef CHANGE_STYLE_OF_NAMING_UI_H
#define CHANGE_STYLE_OF_NAMING_UI_H

#include <string>
#include <unordered_map>

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
  static void AskIsCorrect(std::string& DirPath, std::string& FilePath,
                           WhatToChange& what_to_change, Style& necessary_style,
                           WorkWFile& read_or_make);

  static std::string ReadPath();
  static WhatToChange ReadWhatToChange();
  static Style ReadStyle();
  static WorkWFile ReadChangeOrCreateFile();

  static void Begin(std::string& dir_path,
                    std::string& file_path,
                    WhatToChange& what_to_change,
                    Style& necessary_style,
                    WorkWFile& read_or_make);

  class IncorrectInput {};

 private:
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

  static inline std::unordered_map<WorkWFile, std::string> work_w_file_ = {
      {create_new, "create new file"},
      {change_current, "change current file"}
  };

  static int AskAndGetNum();
  static void PrintWhatToChange(WhatToChange what_to_change);
  static void PrintNecessaryStyle(Style style);
  static void PrintReadOrMake(WorkWFile read_or_make);
  static void ChangeCorrectness(std::string& dir_path,
                                std::string& file_path,
                                WhatToChange& what_to_change,
                                Style& necessary_style,
                                WorkWFile& read_or_make);
};

#endif //CHANGE_STYLE_OF_NAMING_UI_H
