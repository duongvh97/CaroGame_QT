#include "player.h"
#include <conio.h>

Player::Player(){
    this->namePL1 = "Unknow";
    this->namePL2 = "Unknow";
    this->matchID = 0;
    this->menu = 0;
    this->playerFirstWin = 0;
    this->playerFirstLose = 0;
    this->playerDraw = 0;
    this->playerSecondWin = 0;
    this->playerSecondLose= 0;
}
Player::~Player(){
}
/* @brief: For user select menu
*  @param: None
*  @return: None
*/
void Player::playerInit(){
    myUI.createBoard();
    switch (myUI.getSelection()){
    case PLAY_OFFLINE:
        system("color 06");
        setNamePlayer(PLAYER_1);
        setNamePlayer(PLAYER_2);
        cout << "Saving data..." << endl;
        Sleep(800);
        playerRefresh();
        menu = PLAY_OFF;
        break;
    case PLAY_ONLINE:
        system("cls");
        cout << "Function is developing..." << endl;
        system("pause");
        menu = MAIN_MENU;
        system("cls");
        break;
    case SEARCH_PLAYER:
        myFile.searchPlayerInfor();
        system("cls");
        menu = MAIN_MENU;
        break;
    case SEARCH_MATCH:
        playerReplay();
        system("cls");
        menu = MAIN_MENU;
        break;
    default:
        break;
    }
}
/* @brief: For player input x, y
*  @param: Player
*  @return: None
*/
void Player::playerInput(PlayerType type){
    int x;
    int y;
    if(type == PLAYER_1){
        cout << "Player 1 input x: "; cin >> x;
        cout << "Player 1 input y: "; cin >> y;
        myUI.tickBoard(x, y, type);
        Beep(500, 500);
    }
    else{
        cout << "Player 2 input x: "; cin >> x;
        cout << "Player 2 input y: "; cin >> y;
        myUI.tickBoard(x, y, type);
        Beep(700, 500);
    }

}
/* @brief: Player sequence
*  @param: None
*  @return: None
*/
void Player::playerTick(){
    if(myUI.getGameDataSize() == 0){
        playerInput(PLAYER_1);
    }
    else if( (myUI.getGameDataSize() - 1) % 2 == 0 ){
        playerInput(PLAYER_2);
    }
    else{
        playerInput(PLAYER_1);
    }
    playerRefresh();
}
/* @brief: Play and check who is winner and log file
*  @param: None
*  @return: None
*/
void Player::playerCheckWin(){
    playerTick();
    vector<Point_t> temp;
    if(gameRule.checkWin(myUI.getValueX(myUI.getGameDataSize() - 1),
                           myUI.getValueY(myUI.getGameDataSize() - 1),
                           myUI.caroBoard))
    {
        matchID++;
        int index = myUI.getGameDataSize() - 1;
        if(index % 2 == 0){
            cout << getPlayerName(PLAYER_1) << " WIN" << endl;
            increase(PLAYER_1_WIN);
            increase(PLAYER_2_LOSE);
        }
        else{
            cout << getPlayerName(PLAYER_2) << " WIN" << endl;
            increase(PLAYER_2_WIN);
            increase(PLAYER_1_LOSE);
        }
        cout << "Enter (Y/N) to play again!" << endl;
        myUI.copyData(temp);
        myFile.writeMatchInfor(getPlayerName(PLAYER_1),
                               getPlayerName(PLAYER_2),
                               matchID, temp);
        myFile.writePlayerInfor(getPlayerName(PLAYER_1),
                                getPlayerName(PLAYER_2),
                                playerFirstWin,
                                playerFirstLose,
                                playerSecondWin,
                                playerSecondLose,
                                playerDraw);
        char temp;
        cin >> temp;
        if(temp == 'Y' || temp == 'y'){
            myUI.clearBoard();
            myUI.clearData();
            playerRefresh();
            menu = 1;
        }
        else if(temp == 'N' || temp == 'n'){
            resetResult();
            myUI.clearData();
            system("cls");
            menu = 0; // Come back menu
        }
    }
    if(gameRule.checkGameOver(myUI.getGameDataSize())){
        increase(PLAYER_1_AND_2_DRAW);
        myFile.writePlayerInfor(getPlayerName(PLAYER_1),
                                getPlayerName(PLAYER_2),
                                playerFirstWin,
                                playerFirstLose,
                                playerSecondWin,
                                playerSecondLose,
                                playerDraw);
        myFile.writeMatchInfor(getPlayerName(PLAYER_1),
                               getPlayerName(PLAYER_2),
                               matchID, temp);
        cout << "No WINNER" << endl;
    }
}
/* @brief: PLaying
*  @param: None
*  @return: None
*/
void Player::playerPlaying(){
    switch(menu){
    case MAIN_MENU:
        playerInit();
        break;
    case PLAY_OFF:
        playerCheckWin();
        break;
    default:
        break;
    }
}
/* @brief: Set player's name
*  @param: Name
*  @return: None
*/
void Player::setNamePlayer(PlayerType type){
    if(type == PLAYER_1){
        myUI.inputNamePlayer(namePL1, type);
    }
    else{
        myUI.inputNamePlayer(namePL2, type);
    }
}
/* @brief: Increase match index
*  @param: Result
*  @return: None
*/
void Player::increase(MATCH_RESULT result){
    if(result == PLAYER_1_WIN) playerFirstWin++;
    else if(result == PLAYER_2_WIN) playerSecondWin++;
    else if(result == PLAYER_1_LOSE) playerFirstLose++;
    else if(result == PLAYER_2_LOSE) playerSecondLose++;
    else playerDraw++;
}
/* @brief: Reset all result
*  @param: None
*  @return: None
*/
void Player::resetResult(){
    this->playerFirstWin = 0;
    this->playerFirstLose = 0;
    this->playerDraw = 0;
    this->playerSecondWin = 0;
    this->playerSecondLose= 0;
}
/* @brief: Delete two member arr[0] and arr[1]
*  @param: arr[], total member
*  @return: None
*/
void Player::clearTwoMember(int *arr, int &number){
    for(uint8_t i = 0; i < number - 1; i++){
        arr[i] = arr[i + 1];
    }
    number = number - 1;

    for(uint8_t i = 0; i < number - 1; i++){
        arr[i] = arr[i + 1];
    }
    number = number - 1;
}
/* @brief: Replay a match
*  @param: None
*  @return: None
*/
void Player::playerReplay(){
    int temp[100];
    int numberStep; // Lưu số phần tử đã có trong mảng temp => (numberStep/2) -1 = số nước đi
    myFile.searchMatchInfor(temp, numberStep);
    myUI.setColor(YELLOW);
    myUI.clearBoard();
    for(uint8_t i = 0; i < ((numberStep - 1) / 2);){
        myUI.tickBoardNoCheck(temp[0], temp[1], PLAYER_1);
        playerRefresh();
        Sleep(500);
        // Tới lượt đánh cuối cùng
        if(numberStep == 3){
            numberStep = 0;
        }
        else{
            clearTwoMember(temp, numberStep);
            myUI.tickBoardNoCheck(temp[0], temp[1], PLAYER_2);
            playerRefresh();
            Sleep(500);
            clearTwoMember(temp, numberStep);
        }
    }
    cout << "Press any key to comback Menu!";
    _getch();
}
/* @brief: Reload UI
*  @param: None
*  @return: None
*/
void Player::playerRefresh(){
    system("cls");
    myUI.reloadBoard();
}
/* @brief: Get player's
*  @param: Player 1 or 2
*  @return: None
*/
string Player::getPlayerName(PlayerType type){
    if(type == PLAYER_1){
        return namePL1;
    }
    else{
        return namePL2;
    }
}
