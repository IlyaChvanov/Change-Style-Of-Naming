#include <iostream>

#include "text.h"

using std::cin;
int main() {

//  auto input = UI::Begin();
//  auto pr = Project(input.dir_path);

//  pr.FindAndPushClasses();
//  pr.FindAndPushFunctions();
//  pr.FindAndPushVariables();

  std::string a("const int a;");
  std::regex var_regex("([\\w\\s]*)"
                       "([\\w-]*)"
                       "([\\s]*)"
                       "([;]{1})"); //value

  std::cmatch res;
  std::regex_match(a.c_str(),res, var_regex);
  for (int i = 0; i < res.size(); i++) {
    std::cout<<res[i]<<'\n';
  }
  return 0;
}
