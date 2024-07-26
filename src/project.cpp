#include "project.h"
#include "helpingFunctions.h"

Project::Project(UserInput& input) : input_(input) {
  std::vector<std::string> files;
  HelpingFunctions::GetFiles(input.dir_path, files);
  texts_from_files_ = HelpingFunctions::MakeTextsFromFiles(files);
}

void Project::FindAndPush(const std::regex& regex,
                          std::unordered_set<std::string>& where_push,
                          int pos_of_pushing) {

  for (const auto& text : texts_from_files_) {
    for (std::sregex_iterator it = std::sregex_iterator(text.begin(), text.end(), regex);
         it != std::sregex_iterator(); it++) {
      std::smatch match = *it;
      //HelpingFunctions::LogForFindings(it, pos_of_pushing);
      where_push.insert(match.str(pos_of_pushing));
    }
  }
}

void Project::FindAndPushClasses() {
  std::regex class_regex("(\\b)(class)(\\s)(\\w+)"
                         "([\\s\:\\w_\-]*)([\{])");
  FindAndPush(class_regex, objects_.classes_, 4);
}
//DOESN't WORK
void Project::FindAndPushVariables() {
  std::regex var_regex("([a-zA-Z0-9\:\*&\<\>\_\-]+[\\s])"
                       "([a-zA-Z0-9\*&\<\>\_\-])"
                       "(.*;)");
  FindAndPush(var_regex, objects_.variables_, 2);
}

void Project::FindAndPushFunctions() {
  std::regex function_regex("([a-zA-Z0-9\:\*&\<\>\_\-]+[\\s])([\\s]*[a-zA-Z0-9\*&]*((::)|(\\s)))"
                            "([a-zA-Z0-9_-]+)"
                            "([\(]+)"
                            "([\)a-zA-Z0-9:,\\s\*&\<\>\_\-\]+[{])");
  FindAndPush(function_regex, objects_.functions_, 6);
}
Style Project::GetOriginalStyle() const {
  return input_.original_style;
}
Style Project::GetNecessaryStyle() const {
  return input_.necessary_style;
}
WhatToChange Project::GetWhatToChange() const {
  return input_.what_to_change;
}
WorkWFile Project::GetWorkWFile() const {
  return input_.change_or_create;
}
const std::unordered_set<std::string>& Project::GetObjectsToChange() const {
  if (input_.what_to_change == variable_names) {
    return objects_.variables_;
  }
  if (input_.what_to_change == function_names) {
    return objects_.functions_;
  }
  return objects_.classes_;
}
