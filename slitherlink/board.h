#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

enum CellLabel {
    LABEL_NONE = -1,
    LABEL_ZERO = 0,
    LABEL_ONE = 1,
    LABEL_TWO = 2,
    LABEL_THREE = 3,
    LABEL_FOUR = 4
};

class Board {
public:
    Board(int width, int height);

    void fillFromString(std::string string);
    std::string toString(int i, int j);

    int width;
    int height;

    std::vector<std::vector<CellLabel>> labels;
};

#endif // BOARD_H
