#include <iostream>
#include <fstream>
#include <string>

#include "UI.h"

using std::cin;
int main() {
  std::string path;
  UI::askPath();
  path = UI::readPath();

  UI::askWhatToChange();
  WhatToChange what_to_change = UI::readWhatToChange();
  return 0;
}
