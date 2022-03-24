#ifndef PLAYER_H
#define PLAYER_H

#include "game_UI.h"
#include "rules.h"
#include "file.h"

using namespace std;

class Player{
private:
    string namePL1;
    string namePL2;
    uint8_t matchID;

    uint8_t playerFirstWin;
    uint8_t playerFirstLose;
    uint8_t playerSecondWin;
    uint8_t playerSecondLose;
    uint8_t playerDraw;

    Game_UI myUI;
    Rule gameRule;
    File myFile;

public:
    uint8_t menu;
    Player();
    ~Player();
    void playerInit();
    void playerInput(PlayerType type);
    void playerTick(void);
    void playerCheckWin(void);
    void playerPlaying(void);

    void setNamePlayer(PlayerType type);
    void increase(MATCH_RESULT result);
    void resetResult(void);
    void clearTwoMember(int *arr, int &number);

    void playerReplay(void);
    void playerRefresh(void);

    string getPlayerName(PlayerType type);
};

#endif // PLAYER_H
