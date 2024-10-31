#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QVBoxLayout>
#include <QLineEdit>

#include <QMainWindow>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include "UI.h"

class MyAppWindow : public QMainWindow {
    Q_OBJECT
public:
    MyAppWindow(UserInput& input, QWidget* parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("Change style of naming");
        setMinimumSize(600, 600);

        auto* central_widget = new QWidget(this);
        auto* main_layout = new QVBoxLayout(central_widget);
        main_layout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
        auto* formLayout = new QVBoxLayout();

        auto* label = new QLabel("Enter the path of file you want to change", central_widget);
        label->setAlignment(Qt::AlignCenter);
        formLayout->addWidget(label);

        auto* search_line_edit = new QLineEdit(central_widget);
        formLayout->addWidget(search_line_edit);

        auto* send_button = new QPushButton("accept", central_widget);
        formLayout->addWidget(send_button);
        main_layout->addLayout(formLayout);

        main_layout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
        setCentralWidget(central_widget);

        connect(send_button, &QPushButton::clicked, [search_line_edit, &input]() {
            input.file_path = search_line_edit->text().toStdString();
            qDebug() << input.file_path;
        });
    }
};
#endif //MAINWINDOW_H
