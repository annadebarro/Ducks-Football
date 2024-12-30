#ifndef __TEAM__
#define __TEAM__

#include "player.h"

class Team {
    Player * players;
    int count;
    int capacity;
    bool ready;
    char fileName[MAX];
    ifstream inFile;
    ofstream outFile;
    bool insert(Player newPlayer);
    void grow();

    public:
    Team();
    ~Team();
    //Team(const Team &) = delete; // Produces a syntax error.
    //Team & operator=(const Team &) = delete;
    int loadPlayers();
    bool addPlayer();
    void printPlayers();
    bool openTheFile();
    int getCount();
    void searchNumber(int num);
    void searchName(const char name[]);
    void searchPosition(const char pos[]);
    void searchGrade(const char grade[]);
    void searchState(const char state[]);
    void removePlayer(const char first[], const char last[]);
    void writePlayers();
    Player & operator[](int); // subscript operator.
    bool allSet();
};

#endif