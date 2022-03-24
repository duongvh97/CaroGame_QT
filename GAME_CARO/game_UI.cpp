#include "game_UI.h"

Game_UI::Game_UI(){
    index = 0;
    selectedMenu = 0xFF;
}
Game_UI::~Game_UI(){

}
/* @brief: Set text color
*  @param: None
*  @return: None
*/
void Game_UI::setColor(const uint8_t color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
/* @brief: Sett pointer console in position x, y
*  @param: None
*  @return: None
*/
void Game_UI::gotoXY(const uint8_t x,const uint8_t y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
/* @brief: Highlight selection
*  @param: None
*  @return: None
*/
void Game_UI::hlightSelection(const uint8_t y,const uint8_t color_member, COLOR_CODE color, string msg){
    colorTable[color_member] = color;
    gotoXY(0, y);
    setColor(colorTable[color_member]);
    cout << msg;
}
/* @brief: Create menu
*  @param: None
*  @return: None
*/
void Game_UI::createMenu(){
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 20;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    setColor(YELLOW);
    cout << "********CARO GAME MENU**********";
    while(1){
        if(index == 0){
            hlightSelection(1, 0, RED, "1. Play Offline");
            hlightSelection(2, 1, WHITE, "2. Play Online");
            hlightSelection(3, 2, WHITE, "3. Search Player");
            hlightSelection(4, 3, WHITE, "4. Search Match");
            gotoXY(0, 1);
        }
        else if(index == 1){
            hlightSelection(1, 0, WHITE, "1. Play Offline");
            hlightSelection(2, 1, RED, "2. Play Online");
            hlightSelection(3, 2, WHITE, "3. Search Player");
            hlightSelection(4, 3, WHITE, "4. Search Match");
            gotoXY(0, 2);
        }
        else if(index == 2){
            hlightSelection(1, 0, WHITE, "1. Play Offline");
            hlightSelection(2, 1, WHITE, "2. Play Online");
            hlightSelection(3, 2, RED, "3. Search Player");
            hlightSelection(4, 3, WHITE, "4. Search Match");
            gotoXY(0, 3);
        }
        else if(index == 3){
            hlightSelection(1, 0, WHITE, "1. Play Offline");
            hlightSelection(2, 1, WHITE, "2. Play Online");
            hlightSelection(3, 2, WHITE, "3. Search Player");
            hlightSelection(4, 3, RED, "4. Search Match");
            gotoXY(0, 4);
        }
        char temp = _getch();
        if(temp == DOWN_KEY){
            index++;
            if(index == MAX_OPTION) index = 0;
        }
        else if(temp == '\r'){
            system("cls");
            if(index == 0){
                selectedMenu = PLAY_OFFLINE;
                break;
            }
            else if(index == 1){
                selectedMenu = PLAY_ONLINE;
                break;
            }
            else if(index == 2){
                selectedMenu = SEARCH_PLAYER;
                break;
            }
            else if(index == 3){
                selectedMenu = SEARCH_MATCH;
                setColor(WHITE);
                break;
            }
        }
    }
}
/* @brief: getSelection of user
*  @param: None
*  @return: Return user's selection menu
*/
int Game_UI::getSelection(){
    return selectedMenu;
}
/* @brief: Draw board
*  @param: None
*  @return: None
*/
void Game_UI::createBoard(){
    createMenu();
    clearBoard();
    if(selectedMenu == PLAY_OFFLINE || selectedMenu == PLAY_ONLINE){
        cout << "                 CARO GAME" << endl;
        for(uint8_t i = 0; i < COLUM + 1; i++){
            cout << "----";
        }
        cout << endl;
        cout << "          PLAYER 1: X    PLAYER 2: O" << endl;
        for(uint8_t i = 0; i < COLUM + 1; i++){
            cout << "----";
        }
        cout << endl;
        cout << "  ";
        for(int i = 0; i < COLUM; i++){
            if(i < 10){
                cout << "   " << i;
            }
            else if(i >= 10 && i < 100){
                cout << "  " << i;
            }
        }
        cout << endl;
        for(uint8_t i = 0; i < COLUM + 1; i++){
            cout << "---+";
        }
        cout << endl;

        for(int i = 0; i < ROW; i++){
            if(i < 10){
                cout << " " << i << " |";
            }
            else if(i >= 10 && i < 100){
                cout << " " << i << "|";
            }
            //
            for(int j = 0; j < COLUM; j++){
                cout << " " << caroBoard[i][j] << " |";
            }
            //
            cout << endl;
            for(uint8_t i = 0; i < COLUM + 1; i++){
                cout << "---+";
            }
            cout << endl;
        }
    }
}
/* @brief: Reload again board
*  @param: None
*  @return: None
*/
void Game_UI::reloadBoard(){
    if(selectedMenu == PLAY_OFFLINE || selectedMenu == PLAY_ONLINE || selectedMenu == SEARCH_MATCH){
        cout << "                 CARO GAME" << endl;
        for(uint8_t i = 0; i < COLUM + 1; i++){
            cout << "----";
        }
        cout << endl;
        cout << "          PLAYER 1: X    PLAYER 2: O" << endl;
        for(uint8_t i = 0; i < COLUM + 1; i++){
            cout << "----";
        }
        cout << endl;
        cout << "  ";
        for(int i = 0; i < COLUM; i++){
            if(i < 10){
                cout << "   " << i;
            }
            else if(i >= 10 && i < 100){
                cout << "  " << i;
            }
        }
        cout << endl;
        for(uint8_t i = 0; i < COLUM + 1; i++){
            cout << "---+";
        }
        cout << endl;

        for(int i = 0; i < ROW; i++){
            if(i < 10){
                cout << " " << i << " |";
            }
            else if(i >= 10 && i < 100){
                cout << " " << i << "|";
            }
            //
            for(int j = 0; j < COLUM; j++){
                cout << " " << caroBoard[i][j] << " |";
            }
            //
            cout << endl;
            for(uint8_t i = 0; i < COLUM + 1; i++){
                cout << "---+";
            }
            cout << endl;
        }
    }
}
/* @brief: Clear all 'X', 'O'
*  @param: None
*  @return: None
*/
void Game_UI::clearBoard(){
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUM; j++)
        {
            caroBoard[i][j] = ' ';
        }
    }
}
/* @brief: Get x position of member x in array data
*  @param: Member x
*  @return: x position
*/
int Game_UI::getValueX(const uint8_t x){
    return GameData[x].x;
}
/* @brief: Get y position of member x in array data
*  @param: Member y
*  @return: y position
*/
int Game_UI::getValueY(const uint8_t y){
    return GameData[y].y;
}
/* @brief: Get number of member in array data
*  @param: None
*  @return: Number of member
*/
int Game_UI::getGameDataSize(){
    return GameData.size();
}
/* @brief: Check x, y is invalid
*  @param: x, y
*  @return: true or false
*/
bool Game_UI::isInvalidXY(const int x, const int y){
    if( (x < 0) || (x > ROW - 1) || (y < 0) || (y > COLUM - 1) ){
        return false;
    }
    for(int i = 0; i < getGameDataSize(); i++){
        if(getValueX(i) == x && getValueY(i) == y){
            return false;
        }
    }
    return true;
}
/* @brief: Input player's name
*  @param: Name and Player 1 or 2
*  @return: None
*/
void Game_UI::inputNamePlayer(string &name, PlayerType type){
    string temp;
    do{
        if(type == PLAYER_1){
            cout << "Input Player 1 name: ";
        }
        else{
            cout << "Input Player 2 name: ";
        }
        cin >> temp;
    }while(temp == "");
    name = temp;
}
/* @brief: Push point(x, y) in array
*  @param: Point
*  @return: None
*/
void Game_UI::pushInVector(Point_t point){
    GameData.push_back(point);
}
/* @brief: Tick X or O in (x, y)
*  @param: x, y, player
*  @return: None
*/
void Game_UI::tickBoard(const int x, const int y, PlayerType type){
    if(isInvalidXY(x, y) ==  true){
        Point_t temp;
        temp.x = x;
        temp.y = y;
        pushInVector(temp);
        for(uint8_t i = 0; i < ROW; i++){
            for(uint8_t j = 0; j < COLUM; j++){
                if(x == i && y == j){
                    if(type == PLAYER_1){
                        caroBoard[x][y] = 'X';
                    }
                    else{
                        caroBoard[x][y] = 'O';
                    }
                }
            }
        }
    }
    else{
        cout << "Position error, input again!" << endl;
        for(uint8_t i = 0; i < 3; i++){
            Beep(1000, 300);
            Sleep(200);
        }
    }
}
/* @brief: Tick no check for replay
*  @param: x, y, player
*  @return: None
*/
void Game_UI::tickBoardNoCheck(const int x, const int y, PlayerType type){
    for(uint8_t i = 0; i < ROW; i++){
        for(uint8_t j = 0; j < COLUM; j++){
            if(x == i && y == j){
                if(type == PLAYER_1){
                    caroBoard[x][y] = 'X';
                }
                else{
                    caroBoard[x][y] = 'O';
                }
            }
        }
    }
}
/* @brief: Clear all member of array data
*  @param: None
*  @return: None
*/
void Game_UI::clearData(void){
    GameData.clear();
}
/* @brief: Copy data vector
*  @param: None
*  @return: None
*/
void Game_UI::copyData(vector<Point_t> &point){
    point = GameData;
}



