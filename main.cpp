#include <iostream>

#include "change.h"
#include "save.h"
using std::cin;
int main() {
  auto input = UI::Begin();
  auto pr = Project(input);
  auto change = Change(pr);
  auto save = Save(pr);
  return 0;
}

