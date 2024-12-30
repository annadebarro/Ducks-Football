#ifndef __PLAYER__
#define __PLAYER__
//Libraries
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cctype>

using namespace std;

const int MAX = 101;
const int ROSTER_MAX = 200;
const int NUMBER_MAX = 99;

//Player Info Struct
class Player {
    private:
    int number;
    char * first;
    char * last;
    char * position;
    char * grade;
    char * city;
    char * state;

    public:
    Player();
    Player(const Player &);
    Player & operator=(const Player &);
    ~Player();

    //Getters
    int getNumber();
    const char * getFirst() const;
    const char * getLast() const;
    const char * getPosition() const;
    const char * getGrade() const;
    const char * getCity() const;
    const char * getState() const;

    //Setters
    void setNumber(int);
    void setFirst(const char *);
    void setLast(const char *);
    void setPosition(const char *);
    void setGrade(const char *);
    void setCity(const char *);
    void setState(const char *);

    // Operator functions
    friend ostream & operator<<(ostream &, Player &);
    Player operator+(Player & otherPlayer); //member version
    Player & operator++(); //pre-increment
    //Player operator++(int unused); //post-increment. Signature is different
};

#endif
