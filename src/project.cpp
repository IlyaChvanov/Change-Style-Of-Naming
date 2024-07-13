#include "project.h"
#include "helpingFunctions.h"

Project::Project(UserInput& input) : Change(input.necessary_style) {
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
      where_push.insert(match.str(pos_of_pushing));
    }
  }
}


void Project::FindAndPushClasses() {
  std::regex class_regex("(\\b)(class)(\\s)(\\w+)");
  FindAndPush(class_regex, objects_.classes_, 4);
}
//DOESN't WORK
void Project::FindAndPushVariables() {
  std::regex var_regex("");
  FindAndPush(var_regex, objects_.variables_, 2);
}
//DOESN't WORK
void Project::FindAndPushFunctions() {
  std::regex function_regex("(\\w+)(\\s+)(\\w+)"
                            "(\\s*)(\\()(.*)(\\))[^;$]");
  FindAndPush(function_regex, objects_.functions_, 3);
}
