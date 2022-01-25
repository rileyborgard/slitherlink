#include "boardwidget.h"
#include <QPainter>
#include <QString>

BoardWidget::BoardWidget(QWidget *parent) : QWidget(parent) {

}

void BoardWidget::setBoard(Board *board) {
    this->board = board;
}

void BoardWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::RenderHint::Antialiasing);

    QColor backgroundColor = QColor(32, 32, 32);
    QColor pointColor = Qt::white;

    painter.fillRect(0, 0, width(), height(), backgroundColor);

    float padding = 0.1;

    float centerX = width() / 2, centerY = height() / 2;

    float cellSize = std::min(2.0 * centerX / (board->width + 1), 2.0 * centerY / (board->height + 1));

    cellSize *= (1 - padding);

    float startX = centerX - cellSize * (board->width + 1) / 2 + cellSize / 2;
    float startY = centerY - cellSize * (board->height + 1) / 2 + cellSize / 2;

    QPen pen;
    pen.setColor(pointColor);
    pen.setWidth(1);
    painter.setPen(pen);
    painter.setBrush(pointColor);

    float ellipseSize = cellSize / 10;

    for(int i = 0; i <= board->width; i++) {
        for(int j = 0; j <= board->height; j++) {
            painter.drawEllipse(startX + i * cellSize - ellipseSize / 2, startY + j * cellSize - ellipseSize / 2, ellipseSize, ellipseSize);
        }
    }

    QFont font = painter.font();
    int fontHeight = std::max(8, (int) cellSize / 3);
    font.setPointSize(fontHeight);
    painter.setFont(font);

    for(int i = 0; i < board->width; i++) {
        for(int j = 0; j < board->height; j++) {
            painter.drawText(QRectF(startX + i * cellSize, startY + j * cellSize, cellSize, cellSize), Qt::AlignCenter, board->toString(i, j).c_str());
        }
    }
}
