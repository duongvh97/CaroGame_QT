#include "file.h"
#include <conio.h>
#include <string.h>

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
    int i = 0;
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
            i++;
        }
        myFile.close();
    }
}
/* @brief: Get player infor
*  @param: None
*  @return: None
*/
void File::searchPlayerInfor(){
    string temp;
    int counter = 0;

    loadUserData(); // Load data in .txt file to buffer
    system("cls");
    cout << "What is the Player's name: "; cin >> temp;
    for(uint8_t i = 0 ; i < userDataFile.size() - 1; i++){
        if(strstr(userDataFile[i].c_str(), temp.c_str()) ){
            if(i == 0){
                 cout << "INFOR: " << userDataFile[i] << endl; // check
            }
            else counter = i;
        }
    }
    if(counter != 0){
        cout << "INFOR: " << userDataFile[counter] << endl;
    }
    else{
        cout << "Not found player!" << endl;
    }
    cout << "Press any key to comeback Menu!" << endl;
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
