#include <iostream>

#include "text.h"

using std::cin;
int main() {

  auto input = UI::Begin();
  auto pr = Project(input.dir_path);

  pr.FindAndPushClasses();
  pr.FindAndPushFunctions();
  pr.FindAndPushVariables();

  return 0;
}
