#ifndef FILE_H
#define FILE_H

#include "config.h"
#include "game_UI.h"
#include <fstream>

typedef struct{
    int win;
    int lose;
    int draw;
    int index;
}Result_t;

class File{
private:
    vector<string> userDataFile;
    vector<string> matchDataFile;
public:
    File();
    ~File();
    void writePlayerInfor(const string name1, const string name2,
                          const int win1, const int lose1,
                          const int win2, const int lose2,
                          const int draw);
    void writeMatchInfor(const string name1, const string name,
                         const int index, const vector<Point_t> &x);
    void loadUserData(void);
    void loadMatchData(void);
    void searchPlayerInfor(void);
    void searchMatchInfor(int *gameData, int &numberStep);
    void showListMatch(void);
    void showSameResult(const string name);
    Result_t getResult(const string name);
};

#endif // FILE_H
