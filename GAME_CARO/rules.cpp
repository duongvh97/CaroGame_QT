#include "rules.h"

Rule::Rule(){

}

Rule::~Rule(){

}
/* @brief: Check win in row
*  @param: x, y, board
*  @return: true or false
*/
bool Rule::checkWinInRow(const int x, const int y, const char board[ROW][COLUM]){
    int xVal = x;
    int yVal = y;
    char temp = board[xVal][yVal];
    int counter = 1;
    int i = yVal;
    while(i > 0){
        i--;
        if(board[xVal][i]  == temp){
            counter++;
            if(counter == GAME_WIN){
                return true;
            }
        }
        else{
            break;
        }
    }
    i = yVal;
    while(i < COLUM - 1){
        i++;
        if(board[xVal][i] == temp){
            counter++;
            if(counter == GAME_WIN){
                return true;
            }
        }
        else{
            return false;
        }
    }
    return false;
}
/* @brief: Check win in colum
*  @param: x, y, board
*  @return: true or false
*/
bool Rule::checkWinInColum(const int x, const int y, const char board[ROW][COLUM]){
    int xVal = x;
    int yVal = y;
    char temp = board[xVal][yVal];
    int counter = 1;
    int i = xVal;
    while(i > 0){
        i--;
        if(board[i][yVal]  == temp){
            counter++;
            if(counter == GAME_WIN){
                return true;
            }
        }
        else{
            break;
        }
    }
    i = xVal;
    while(i < COLUM - 1){
        i++;
        if(board[i][yVal] == temp){
            counter++;
            if(counter == GAME_WIN){
                return true;
            }
        }
        else{
            return false;
        }
    }
    return false;
}
/* @brief: Check win in cross
*  @param: x, y, board
*  @return: true or false
*/
bool Rule::checkWinInCrossFirst(const int x, const int y, const char board[ROW][COLUM]){
    int xVal = x;
    int yVal = y;
    char temp = board[xVal][yVal];
    int counter = 1;
    int i = xVal;
    int j = yVal;
    while(i > 0 && j > 0){
        i--;
        j--;
        if(board[i][j] == temp){
            counter++;
            if(counter == GAME_WIN){
                return true;
            }
        }
        else{
            break;
        }
    }
    i = xVal;
    j = yVal;
    while( (i < ROW - 1) && (j < COLUM - 1) ){
        i++;
        j++;
        if(board[i][j] == temp){
            counter++;
            if(counter == GAME_WIN){
                return true;
            }
        }
        return false;
    }
    return false;
}
/* @brief: Check win in cross
*  @param: x, y, board
*  @return: true or false
*/
bool Rule::checkWinInCrossSecond(const int x, const int y, const char board[ROW][COLUM]){
    int xVal = x;
    int yVal = y;
    char temp = board[xVal][yVal];
    int counter = 1;
    int i = xVal;
    int j = yVal;
    while(i > 0 && (j < COLUM - 1)){
        i--;
        j++;
        if(board[i][j] == temp){
            counter++;
            if(counter == GAME_WIN){
                return true;
            }
        }
        else{
            break;
        }
    }
    i = xVal;
    j = yVal;
    while( (i < ROW - 1) && j > 0 ){
        i++;
        j--;
        if(board[i][j] == temp){
            counter++;
            if(counter == GAME_WIN){
                return true;
            }
        }
        return false;
    }
    return false;
}
/* @brief: Check no winner
*  @param: turn
*  @return: true or false
*/
bool Rule::checkGameOver(const uint8_t turn){
    if(turn == (ROW * COLUM)) return true;
    else return false;
}
/* @brief: Check win
*  @param: x, y, board
*  @return: true or false
*/
bool Rule::checkWin(const int x, const int y, const char (*board)[COLUM]){
    if(checkWinInRow(x, y, board)) return true;
    else if(checkWinInColum(x,y, board)) return true;
    else if(checkWinInCrossFirst(x, y, board)) return true;
    else if(checkWinInCrossSecond(x, y, board)) return true;
    return false;
}



