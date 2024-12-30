#include "team.h"

Team::Team() {
    count = 0;
    capacity = 3;
    players = new Player[capacity];
    ready = openTheFile();
    if(ready) {
        loadPlayers();
    }
}

Team::~Team() {
    delete[] players;
}

int Team::getCount() {
    return count;
}

// openTheFile function
// Args: none
// Returns: true if the file opened successfully
bool Team::openTheFile() {
    bool success = false;
    cout << "Welcome to the Oregon Ducks 2024-25 College Football Roster." << endl;
    cout << "Please enter the file name: ";
    cin.getline(fileName, MAX);
    inFile.open(fileName);

    while(!inFile.is_open() && strcmp(fileName, "QUIT") != 0) {
        cout << "The file did not open. Try again or enter QUIT: ";
        cin.getline(fileName, MAX);
        inFile.open(fileName);
    }
    if(inFile.is_open()) {
        success = true;
    }
     return success;
}

// loadPlayers function
// Args: none
// Returns: the number of players loaded from the file
int Team::loadPlayers() {
    Player newPlayer;
    char str[MAX];
    int playerNumber = 0;
    bool success = true;
    
    inFile >> playerNumber;
    newPlayer.setNumber(playerNumber);
    inFile.ignore();
    while(!inFile.eof() && success) {
        inFile.getline(str, MAX, ';');
        newPlayer.setFirst(str);
        inFile.getline(str, MAX, ';');
        newPlayer.setLast(str);
        inFile.getline(str, MAX, ';');
        newPlayer.setPosition(str);
        inFile.getline(str, MAX, ';');
        newPlayer.setGrade(str);
        inFile.getline(str, MAX, ';');
        newPlayer.setCity(str);
        inFile.getline(str, MAX, '\n');
        newPlayer.setState(str);
        success = insert(newPlayer);
        inFile >> playerNumber;
        newPlayer.setNumber(playerNumber);
        inFile.ignore();
    }
    if(!inFile.eof() && !success) {
        cout << "Not all players loaded from the file, out of room." << endl;
    }
    return count;
}

bool Team::addPlayer() {
    bool result = false;
    char str[MAX];
    int playerNumber = 0;

    if(count < ROSTER_MAX) {
        Player newPlayer;
        cout << "Player uniform number: ";
        while(!(cin >> playerNumber) || playerNumber < 0 || playerNumber > NUMBER_MAX) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Please enter a number from 0 - " << NUMBER_MAX << ": ";
        }
        newPlayer.setNumber(playerNumber);
        cin.ignore();
        cout << "Player first name: ";
        cin.getline(str, MAX);
        newPlayer.setFirst(str);
        cout << "Player last name: ";
        cin.getline(str, MAX);
        newPlayer.setLast(str);
        cout << "Player position: ";
        cin.getline(str, MAX);
        newPlayer.setPosition(str);
        cout << "Player grade: ";
        cin.getline(str, MAX);
        newPlayer.setGrade(str);
        cout << "Player hometown: ";
        cin.getline(str, MAX);
        newPlayer.setCity(str);
        cout << "Player state: ";
        cin.getline(str, MAX);
        newPlayer.setState(str);
        result = insert(newPlayer);
    }
    return result;
}

bool Team::insert(Player newPlayer) {
    bool result = true;
    int index = 0;
    // #1, empty array.
    if(count == 0) {
        players[0] = newPlayer;
    }
    // #2, insert at the end.
    else if(players[count - 1].getNumber() < newPlayer.getNumber()) {
        players[count] = newPlayer;
    }
    // #3, insert somewhere in the list.
    // Shift the players already on the roster.
    else {
        while(players[index].getNumber() < newPlayer.getNumber()) {
            index++;
        }
        // Move the players up to the next indices.
        for(int i = count; i > index; i--) {
            players[i] = players[i - 1]; // moved up by one index.
        }
        // Now there is room for the new player at the correct index.
        players[index] = newPlayer;
    }
    count++;
    if(count >= capacity) {
        grow();
    }
    return result;
}

void Team::printPlayers() {
    cout << endl;
    cout << "2024-25 Roster" << endl << endl;
    cout << left << setw(10) << "Number" << setw(35) << "Name" << setw(10) 
    << "Pos." << setw(10) << "Grade" << setw(15) << "From" << endl;
    for(int i = 0; i < 100; i++) {
        cout << "-";
    }
    cout << endl;
    for(int i = 0; i < count; i++) {
        cout << left << setw(10) << players[i].getNumber() << setw(15) << players[i].getFirst() << setw(20) << players[i].getLast()
        << setw(10) << players[i].getPosition() << setw(10) << players[i].getGrade()
        << players[i].getCity() << ", " << players[i].getState() << endl;
    }
    cout << endl;
}

void Team::searchNumber(int num) {
    bool found = false;
    cout << endl;
    cout << left << setw(10) << "Number" << setw(35) << "Name" << setw(10) 
    << "Pos." << setw(10) << "Grade" << setw(15) << "From" << endl;
    for(int j = 0; j < 100; j++) {
        cout << "-";
    }
    cout << endl;
    for(int i = 0; i < count; i++) {
        if(num == players[i].getNumber()) {
            found = true;
            cout << left << setw(10) << players[i].getNumber() << setw(15) << players[i].getFirst() << setw(20) << players[i].getLast()
            << setw(10) << players[i].getPosition() << setw(10) << players[i].getGrade()
            << players[i].getCity() << ", " << players[i].getState() << endl;
        }
    }
    if(!found) {
        cout << endl << num << " was not found." << endl;
    }
    cout << endl;
}

