#include <iostream>
#include <fstream>
#include <string>

#include "UI.h"

using std::cin;
int main() {
  std::string path;
  UI::AskPath();
  path = UI::ReadPath();

  UI::AskWhatToChange();
  WhatToChange what_to_change = UI::ReadWhatToChange();
  return 0;
}
