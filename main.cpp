#include <iostream>

#include "text.h"

using std::cin;
int main() {

  auto input = UI::Begin();
  auto pr = Project(input.dir_path);

  pr.FindAndSetClasses();
//  std::string a("class MAIN {sdasd}");
//std::regex word_regex("([A-Za-z0-9_ \\f\\n\\r\\t\\v]*)"
//                        "(class )"
//                        "([\\w-]+[\\s]*)"
//                        "([{]*)"
//                        "([\\w]*)([}]*)");
//  std::cmatch res;
//  std::regex_match(a.c_str(),res, word_regex);
//  for (int i = 0; i < res.size(); i++) {
//    std::cout<<res[i]<<'\n';
//  }
  return 0;
}
