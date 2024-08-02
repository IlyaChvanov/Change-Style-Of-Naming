#include "save.h"
Save::Save(const Project& project) :project_(project) {
  if (project_.GetWorkWFile() == create_new) {
    MakeFile();
  } else {
    ChangeFile();
  }
}
void Save::MakeFile() {

}
void Save::ChangeFile() {

}
