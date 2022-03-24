#ifndef RULES_H
#define RULES_H
#include "config.h"

class Rule{
private:
public:
    Rule();
    ~Rule();
    bool checkWinInRow(const int x, const int y, const char board[ROW][COLUM]);
    bool checkWinInColum(const int x, const int y, const char board[ROW][COLUM]);
    bool checkWinInCrossFirst(const int x, const int y, const char board[ROW][COLUM]);
    bool checkWinInCrossSecond(const int x, const int y, const char board[ROW][COLUM]);
    bool checkGameOver(const uint8_t turn);
    bool checkWin(const int x, const int y, const char board[ROW][COLUM]);
};

#endif // RULES_H
