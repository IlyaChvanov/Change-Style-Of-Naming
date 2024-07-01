#include <iostream>
#include "UI.h"

using std::cout, std::cin;

void UI::AskFilePath() {
  cout << "Enter the path of file you want to change" << '\n';
}

void UI::AskDirectoryPath() {
  cout << "Enter the path of the directory with all declarations" << '\n';
}

void UI::AskWhatToChange() {
  cout << "Enter what you want to change:" << '\n';
  cout << "1: variable names" << '\n';
  cout << "2: function names" << '\n';
  cout << "3: class names" << '\n';
  cout << "4: everything above" << '\n';
}

void UI::AskWhichStyleIsNeeded() {
  cout << "Which style do you need:" << '\n';
  cout << "1: snake_case" << '\n';
  cout << "2: camelCase" << '\n';
  cout << "3: PascalCase" << '\n';
}

void UI::AskChangeOrCreateFile() {
  cout << "Create new file or change current:" << '\n';
  cout << "1: create new" << '\n';
  cout << "2: change current" << '\n';
}

std::string UI::ReadPath() {
  std::string path_;
  cin >> path_;
  return path_;
}

int UI::AskAndGetNum() {
  std::string what_to_change;
  cin >> what_to_change;
  int key = std::stoi(what_to_change);
  if (std::to_string(key).length() != what_to_change.length()) {
    throw UI::IncorrectInput();
  }
  return std::stoi(what_to_change);
}

WhatToChange UI::ReadWhatToChange() {
  try {
    switch (UI::AskAndGetNum()) {
      case 1:return variable_names;
      case 2:return function_names;
      case 3:return class_names;
      case 4:return all;
      default:throw UI::IncorrectInput();
    }
  } catch (...) {
    cout << "incorrect input, try again" << '\n';
    return ReadWhatToChange();
  }
}

Style UI::ReadStyle() {
  try {
    switch (UI::AskAndGetNum()) {
      case 1:return snake_case;
      case 2:return camelCase;
      case 3:return PascalCase;
      default:throw UI::IncorrectInput();
    }
  } catch (...) {
    cout << "incorrect input, try again" << '\n';
    return ReadStyle();
  }
}
WorkWFile UI::ReadChangeOrCreateFile() {
  try {
    switch (UI::AskAndGetNum()) {
      case 1:return create_new;
      case 2:return change_current;
      default:throw UI::IncorrectInput();
    }
  } catch (...) {
    cout << "incorrect input, try again" << '\n';
    return ReadChangeOrCreateFile();
  }
}
void UI::AskIsCorrect(std::string& DirPath,
                      std::string& FilePath,
                      WhatToChange& what_to_change,
                      Style& necessary_style,
                      WorkWFile& read_or_make) {
  cout << "\n";
  cout << "Directory with declarations: " << DirPath << '\n';
  cout << "File path: " << FilePath << '\n';
  cout << "You want to change: ";
  PrintWhatToChange(what_to_change);
  cout << "Necessary style is: " ;
  PrintNecessaryStyle(necessary_style);
  cout << "You want to ";
  PrintReadOrMake(read_or_make);
  cout << '\n';
  cout << "Do you want to change something?" << '\n';
  cout << "0: No" << '\n';
  cout << "1: Directory path" << '\n';
  cout << "2: File for changing" << '\n';
  cout << "3: Objects for changing" << '\n';
  cout << "4: Necessary style" << '\n';
  cout << "5: Choose make new file or change current" << '\n';
  cout << "6: All" << '\n';
}

void UI::PrintWhatToChange(WhatToChange what_to_change) {
  cout << what_to_change_[what_to_change] << '\n';
}
void UI::PrintNecessaryStyle(Style style) {
  cout << style_[style] << '\n';
}
void UI::PrintReadOrMake(WorkWFile read_or_make) {
  cout << work_w_file_[read_or_make] << '\n';
}
void UI::ChangeCorrectness(std::string& dir_path,
                           std::string& file_path,
                           WhatToChange& what_to_change,
                           Style& necessary_style,
                           WorkWFile& read_or_make) {
  switch (AskAndGetNum()) {
    case 0: return;
    case 1: {
      AskDirectoryPath();
      dir_path = ReadPath();
      break;
    }
    case 2: {
      AskFilePath();
      file_path = ReadPath();
      break;
    }
    case 3: {
      AskWhatToChange();
      what_to_change = ReadWhatToChange();
      break;
    }
    case 4: {
      AskWhichStyleIsNeeded();
      necessary_style = ReadStyle();
      break;
    }
    case 5: {
      AskChangeOrCreateFile();
      read_or_make = ReadChangeOrCreateFile();
      break;
    }
    case 6: {
      Begin(dir_path,file_path,what_to_change,
            necessary_style,read_or_make);
      break;
    }
  }

}
void UI::Begin(std::string& dir_path,
               std::string& file_path,
               WhatToChange& what_to_change,
               Style& necessary_style,
               WorkWFile& read_or_make) {
  UI::AskDirectoryPath();
  dir_path = UI::ReadPath();

  UI::AskFilePath();
  file_path = UI::ReadPath();

  UI::AskWhatToChange();
  what_to_change = UI::ReadWhatToChange();

  UI::AskWhichStyleIsNeeded();
  necessary_style = UI::ReadStyle();

  UI::AskChangeOrCreateFile();
  WorkWFile work_with_file = UI::ReadChangeOrCreateFile();

  UI::AskIsCorrect(dir_path, file_path, what_to_change,
                   necessary_style,work_with_file);

  UI::ChangeCorrectness(dir_path, file_path, what_to_change,
                        necessary_style,work_with_file);
}






