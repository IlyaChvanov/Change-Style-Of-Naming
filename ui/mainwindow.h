#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow() override;

private:
    Ui::mainwindow *ui;
};


#endif //MAINWINDOW_H
