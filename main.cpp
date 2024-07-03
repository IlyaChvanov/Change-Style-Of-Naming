#include <iostream>

#include "text.h"

using std::cin;
int main() {

  auto input = UI::Begin();
  Project(input.dir_path);

  //ObjectsToChange obj;
  //HelpingFunctions::GetTextsFromAllFiles(input.dir_path);

  return 0;
}
