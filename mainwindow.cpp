//
// Created by Ant1 on 26.07.2023.
//

#include "mainwindow.h"

//int MainWindow::current_player = PLAYER_1;

MainWindow::MainWindow(const QString &windowTitle, QWidget *parent) :
        QMainWindow(parent),
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
        label1(new QLabel()),
        Statistics(new QLabel()),
        p1(0),
        p2(0),
        ties(0)
        {



    initButtons();
    initConnections();
    addStyles();
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
    addStyles();
    label1->setText("Сейчас ход Игрока 1");
    gameStarted = true;
    current_player = PLAYER_1;
    availibleTurns = true;
}

void MainWindow::gameStep() {
    if (!gameStarted) {
        return;
    }
    if (current_player == 1) {
        auto* btn = dynamic_cast<QPushButton*>(sender());
        if(btn->text() == ""){
        btn->setText("x");
        btn->setStyleSheet("QPushButton{background: black; color: white; border-radius: 5px; height: 100%; font-size: 38px; border-color: white}"
                           "QPushButton:hover{background: black;}");
        label1->setText("Сейчас ход Игрока 2");
        getWinner();
        current_player = PLAYER_2;}
    } else {
        auto* btn = dynamic_cast<QPushButton*>(sender());
        if(btn->text() == ""){
        btn->setText("o");
        btn->setStyleSheet("QPushButton{background: black; color: white; border-radius: 5px; height: 100%; font-size: 38px; border-color: white}"
                           "QPushButton:hover{background: black;}");
        label1->setText("Сейчас ход Игрока 1");
        getWinner();
        current_player = PLAYER_1;}
    }
}

void MainWindow::addStyles() {
    centralWidget->setStyleSheet("background-color: black");

    label1->setStyleSheet("font-size: 18px; color: white");
    label1->setText("\tДобро пожаловать в TicTacToe by neverlxved!\n"
                    "Надеюсь вы хорошо проведете время!");
    label1->setAlignment(Qt::AlignCenter);
    Statistics->setStyleSheet("font-size: 26px; color: green;");
    Statistics->setText(QString("    ╔ Статистика игр ッ\n"
                        "    ╠ Побед игрока 1: %1\n"
                        "    ╠ Побед игрока 2: %2\n"
                        "    ╚ Ничьих: %3").arg(p1).arg(p2).arg(ties));
    Statistics->setAlignment(Qt::AlignLeft);




    btn1->setStyleSheet("QPushButton{background: darkgreen ; color: white; border-radius: 5px; height: 100%; font-size: 38px}"
                        "QPushButton:hover{background: lightgreen;}");
    btn1->setText("");
    btn2->setStyleSheet("QPushButton{background: darkgreen ; color: white; border-radius: 5px; height: 100%; font-size: 38px}"
                        "QPushButton:hover{background: lightgreen;}");
    btn2->setText("");
    btn3->setStyleSheet("QPushButton{background: darkgreen ; color: white; border-radius: 5px; height: 100%; font-size: 38px}"
                        "QPushButton:hover{background: lightgreen;}");
    btn3->setText("");
    btn4->setStyleSheet("QPushButton{background: darkgreen ; color: white; border-radius: 5px; height: 100%; font-size: 38px}"
                        "QPushButton:hover{background: lightgreen;}");
    btn4->setText("");
    btn5->setStyleSheet("QPushButton{background: darkgreen ; color: white; border-radius: 5px; height: 100%; font-size: 38px}"
                        "QPushButton:hover{background: lightgreen;}");
    btn5->setText("");
    btn6->setStyleSheet("QPushButton{background: darkgreen ; color: white; border-radius: 5px; height: 100%; font-size: 38px}"
                        "QPushButton:hover{background: lightgreen;}");
    btn6->setText("");
    btn7->setStyleSheet("QPushButton{background: darkgreen ; color: white; border-radius: 5px; height: 100%; font-size: 38px}"
                        "QPushButton:hover{background: lightgreen;}");
    btn7->setText("");
    btn8 ->setStyleSheet("QPushButton{background: darkgreen ; color: white; border-radius: 5px; height: 100%; font-size: 38px}"
                         "QPushButton:hover{background: lightgreen;}");
    btn8->setText("");
    btn9->setStyleSheet("QPushButton{background: darkgreen ; color: white; border-radius: 5px; height: 100%; font-size: 38px}"
                        "QPushButton:hover{background: lightgreen;}");
    btn9->setText("");
    btnStart->setStyleSheet("QPushButton{background: darkgreen ; color: white; border-radius: 5px; height: 60%; font-size: 24px}"
                            "QPushButton:hover{background: lightgreen;}");
}

