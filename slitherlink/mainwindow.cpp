#include "mainwindow.h"
#include "boardwidget.h"
#include "board.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle("Slitherlink");
    resize(800, 800);
    setMinimumSize(200, 200);

    Board *board = new Board(10, 10);
    std::string hints =
            "3  313  0 "
            "3       3 "
            "    12  21"
            " 32 10    "
            " 30       "
            "       23 "
            "    22 23 "
            "23  33    "
            " 3       3"
            " 2  012  3";

    board->fillFromString(hints);

    BoardWidget *boardWidget = new BoardWidget(this);
    boardWidget->setBoard(board);
    setCentralWidget(boardWidget);
}

MainWindow::~MainWindow() {

}