void Team::searchName(const char name[]) {
    bool found = false;
    cout << endl;
    cout << left << setw(10) << "Number" << setw(35) << "Name" << setw(10) 
    << "Pos." << setw(10) << "Grade" << setw(15) << "From" << endl;
    for(int j = 0; j < 100; j++) {
        cout << "-";
    }
    cout << endl;
    for(int i = 0; i < count; i++) {
        if(strcmp(name, players[i].getFirst()) == 0 || strcmp(name, players[i].getLast()) == 0) {
            found = true;
            cout << left << setw(10) << players[i].getNumber() << setw(15) << players[i].getFirst() << setw(20) << players[i].getLast()
            << setw(10) << players[i].getPosition() << setw(10) << players[i].getGrade()
            << players[i].getCity() << ", " << players[i].getState() << endl;
        }
    }
    if(!found) {
        cout << endl << name << " was not found." << endl;
    }
    cout << endl;
}

void Team::searchPosition(const char pos[]) {
    bool found = false;
    cout << left << setw(10) << "Number" << setw(35) << "Name" << setw(10) 
    << "Pos." << setw(10) << "Grade" << setw(15) << "From" << endl;
    for(int j = 0; j < 100; j++) {
        cout << "-";
    }
    cout << endl;
    for(int i = 0; i < count; i++) {
        if(strcmp(pos, players[i].getPosition()) == 0) {
            found = true;
            cout << left << setw(10) << players[i].getNumber() << setw(15) << players[i].getFirst() << setw(20) << players[i].getLast()
            << setw(10) << players[i].getPosition() << setw(10) << players[i].getGrade()
            << players[i].getCity() << ", " << players[i].getState() << endl;
        }
    }
    if(!found) {
        cout << endl << pos << " was not found." << endl;
    }
    cout << endl;
}

void Team::searchGrade(const char grade[]) {
    bool found = false;
    cout << left << setw(10) << "Number" << setw(35) << "Name" << setw(10) 
    << "Pos." << setw(10) << "Grade" << setw(15) << "From" << endl;
    for(int j = 0; j < 100; j++) {
        cout << "-";
    }
    cout << endl;
    for(int i = 0; i < count; i++) {
        if(strcmp(grade, players[i].getGrade()) == 0) {
            found = true;
            cout << left << setw(10) << players[i].getNumber() << setw(15) << players[i].getFirst() << setw(20) << players[i].getLast()
            << setw(10) << players[i].getPosition() << setw(10) << players[i].getGrade()
            << players[i].getCity() << ", " << players[i].getState() << endl;
        }
    }
    if(!found) {
        cout << endl << grade << " was not found." << endl;
    }
    cout << endl;
}

void Team::searchState(const char state[]) {
    bool found = false;
    cout << left << setw(10) << "Number" << setw(35) << "Name" << setw(10) 
    << "Pos." << setw(10) << "Grade" << setw(15) << "From" << endl;
    for(int j = 0; j < 100; j++) {
        cout << "-";
    }
    cout << endl;
    for(int i = 0; i < count; i++) {
        if(strcmp(state, players[i].getState()) == 0) {
            found = true;
            cout << left << setw(10) << players[i].getNumber() << setw(15) << players[i].getFirst() << setw(20) << players[i].getLast()
            << setw(10) << players[i].getPosition() << setw(10) << players[i].getGrade()
            << players[i].getCity() << ", " << players[i].getState() << endl;
        }
    }
    if(!found) {
        cout << endl << state << " was not found." << endl;
    }
    cout << endl;
}

void Team::removePlayer(const char first[], const char last[]) {
    bool found = false;
    int index = 0;
    for(int i = 0; i < count; i++) {
        if(strcmp(first, players[i].getFirst()) == 0 && strcmp(last, players[i].getLast()) == 0) {
            found = true;
            index = i;
            break;
        }
    }
    if(found) {
        for(int j = index; j < count - 1; j++) {
            players[j] = players[j + 1];
        }
        count--;
        cout << first << " " << last << " was successfully removed." << endl;
    }
    else {
        cout << first << " " << last << " was not found." << endl;
    }
    
}

void Team::writePlayers() {
    char fileName[MAX];
    ofstream outFile;
    cout << "What is the name of the file to write to? " << endl;
    cin.getline(fileName, MAX);
    outFile.open(fileName);

    for(int i = 0; i < count; i++) {
        outFile << players[i].getNumber() << ';' << players[i].getFirst() << ';'
        << players[i].getLast() << ';' << players[i].getPosition() << ';' << players[i].getGrade()
        << ';' << players[i].getCity() << ';' << players[i].getState() << '\n';
    }
    outFile.close();
}

Player & Team::operator[](int index) {
    return players[index];
}

void Team::grow() {
    Player * temp;
    capacity += 2;
    temp = new Player[capacity];
    for(int i = 0; i < count; i++) {
        temp[i] = players[i];
    }
    delete[] players;
    players = temp;
}

bool Team::allSet() {
    return ready;
}