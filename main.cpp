#include <iostream>

#include "text.h"

using std::cin;
int main() {
//
//  auto input = UI::Begin();
//  auto pr = Project(input.dir_path);
//
//  pr.FindAndPushClasses();

  std::string a("void f() {const }");
  std::regex var_regex("([\\s]*[\\w-]+[\\s]+)" // type
                       "([\\w]+)" // name
                       "([(]+.*[)]*)"
                       "[^;]"); //value

  std::cmatch res;
  std::regex_match(a.c_str(),res, var_regex);
  for (int i = 0; i < res.size(); i++) {
    std::cout<<res[i]<<'\n';
  }
  return 0;
}
