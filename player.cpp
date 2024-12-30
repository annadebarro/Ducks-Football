#include "player.h"

Player::Player() {
    number = 0;
    first = new char[strlen("none") + 1];
    strcpy(first, "none");
    last = new char[strlen("none") + 1];
    strcpy(last, "none");
    position = new char[strlen("none") + 1];
    strcpy(position, "none");
    grade = new char[strlen("none") + 1];
    strcpy(grade, "none");
    city = new char[strlen("none") + 1];
    strcpy(city, "none");
    state = new char[strlen("none") + 1];
    strcpy(state, "none");
}

// Copy constructor
Player::Player(const Player & other) {
    number = other.number;
    first = new char[strlen(other.first + 1)];
    strcpy(first, other.first);
    last = new char[strlen(other.last + 1)];
    strcpy(last, other.last);
    position = new char[strlen(other.position + 1)];
    strcpy(position, other.position);
    grade = new char[strlen(other.grade + 1)];
    strcpy(grade, other.grade);
    city = new char[strlen(other.city + 1)];
    strcpy(city, other.city);
    state = new char[strlen(other.state + 1)];
    strcpy(state, other.state);
}

Player & Player::operator=(const Player & other) {
    if(&other != this) {
        if(first != nullptr) {
            delete[] first;
        }
        if(last != nullptr) {
            delete[] last;
        }
        if(position != nullptr) {
            delete[] position;
        }
        if(grade != nullptr) {
            delete[] grade;
        }
        if(city != nullptr) {
            delete[] city;
        }
        if(state != nullptr) {
            delete[] state;
        }
        number = other.number;
        first = new char[strlen(other.first + 1)];
        strcpy(first, other.first);
        last = new char[strlen(other.last + 1)];
        strcpy(last, other.last);
        position = new char[strlen(other.position + 1)];
        strcpy(position, other.position);
        grade = new char[strlen(other.grade + 1)];
        strcpy(grade, other.grade);
        city = new char[strlen(other.city + 1)];
        strcpy(city, other.city);
        state = new char[strlen(other.state + 1)];
        strcpy(state, other.state);
    }
    return *this;
}

// Destructor
Player::~Player() {
    if(first != nullptr) {
        delete[] first;
        }
    if(last != nullptr) {
        delete[] last;
    }
    if(position != nullptr) {
        delete[] position;
    }
    if(grade != nullptr) {
        delete[] grade;
    }
    if(city != nullptr) {
        delete[] city;
    }
    if(state != nullptr) {
        delete[] state;
    }    
}

// Getters
int Player::getNumber() {
    return number;
}

const char * Player::getFirst() const {
    return first;
}

const char * Player::getLast() const {
    return last;
}

const char * Player::getPosition() const {
    return position;
}

const char * Player::getGrade() const {
    return grade;
}

const char * Player::getCity() const {
    return city;
}

const char * Player::getState() const {
    return state;
}

// Setters
void Player::setNumber(int numberArg) {
    number = numberArg;
}

void Player::setFirst(const char * firstArg) {
    if(first != nullptr) {
        delete[] first;
    }
    first = new char[strlen(firstArg) + 1];
    strcpy(first, firstArg);
}

void Player::setLast(const char * lastArg) {
    if(last != nullptr) {
        delete[] last;
    }
    last = new char[strlen(lastArg) + 1];
    strcpy(last, lastArg);
}

void Player::setPosition(const char * positionArg) {
    if(position != nullptr) {
        delete[] position;
    }
    position = new char[strlen(positionArg) + 1];
    strcpy(position, positionArg);
}

void Player::setGrade(const char * gradeArg) {
    if(grade != nullptr) {
        delete[] grade;
    }
    grade = new char[strlen(grade) + 1];
    strcpy(grade, gradeArg);
}

void Player::setCity(const char * cityArg) {
    if(city != nullptr) {
        delete[] city;
    }
    city = new char[strlen(cityArg) + 1];
    strcpy(city, cityArg);
}

void Player::setState(const char * stateArg) {
    if(state != nullptr) {
        delete[] state;
    }
    state = new char[strlen(stateArg) + 1];
    strcpy(state, stateArg);
}

// Operator functions

ostream & operator<<(ostream & out, Player & player) {
    cout << player.number << " " << player.first << " " << player.last
    << " " << player.position << " " << player.grade << " " << player.city
    << ", " << player.state << endl;
    return out;
}

Player Player::operator+(Player & otherPlayer) {
    Player localPlayer;
    localPlayer.number = this->number + otherPlayer.number;
    return localPlayer;
}

Player & Player::operator++() {
    number++;
    return *this;
}

/*Player Player::operator++(int unused) {
    Player tempPlayer = *this;
    number++;
    return tempPlayer;
}*/