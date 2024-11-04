#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QHBoxLayout>
#include <QMainWindow>
#include <QLineEdit>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>

#include <save.h>
#include <project.h>
#include <change.h>
#include <helpingFunctions.h>
#include "UI.h"

static int step = 0;

class MyAppWindow : public QMainWindow {
  Q_OBJECT
public:
  MyAppWindow(UserInput &input, QWidget *parent = nullptr) : input(input), QMainWindow(parent) {
    Begin();
  }
private:
  QWidget* central_widget;
  QVBoxLayout* main_layout;
  QVBoxLayout* form_layout;
  UserInput& input;

  void Begin() {
    setWindowTitle("Change style of naming");
    setMinimumSize(600, 600);

    central_widget = new QWidget(this);
    main_layout = new QVBoxLayout(central_widget);
    main_layout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    form_layout = new QVBoxLayout();

    auto *label = new QLabel("Enter the root of project", central_widget);
    label->setAlignment(Qt::AlignCenter);
    form_layout->addWidget(label);

    auto *search_line_edit = new QLineEdit(central_widget);
    form_layout->addWidget(search_line_edit);

    auto *send_button = new QPushButton("accept", central_widget);
    form_layout->addWidget(send_button);

    main_layout->addLayout(form_layout);

    auto *combo_box = new QComboBox(central_widget);
    combo_box->addItem("variables");
    combo_box->addItem("functions");
    combo_box->addItem("classes");
    combo_box->addItem("all");
    combo_box->hide();

    main_layout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    setCentralWidget(central_widget);
    auto *yes_button = new QPushButton("yes", central_widget);
    auto *no_button = new QPushButton("no", central_widget);
    yes_button->hide();
    no_button->hide();

    step = 0;
    connect(send_button, &QPushButton::clicked, [=]() {
      if (step == 0) {
        input.dir_path = search_line_edit->text().toStdString();
        if (!std::filesystem::is_directory(input.dir_path)) {
          label->setText("it is not a directory try again");
          step = -1;
        } else {
          qDebug() << "root is " << input.dir_path;
          label->setText("Enter the file you want to change");
        }
      } else if (step == 1) {
        input.file_path = search_line_edit->text().toStdString();
        if (!std::filesystem::exists(input.file_path)) {
          label->setText("file doesn't exist, try again");
          step = 0;
        } else {
          search_line_edit->close();
          qDebug() << "file is: " << input.file_path;
          label->setText("What do you want to change");
          form_layout->addWidget(combo_box);
          combo_box->show();
          form_layout->removeWidget(send_button);
          form_layout->addWidget(send_button);
        }
      } else if (step == 2) {
        input.what_to_change = static_cast<WhatToChange>(combo_box->currentIndex() + 1);
        qDebug() << UI::what_to_change_.at(input.what_to_change);
        label->setText("Which style do you need");
        combo_box->clear();
        combo_box->addItem("snake_case");
        combo_box->addItem("camelCase");
        combo_box->addItem("PascalCase");
      } else if (step == 3) {
        input.necessary_style = static_cast<Style>(combo_box->currentIndex() + 1);
        qDebug() << UI::style_.at(input.necessary_style);
        label->setText("What is the original style");
        combo_box->clear();
        combo_box->addItem("snake_case");
        combo_box->addItem("camelCase");
        combo_box->addItem("PascalCase");
      } else if (step == 4) {
        input.original_style = static_cast<Style>(combo_box->currentIndex() + 1);
        qDebug() << UI::style_.at(input.original_style);
        label->setText("Create new file or change the current");
        combo_box->clear();
        combo_box->addItem("create new");
        combo_box->addItem("change current");
      } else if (step == 5) {
        input.change_or_create = static_cast<WorkWFile>(combo_box->currentIndex() + 1);
        qDebug() << UI::work_w_file_.at(input.change_or_create);
        combo_box->close();
        search_line_edit->close();
        send_button->close();

        label->setText(("Is everything correct? "
                        "\n Project path: " + input.dir_path
                        + "\nFile: " + input.file_path
                        + "\nYou want to change " + UI::what_to_change_.at(input.what_to_change)
                        + "\nYou need " + UI::style_.at(input.necessary_style)
                        + "\nThe original style is " + UI::style_.at(input.original_style)
                        + "\nYou want to " + UI::work_w_file_.at(input.change_or_create)).data());
        auto *buttons = new QHBoxLayout;
        buttons->addWidget(yes_button);
        buttons->addWidget(no_button);
        main_layout->addLayout(buttons);
        yes_button->show();
        no_button->show();
      }
      search_line_edit->clear();
      step++;
    });

    connect(yes_button, &QPushButton::clicked, [label, yes_button, no_button, this]() {
      while (QLayoutItem *item = main_layout->takeAt(0)) {
          delete item->widget();
          delete item;
      }
      auto pr = Project(input);
      auto change = Change(pr);
      auto save = Save(pr);
      QTextEdit *outputTextEdit = new QTextEdit(central_widget);
      outputTextEdit->setReadOnly(true);
      outputTextEdit->setAlignment(Qt::AlignLeft);
      main_layout->addWidget(outputTextEdit);
      QString output;
      for (const auto& [old_name, new_name] : change.old_new_names) {
        qDebug() << old_name << " -> " << new_name;
        output += QString::fromStdString(old_name.data()) + " -> " + QString::fromStdString(new_name) + "\n";
      }
      outputTextEdit->setPlainText(output);
    });

    connect(no_button, &QPushButton::clicked, [this]() {
      Begin();
    });
  }

};


#endif //MAINWINDOW_H
