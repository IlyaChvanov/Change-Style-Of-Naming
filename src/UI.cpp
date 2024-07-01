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

}

void UI::AskChangeOrCreateFile() {

}

std::string UI::ReadPath() {
  std::string path_;
  cin >> path_;
  return path_;
}

WhatToChange UI::ReadWhatToChange() {
  try {
    std::string what_to_change;
    cin >> what_to_change;
    int key = std::stoi(what_to_change);
    if (std::to_string(key).length() != what_to_change.length()) {
      throw UI::IncorrectInput();
    }
    switch (std::stoi(what_to_change)) {
      case 1:return variable_names;
      case 2:return function_names;
      case 3:return class_names;
      case 4:return all;
      default:throw UI::IncorrectInput();
    }
  } catch (UI::IncorrectInput) {
    cout << "incorrect input, try again" << '\n';
    return ReadWhatToChange();
  }
}



