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

        auto* centralWidget = new QWidget(this);
        auto* mainLayout = new QVBoxLayout(centralWidget);
        mainLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
        auto* formLayout = new QVBoxLayout();

        auto* label = new QLabel("Enter the path of file you want to change", centralWidget);
        label->setAlignment(Qt::AlignCenter);
        formLayout->addWidget(label);

        auto* searchLineEdit = new QLineEdit(centralWidget);
        formLayout->addWidget(searchLineEdit);

        auto* send_button = new QPushButton("accept", centralWidget);
        formLayout->addWidget(send_button);
        mainLayout->addLayout(formLayout);

        mainLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
        setCentralWidget(centralWidget);

        connect(send_button, &QPushButton::clicked, [searchLineEdit, &input]() {
            input.file_path = searchLineEdit->text().toStdString();
            qDebug() << input.file_path;
        });
    }
};
#endif //MAINWINDOW_H
