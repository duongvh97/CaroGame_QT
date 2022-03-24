#include "file.h"
#include <conio.h>
#include <string.h>
#include <math.h>

File::File(){
    userDataFile.clear();
}
File::~File(){
}
/* @brief: Log file
*  @param: Name, win, lose and draw
*  @return: None
*/
void File::writePlayerInfor(const string name1, const string name2,
                            const int win1, const int lose1,
                            const int win2, const int lose2,
                            const int draw){
    fstream myFile;
    myFile.open("F://FPT_TRAINING//PROJECT//GAME_CARO//gameData.txt", ios::app);
    if(myFile.fail())
    {
        cout << "Open file error" << endl;
        system("pause");
    }
    else{
        myFile << name1 << "," << win1 << "," << lose1 << "," << draw << endl;
        myFile << name2 << "," << win2 << "," << lose2 << "," << draw << endl;
        myFile.close();
    }
}
/* @brief: Store match infor
*  @param: Name player
*  @return: None
*/
void File:: writeMatchInfor(const string name1, const string name2, const int index, const vector<Point_t> &x){
    fstream myFile;
    myFile.open("F://FPT_TRAINING//PROJECT//GAME_CARO//matchData.txt", ios::app);
    if(myFile.fail()){
        cout << "Open file error" << endl;
        system("pause");
    }
    else{
        myFile << index << "," << name1 << "," << name2;
        for(uint8_t i = 0 ; i < x.size(); i++){
             myFile << "," << x[i].x << "," << x[i].y;
        }
        myFile << endl;
        myFile.close();
    }
}
/* @brief: Load data file
*  @param: None
*  @return: None
*/
void File::loadUserData(){
    string temp;
    fstream myFile;
    myFile.open("F://FPT_TRAINING//PROJECT//GAME_CARO//gameData.txt", ios::in);
    if(myFile.fail()){
        cout << "Open file error" << endl;
        system("pause");
    }
    else{
        while(!myFile.eof()){
            getline(myFile, temp);
            userDataFile.push_back(temp);
        }
    }
}
/* @brief: Get player infor
*  @param: None
*  @return: None
*/
void File::searchPlayerInfor(){
    string temp;
    int counter = 0;
    bool isFound = false;
    userDataFile.clear();
    loadUserData(); // Load data in .txt file to buffer
    system("cls");
    cout << "What is the Player's name: "; cin >> temp;
    for(uint8_t i = 0 ; i < userDataFile.size() - 1; i++){
        if(strstr(userDataFile[i].c_str(), temp.c_str()) ){
            isFound = true;
            if(i == 0){
                 cout << "\nINFOR: " << userDataFile[i] << endl; // check
                 showSameResult(userDataFile[counter]);
            }
            else counter = i;
        }
    }
    if(counter != 0){
        cout << "\nINFOR: " << userDataFile[counter] << endl;
        showSameResult(userDataFile[counter]);
    }
    else{
        if(!isFound)
        cout << "Not found player!" << endl;
    }
    cout << "\nPress any key to comeback Menu!" << endl;
    _getch();
}
/* @brief: Load match data from file
*  @param: None
*  @return: None
*/
void File::loadMatchData(){
    string temp;
    fstream myFile;
    myFile.open("F://FPT_TRAINING//PROJECT//GAME_CARO//matchData.txt", ios::in);
    if(myFile.fail()){
        cout << "Open file error" << endl;
        system("pause");
    }
    else{
        while(!myFile.eof()){
            getline(myFile, temp);
            matchDataFile.push_back(temp);
        }
        myFile.close();
    }
}
/* @brief: Search match
*  @param: None
*  @return: None
*/
void File::searchMatchInfor(int *gameData, int &numberStep){
    showListMatch();
    int matchID;
    int step[100];
    cout << "\nSelect match do you want to replay: ";  cin >> matchID;
        char array[matchDataFile[matchID - 1].size()];
        strncpy(array, matchDataFile[matchID - 1].c_str(), matchDataFile[matchID - 1].size());
        char *token;
        token = strtok(array, ","); // Loai bo id
        token = strtok(NULL, ",");  // Loai bo ten nguoi choi thu nhat
        token = strtok(NULL, ",");  // Loai bo ten nguoi choi thu hai
        int j = 0;
        while(token != NULL){
            token = strtok(NULL, ",");
            step[j++] = atoi(token);
        }
        numberStep = j;
        for(uint8_t i = 0; i < j - 1; i++){
            gameData[i] = step[i];
        }
}
/* @brief: Show list match from matchDataFile
*  @param: None
*  @return: None
*/
void File::showListMatch(){
    string temp;
    char *subString[3] = {NULL, NULL, NULL};
    matchDataFile.clear();
    loadMatchData(); // Load data in .txt file to buffer
    system("cls");

    for(uint8_t i = 0 ; i < matchDataFile.size() - 1; i++){
        char array[matchDataFile[i].size() + 1];
        strncpy(array, matchDataFile[i].c_str(), matchDataFile[i].size());
        char *token = strtok(array, ",");
        subString[0] = token;
        uint8_t j = 1;
        while(token != NULL){
            subString[j++] = strtok(NULL, ",");
            if(j == 3) break;
        }
        cout << subString[0] << ". ";
        cout << subString[1] << " vs ";
        cout << subString[2] << endl;
    }
}
/* @brief: Get win, lose, draw
*  @param: None
*  @return: None
*/
Result_t File::getResult(const string name){
    char arr[100];
    Result_t result;

    for(uint8_t i = 0; i < userDataFile.size() - 1; i++){
        if(strstr(userDataFile[i].c_str(), name.c_str())){
            strncpy(arr, userDataFile[i].c_str(), userDataFile[i].size());
            result.index = i;
        }
    }
    char *token = strtok(arr, ",");
    token = strtok(NULL, ",");
    result.win = atoi(token);
    token = strtok(NULL, ",");
    result.lose = atoi(token);
    token = strtok(NULL, ",");
    result.draw = atoi(token);

    return result;
}
/* @brief: Show same result
*  @param: None
*  @return: None
*/
void File::showSameResult(const string name){
    Result_t arr[50] = {};
    Result_t result = getResult(name); // vi tri thu 0
    char temp[100] = {};
    char *token;
    for(uint8_t i = 0; i < userDataFile.size(); i++){
        if(i != result.index){
            strncpy(temp, userDataFile[i].c_str(), userDataFile[i].size());
            token = strtok(temp, ",");

            token = strtok(NULL, ",");
            arr[i].win = atoi(token);
            token = strtok(NULL, ",");
            arr[i].lose = atoi(token);
            token = strtok(NULL, ",");
            arr[i].draw = atoi(token);
        }
    }
    int minWin = abs(result.win - arr[0].win);
    int minLose = abs(result.lose - arr[0].lose);
    int minDraw = abs(result.draw - arr[0].draw);

    int _min;
    int indexMinWin = 0;
    int indexMinLose = 0;
    int indexMinDraw= 0;

    for(uint8_t i = 1; i < userDataFile.size(); i++){
        _min = abs(result.win - arr[i].win);
        if(minWin > _min){
            minWin = _min;
            indexMinWin = i;
        }
    }

    for(uint8_t i = 1; i < userDataFile.size(); i++){
        _min = abs(result.lose - arr[i].lose);
        if(minLose > _min){
            minLose = _min;
            indexMinLose = i;
        }
    }

    for(uint8_t i = 1; i < userDataFile.size(); i++){
        _min = abs(result.draw - arr[i].draw);
        if(minDraw > _min){
            minDraw = _min;
            indexMinDraw = i;
        }
    }
    cout << "Player win nearest: " << userDataFile[indexMinWin] << endl;
    cout << "Player lose nearest: " << userDataFile[indexMinLose] << endl;
    cout << "Player draw nearest: " << userDataFile[indexMinDraw] << endl;
}
