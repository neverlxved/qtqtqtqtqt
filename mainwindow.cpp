//
// Created by Ant1 on 26.07.2023.
//

#include "mainwindow.h"

//int MainWindow::current_player = PLAYER_1;

MainWindow::MainWindow(const QString &windowTitle, QWidget *parent) :
        QMainWindow(parent) ,
        centralWidget(new QWidget()),
        gridLayout(new QGridLayout()),
        btn1(new QPushButton("")),
        btn2(new QPushButton("")),
        btn3(new QPushButton("")),
        btn4(new QPushButton("")),
        btn5(new QPushButton("")),
        btn6(new QPushButton("")),
        btn7(new QPushButton("")),
        btn8(new QPushButton("")),
        btn9(new QPushButton("")),
        btnStart(new QPushButton("Начнем новую игру? :) ")),
        label1(new QLabel())
        {
    setWindowTitle(windowTitle);

    centralWidget->setStyleSheet("background-color: Black");

    btn1->setStyleSheet("QPushButton{background: darkgreen ; color: white; border-radius: 5px; height: 100%}"
                                "QPushButton:hover{background: lightgreen;}");
    btn2->setStyleSheet("QPushButton{background: darkgreen ; color: white; border-radius: 5px; height: 100%}"
                                "QPushButton:hover{background: lightgreen;}");
    btn3->setStyleSheet("QPushButton{background: darkgreen ; color: white; border-radius: 5px; height: 100%}"
                                "QPushButton:hover{background: lightgreen;}");
    btn4->setStyleSheet("QPushButton{background: darkgreen ; color: white; border-radius: 5px; height: 100%}"
                                "QPushButton:hover{background: lightgreen;}");
    btn5->setStyleSheet("QPushButton{background: darkgreen ; color: white; border-radius: 5px; height: 100%}"
                                "QPushButton:hover{background: lightgreen;}");
    btn6->setStyleSheet("QPushButton{background: darkgreen ; color: white; border-radius: 5px; height: 100%}"
                                "QPushButton:hover{background: lightgreen;}");
    btn7->setStyleSheet("QPushButton{background: darkgreen ; color: white; border-radius: 5px; height: 100%}"
                                "QPushButton:hover{background: lightgreen;}");
    btn8 ->setStyleSheet("QPushButton{background: darkgreen ; color: white; border-radius: 5px; height: 100%}"
                                "QPushButton:hover{background: lightgreen;}");
    btn9->setStyleSheet("QPushButton{background: darkgreen ; color: white; border-radius: 5px; height: 100%}"
                                "QPushButton:hover{background: lightgreen;}");
    btnStart->setStyleSheet("QPushButton{background: darkgreen ; color: white; border-radius: 5px; height: 60%; font-size: 24px}"
                                "QPushButton:hover{background: lightgreen;}");


    label1->setText("\tДобро пожаловать в XnO!\n"
                    "Надеюсь вы хорошо проведете время!");
    label1->setStyleSheet("font-size: 18px, ");
    label1->setAlignment(Qt::AlignCenter);

    setFixedSize(450, 550);
    setCentralWidget(centralWidget);
    centralWidget->setLayout(gridLayout);

    gridLayout->addWidget(label1, 0, 0, 1, 3);
    gridLayout->addWidget(btn1, 1, 0 , 1 ,1) ;
    gridLayout->addWidget(btn2, 1, 1, 1 ,1);
    gridLayout->addWidget(btn3, 1, 2, 1, 1);
    gridLayout->addWidget(btn4, 2, 0 , 1 , 1);
    gridLayout->addWidget(btn5, 2 ,1 ,1, 1);
    gridLayout->addWidget(btn6, 2, 2, 1, 1);
    gridLayout->addWidget(btn7, 3, 0 ,1 ,1);
    gridLayout->addWidget(btn8, 3, 1, 1 , 1);
    gridLayout->addWidget(btn9, 3, 2, 1, 1);
    gridLayout->addWidget(btnStart, 4, 0, 1, 3);

    initConnections();
}

void MainWindow::initConnections() {
    connect(btnStart, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(btn1, &QPushButton::clicked, this, &MainWindow::gameStep);
    connect(btn2, &QPushButton::clicked, this, &MainWindow::gameStep);
    connect(btn3, &QPushButton::clicked, this, &MainWindow::gameStep);
    connect(btn4, &QPushButton::clicked, this, &MainWindow::gameStep);
    connect(btn5, &QPushButton::clicked, this, &MainWindow::gameStep);
    connect(btn6, &QPushButton::clicked, this, &MainWindow::gameStep);
    connect(btn7, &QPushButton::clicked, this, &MainWindow::gameStep);
    connect(btn8, &QPushButton::clicked, this, &MainWindow::gameStep);
    connect(btn9, &QPushButton::clicked, this, &MainWindow::gameStep);
}

void MainWindow::startGame() {
    label1->setText("Сейчас ход Игрока 1");
    gameStarted = true;
}

void MainWindow::gameStep() {
    if (!gameStarted) {
        return;
    }

    if (current_player == 1) {
        auto* btn = dynamic_cast<QPushButton*>(sender());
        btn->setText("x");
        current_player = PLAYER_2;
    } else {
        auto* btn = dynamic_cast<QPushButton*>(sender());
        btn->setText("o");
        current_player = PLAYER_1;
    }
}
