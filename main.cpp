#include "player.h"
#include "team.h"

int main() {
    char choice = ' ';
    bool result = false;
    bool success = false;
    int num = 0;
    int count = 0; // number of players on roster.
    char str[MAX];
    char first[MAX];
    char last[MAX];

    Team roster;
    result = roster.allSet();
    if(result) {
        count = roster.getCount();
        cout << count << " players were loaded from the file." << endl;

        do {
            cout << endl;
            cout << "What would you like to do?" << endl;
            
            cout << "Search:" << endl;
            cout << "  1. Uniform Number" << endl;
            cout << "  2. Name" << endl;
            cout << "  3. Position" << endl;
            cout << "  4. Grade" << endl;
            cout << "  5. State" << endl;
            cout << "(A)dd Player" << endl;
            cout << "(R)emove" << endl;
            cout << "(P)rint Roster" << endl;
            cout << "(Q)uit" << endl;
            cin >> choice;
            cin.ignore();
            choice = toupper(choice); // convert to uppercase.
            switch(choice) {
                case 'A':
                    success = roster.addPlayer();
                    cout << "The new player was ";
                    if(success) {
                        cout << "successfully added." << endl;
                    }
                    else {
                        cout << "not added, array full." << endl;
                    }
                    break;
                    
                case '1':
                    cout << endl;
                    cout << "Enter search number: ";
                    cin >> num;
                    roster.searchNumber(num);
                    break;
                    case '2':
                        cout << endl;
                        cout << "Enter search name: ";
                        cin.getline(str, MAX);
                        roster.searchName(str);
                        break;
                    case '3':
                        cout << endl;
                        cout << "Abbreviation Guide:" << endl;
                        cout << "DB - Defensive Back" << endl;
                        cout << "DE - Defensive End" << endl;
                        cout << "WR - Wide Receiver" << endl;
                        cout << "ILB - Inside Linebacker" << endl;
                        cout << "TE - Tight End" << endl;
                        cout << "QB - Quarterback" << endl;
                        cout << "RB - Running Back" << endl;
                        cout << "OLB - Outside Linebacker" << endl;
                        cout << "DL - Defensive Lineman" << endl;
                        cout << "OL - Offensive Lineman" << endl;
                        cout << "LS - Long Snapper" << endl;
                        cout << "P - Punter" << endl;
                        cout << "K - Kicker" << endl;
                        cout << "DT - Defensive Tackle" << endl;
                        cout << endl;

                        cout << "Enter search position: ";
                        cin.getline(str, MAX);
                        roster.searchPosition(str);
                        break;
                    case '4':
                        cout << endl;
                        cout << "Abbreviation Guide:" << endl;
                        cout << "R-Fr. - Redshirt Freshman" << endl;
                        cout << "Fr. - Freshman" << endl;
                        cout << "So. - Sophomore" << endl;
                        cout << "Jr. - Junior" << endl;
                        cout << "Sr. - Senior" << endl;
                        cout << endl;

                        cout << "Enter search grade: ";
                        cin.getline(str, MAX);
                        roster.searchGrade(str);
                        break;
                    case '5':
                        cout << endl;
                        cout << "Enter search state: ";
                        cin.getline(str, MAX);
                        roster.searchState(str);
                        break;    
                case 'R':
                    cout << "Enter player first name: ";
                    cin.getline(first, MAX);
                    cout << "Enter player last name: ";
                    cin.getline(last, MAX);
                    roster.removePlayer(first, last);
                    break;
                case 'P':
                    roster.printPlayers();
                    break;
                case 'Q':
                    break;
                default:
                    cout << "Option not recognized." << endl;
            }
        } while(choice != 'Q');
        roster.writePlayers();
    }
    cout << "See you next time!" << endl;
    return 0;
}