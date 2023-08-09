#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w("TicTacToe by neverlxved!");
    w.setWindowIcon(QIcon(":images/tictactoeicon.ico"));
    w.show();
    return QApplication::exec();
}
