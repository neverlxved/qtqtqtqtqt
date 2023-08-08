#ifndef CALCULATOR_MAINWINDOW_H
#define CALCULATOR_MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QtGui>


class MainWindow : public QMainWindow {
Q_OBJECT;

public:
    explicit MainWindow(const QString& windowTitle, QWidget* parent = nullptr);

private:
    QWidget *centralWidget;
    QGridLayout *gridLayout;



    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btn7;
    QPushButton *btn8;
    QPushButton *btn9;
    QPushButton *btnStart;

    QLabel *label1;



private slots:

};


#endif //CALCULATOR_MAINWINDOW_H
