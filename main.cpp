#include <iostream>

#include "project.h"

using std::cin;
int main() {

  auto input = UI::Begin();
  auto pr = Project(input);
  pr.FindAndPushClasses();
  pr.FindAndPushFunctions();
  return 0;
}
