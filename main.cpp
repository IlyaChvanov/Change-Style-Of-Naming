#include <iostream>
#include <QApplication>
#include <QDebug>
#include <QString>
#include <thread>

#include "change.h"
#include "save.h"
#include "ui/include/myAppWindow.h"

using std::cin;
int main(int argc, char** argv) {
  UserInput input;
  QApplication app(argc, argv);
  MyAppWindow window(input);
  //auto pr = Project(input);
  //auto change = Change(pr);
  //auto save = Save(pr);
  window.show();

  return app.exec();
}

