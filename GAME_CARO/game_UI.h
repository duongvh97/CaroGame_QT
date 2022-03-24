#ifndef GAME_UI_H
#define GAME_UI_H

#include "config.h"
#include <conio.h>
#include <vector>

typedef struct{
    int x;
    int y;
}Point_t;

class Game_UI{
private:
vector<Point_t> GameData;
public:
    int index;
    uint8_t selectedMenu;
    uint8_t colorTable[4] = {WHITE, WHITE, WHITE, WHITE};
    char caroBoard[ROW][COLUM];

    Game_UI();
    ~Game_UI();
    void setColor(const uint8_t color);
    void gotoXY(const uint8_t x, const uint8_t y);
    void hlightSelection(const uint8_t y,const uint8_t color_member, COLOR_CODE color, string msg);
    void createMenu(void);
    int getSelection(void);
    void createBoard(void);
    void reloadBoard(void);
    void clearBoard(void);
    int getValueX(const uint8_t x);
    int getValueY(const uint8_t y);
    int getGameDataSize(void);
    bool isInvalidXY(const int x, const int y);
    void inputNamePlayer(string &name, PlayerType type);
    void pushInVector(Point_t point);
    void tickBoard(const int x, const int y, PlayerType type);
    void tickBoardNoCheck(const int x, const int y, PlayerType type);
    void clearData(void);
    void copyData(vector<Point_t> &point);
};

#endif // GAME_UI_H
