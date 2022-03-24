#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

#define UP_KEY      77
#define DOWN_KEY    80
#define ENTER_KEY   13
#define MAX_OPTION  4

#define ROW 10
#define COLUM 10

#define GAME_WIN 2

enum PlayerType{
    PLAYER_1 = 0,
    PLAYER_2 = 1
};

enum COLOR_CODE{
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    AQUA = 3,
    RED = 4,
    PURPLE = 5,
    YELLOW = 6,
    WHITE = 7
};

enum _MENU{
    PLAY_OFFLINE = 0,
    PLAY_ONLINE = 1,
    SEARCH_PLAYER = 2,
    SEARCH_MATCH = 3
};

enum NEXT_MENU{
    MAIN_MENU = 0,
    PLAY_OFF = 1,
    PLAY_ONL = 2,
    UN_KNOWN = 0xFF
};

enum MATCH_RESULT{
    PLAYER_1_WIN,
    PLAYER_2_WIN,
    PLAYER_1_LOSE,
    PLAYER_2_LOSE,
    PLAYER_1_AND_2_DRAW
};

#endif // CONFIG_H
