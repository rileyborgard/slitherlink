#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include "board.h"

class BoardWidget : public QWidget {
    Q_OBJECT
public:
    explicit BoardWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);
    void setBoard(Board *board);

private:
    Board *board;
};

#endif // BOARDWIDGET_H