void MainWindow::initButtons() {
    setFixedSize(750, 550);
    setCentralWidget(centralWidget);
    centralWidget->setLayout(gridLayout);

    gridLayout->addWidget(Statistics, 1, 3, 2, 2);
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
}

void MainWindow::getWinner() {

        if (btn1->text() == "x" && btn2->text() == "x" && btn3->text() == "x") {
            gameStarted = false;
            label1->setText("Победил Игрок 1!");
            checkStat();
        }
        if (btn4->text() == "x" && btn5->text() == "x" && btn6->text() == "x") {
            gameStarted = false;
            label1->setText("Победил Игрок 1!");
            checkStat();
        }
        if (btn7->text() == "x" && btn8->text() == "x" && btn9->text() == "x") {
            gameStarted = false;
            label1->setText("Победил Игрок 1!");
            checkStat();
        }
        if (btn1->text() == "o" && btn2->text() == "o" && btn3->text() == "o") {
            gameStarted = false;
            label1->setText("Победил Игрок 2!");
            checkStat();
        }
        if (btn4->text() == "o" && btn5->text() == "o" && btn6->text() == "o") {
            gameStarted = false;
            label1->setText("Победил Игрок 2!");
            checkStat();
        }
        if (btn7->text() == "o" && btn8->text() == "o" && btn9->text() == "o") {
            gameStarted = false;
            label1->setText("Победил Игрок 2!");
            checkStat();
        }
        if (btn1->text() == "x" && btn5->text() == "x" && btn9->text() == "x") {
            gameStarted = false;
            label1->setText("Победил Игрок 1!");
            checkStat();
        }
        if (btn3->text() == "x" && btn5->text() == "x" && btn7->text() == "x") {
            gameStarted = false;
            label1->setText("Победил Игрок 1!");
            checkStat();
        }
        if (btn1->text() == "o" && btn5->text() == "o" && btn9->text() == "o") {
            gameStarted = false;
            label1->setText("Победил Игрок 2!");
            checkStat();
        }
        if (btn3->text() == "o" && btn5->text() == "o" && btn7->text() == "o") {
            gameStarted = false;
            label1->setText("Победил Игрок 2!");
            checkStat();
        }
        if (btn1->text() == "x" && btn4->text() == "x" && btn7->text() == "x") {
            gameStarted = false;
            label1->setText("Победил Игрок 1!");
            checkStat();
        }
        if (btn2->text() == "x" && btn5->text() == "x" && btn8->text() == "x") {
            gameStarted = false;
            label1->setText("Победил Игрок 1!");
            checkStat();
        }
        if (btn3->text() == "x" && btn6->text() == "x" && btn9->text() == "x") {
            gameStarted = false;
            label1->setText("Победил Игрок 1!");
            checkStat();
        }
        if (btn1->text() == "o" && btn4->text() == "o" && btn7->text() == "o") {
            gameStarted = false;
            label1->setText("Победил Игрок 2!");
            checkStat();
        }
        if (btn2->text() == "o" && btn5->text() == "o" && btn8->text() == "o") {
            gameStarted = false;
            label1->setText("Победил Игрок 2!");
            checkStat();
        }
        if (btn3->text() == "o" && btn6->text() == "o" && btn9->text() == "o") {
            gameStarted = false;
            label1->setText("Победил Игрок 2!");
            checkStat();
        } else {
            checkTurns();
            if(!availibleTurns){
                label1->setText("Ничья!");
                checkStat();
                gameStarted = false;
            }
        }

}

void MainWindow::checkTurns() {
    if (btn1->text() != "" && btn2->text() != "" && btn3->text() != "" && btn4->text() != "" && btn5->text() != "" && btn6->text() != "" && btn7->text() != "" && btn8->text() != "" && btn9->text() != "") {
        availibleTurns = false;
    }
}

void MainWindow::checkStat() {
    if(label1->text()=="Победил Игрок 1!"){
        p1++;
    }
    else if(label1->text()=="Победил Игрок 2!"){
        p2++;
    }
    else if(label1->text()=="Ничья!"){
        ties++;
    }
}

