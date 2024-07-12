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

  for (const auto& strings : texts_from_files_) {
    std::cmatch result;
    if (std::regex_match(strings.c_str(), result, regex)) {
      std::cout << strings << ' ' << result[pos_of_pushing] << '\n';
      where_push.insert(result[pos_of_pushing]);

    }
  }
}

void Project::FindAndPushClasses() {
  std::regex class_regex("([\\s]*class )"
                         "([\\w-]+[\\s]*)"
                         "([{]*)"
                         "([\\w]*)([};]*)");
  FindAndPush(class_regex, objects_.classes_, 2);
}
//DOESN't WORK
void Project::FindAndPushVariables() {
  std::regex var_regex("");
  FindAndPush(var_regex, objects_.variables_, 2);
}
//DOESN't WORK
void Project::FindAndPushFunctions() {
  std::regex function_regex("");
  FindAndPush(function_regex, objects_.functions_, 2);
}
