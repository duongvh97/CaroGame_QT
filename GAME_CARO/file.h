#ifndef FILE_H
#define FILE_H

#include "config.h"
#include "game_UI.h"
#include <fstream>

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
};

#endif // FILE_H
