#include <iostream>
#include "UI.h"

using std::cout, std::cin;

void UI::AskPath() {
  cout << "Enter the path of file you want to change" << '\n';
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





