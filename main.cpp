#include <iostream>

#include "change.h"

using std::cin;
int main() {

  auto input = UI::Begin();
  auto pr = Project(input);
  pr.FindAndPushClasses();
  pr.FindAndPushFunctions();
  auto change = Change(pr);
  return 0;
}

