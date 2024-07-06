#include <iostream>

#include "project.h"

using std::cin;
int main() {

  auto input = UI::Begin();
  auto pr = Project(input.dir_path);
  
  return 0;
}
