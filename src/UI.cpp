#include <iostream>
#include "UI.h"

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
    int whatToChange = -1;
    UI::askWhatToChange();
    cin >> whatToChange;
    switch (whatToChange) {
      case 1:return variable_names;
      case 2:return function_names;
      case 3:return class_names;
      case 4:return all;
      case 5:return underlines;
      default:throw IncorrectInput();
    }
  } catch (const IncorrectInput &) {
    cout << "incorrect input, try again" << '\n';
    readWhatToChange();
  }
}

