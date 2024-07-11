#ifndef CHANGE_STYLE_OF_NAMING_CHANGE_H
#define CHANGE_STYLE_OF_NAMING_CHANGE_H

#include "UI.h"

class Change {
 public:
  Change(Style necessary_style);
  void ChangeClasses();
  void ChangeVariables();
  void ChangeFunctions();
 private:
  Style necessary_style_;
};


#endif //CHANGE_STYLE_OF_NAMING_CHANGE_H
