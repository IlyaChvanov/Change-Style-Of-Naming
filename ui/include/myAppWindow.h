#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>

#include <QMainWindow>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>

#include "UI.h"

class MyAppWindow : public QMainWindow {
    Q_OBJECT

public:
    MyAppWindow(UserInput &input, QWidget *parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("Change style of naming");
        setMinimumSize(600, 600);

        auto *central_widget = new QWidget(this);
        auto *main_layout = new QVBoxLayout(central_widget);
        main_layout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
        auto *form_layout = new QVBoxLayout();

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

        connect(send_button, &QPushButton::clicked, [=, &input]() {
            static int step = 0;
            if (step == 0) {
                input.dir_path = search_line_edit->text().toStdString();
                qDebug() << "file is: " << input.dir_path;
                label->setText("Enter the file you want to change");
            } else if (step == 1) {
                input.file_path = search_line_edit->text().toStdString();
                search_line_edit->close();
                qDebug() << "root is: " << input.file_path;
                label->setText("What do you want to change");
                form_layout->addWidget(combo_box);
                combo_box->show();
                form_layout->removeWidget(send_button);
                form_layout->addWidget(send_button);
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
                                +"\nFile: " + input.file_path
                                +"\nYou want to change " + UI::what_to_change_.at(input.what_to_change)
                                +"\nYou need " + UI::style_.at(input.necessary_style)
                                +"\nThe original style is " + UI::style_.at(input.original_style)
                                +"\nYou want to " + UI::work_w_file_.at(input.change_or_create)).data());

                auto* buttons =  new QHBoxLayout;
                auto* yes_button = new QPushButton("yes", central_widget);
                auto* no_button = new QPushButton("no", central_widget);
                buttons->addWidget(yes_button);
                buttons->addWidget(no_button);
                main_layout->addLayout(buttons);
            }
            search_line_edit->clear();
            step++;
        });
    }
};
#endif //MAINWINDOW_H
