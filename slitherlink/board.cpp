#include "board.h"
#include <cstdlib>
#include <Qt>

Board::Board(int width, int height)
    : width(width), height(height) {
    labels.assign(width, std::vector<CellLabel>(height, LABEL_NONE));
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            labels[i][j] = CellLabel(rand() % 5 - 1);
        }
    }
}

void Board::fillFromString(std::string string) {
    Q_ASSERT((int) string.length() == width * height);
    int index = 0;
    for(int j = 0; j < height; j++) {
        for(int i = 0; i < width; i++) {
            if(string[index] >= '0' && string[index] <= '4') {
                labels[i][j] = CellLabel(string[index] - '0');
            }else {
                labels[i][j] = LABEL_NONE;
            }
            index++;
        }
    }
}

std::string Board::toString(int i, int j) {
    if(labels[i][j] == LABEL_NONE) {
        return "";
    }
    return std::to_string((int) labels[i][j]);
}
