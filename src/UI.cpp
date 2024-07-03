#include <iostream>
#include "UI.h"

using std::cout, std::cin;

void UI::AskFilePath() {
  cout << "Enter the path of file you want to change" << '\n';
}

void UI::AskDirectoryPath() {
  cout << "Enter the path to the root of the project" << '\n';
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
  std::string path;
  cin >> path;
  return path;
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
void UI::AskIsCorrect(const UserInput& input) {
  cout << "\n";
  cout << "Path to the root of the project: " << input.dir_path << '\n';
  cout << "File path: " << input.file_path << '\n';
  cout << "You want to change: ";
  PrintWhatToChange(input.what_to_change);
  cout << "Necessary style is: " ;
  PrintNecessaryStyle(input.necessary_style);
  cout << "You want to ";
  PrintReadOrMake(input.read_or_make);
  cout << '\n';
  cout << "Do you want to change something?" << '\n';
  cout << "0: No" << '\n';
  cout << "1: Path of root of the project" << '\n';
  cout << "2: File for changing" << '\n';
  cout << "3: Objects for changing" << '\n';
  cout << "4: Necessary style" << '\n';
  cout << "5: Choose make new file or change current" << '\n';
  cout << "6: All" << '\n';
}

void UI::PrintWhatToChange(WhatToChange& what_to_change) {
  cout << what_to_change_.at(what_to_change) << '\n';
}
void UI::PrintNecessaryStyle(Style style) {
  cout << style_.at(style) << '\n';
}
void UI::PrintReadOrMake(WorkWFile read_or_make) {
  cout << work_w_file_.at(read_or_make) << '\n';
}
void UI::ChangeCorrectness(UserInput& input) {
  switch (AskAndGetNum()) {
    case 0: return;
    case 1: {
      AskDirectoryPath();
      input.dir_path = ReadPath();
      break;
    }
    case 2: {
      AskFilePath();
      input.file_path = ReadPath();
      break;
    }
    case 3: {
      AskWhatToChange();
      input.what_to_change = ReadWhatToChange();
      break;
    }
    case 4: {
      AskWhichStyleIsNeeded();
      input.necessary_style = ReadStyle();
      break;
    }
    case 5: {
      AskChangeOrCreateFile();
      input.read_or_make = ReadChangeOrCreateFile();
      break;
    }
    case 6: {
      Begin();
      break;
    }
  }

}
UserInput UI::Begin() {
  UI::AskDirectoryPath();
  auto dir_path = UI::ReadPath();

  UI::AskFilePath();
  auto file_path = UI::ReadPath();

  UI::AskWhatToChange();
  auto what_to_change = UI::ReadWhatToChange();

  UI::AskWhichStyleIsNeeded();
  auto necessary_style = UI::ReadStyle();

  UI::AskChangeOrCreateFile();
  auto read_or_make = UI::ReadChangeOrCreateFile();

  auto input = UserInput(dir_path, file_path, what_to_change,
            necessary_style,read_or_make);

  UI::AskIsCorrect(input);
  UI::ChangeCorrectness(input);

  return input;
}
