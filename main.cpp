#include <iostream>
#include <string>

#include "text.h"
#include "helpingfunctions.h"

using std::cin;
int main() {
//  std::string dir_path;
//  std::string file_path;
//  WhatToChange what_to_change;
//  Style necessary_style;
//  WorkWFile work_w_file;
//
//  UI::Begin(dir_path, file_path, what_to_change, necessary_style, work_w_file);
//
//  auto text = HelpingFunctions::MakeTextObject(file_path);
//
  std::string string = "C:\\Users\\user\\Desktop\\Git\\change-style-of-namin";
   ObjectsToChange obj;
   GetObjectsToChange::TraverseDirectory(string, variable_names, obj);
  return 0;
}
