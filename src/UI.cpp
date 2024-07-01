#include <iostream>
#include "UI.h"
#include <numeric>

using std::cout, std::cin;

void UI::askPath() {
  cout << "Enter the path of file you want to change" << '\n';
}

void UI::askWhatToChange() {
  cout << "Enter what you want to change:" << '\n';
  cout << "1: variable names" << '\n';
  cout << "2: function names" << '\n';
  cout << "3: class names" << '\n';
  cout << "4: everything above" << '\n';
  cout << "5: add right underline to the private fields" << '\n';
}

void UI::askWhichStyleIsNeeded() {

}

void UI::askChangeOrCreateFile() {

}

std::string UI::readPath() {
  std::string path;
  cin >> path;
  return path;
}


WhatToChange UI::readWhatToChange() {
  try {
    std::string whatToChange;
    cin >> whatToChange;
    int key = std::stoi(whatToChange);
    if (std::to_string(key).length() != whatToChange.length()) {
      throw UI::IncorrectInput();
    }
    switch (std::stoi(whatToChange)) {
      case 1:return variable_names;
      case 2:return function_names;
      case 3:return class_names;
      case 4:return all;
      case 5:return underlines;
      default:throw UI::IncorrectInput();
    }
  } catch (UI::IncorrectInput) {
    cout << "incorrect input, try again" << '\n';
    return readWhatToChange();
  }
}



