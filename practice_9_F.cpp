#include <iostream>
#include <limits>
#include <string>

using namespace std;

string currentNote;

void printWelcome()
{
    cout << "Welcome to CLI Notes!\n";
}

void displayMenu()
{
    cout << "\n1. Create Note\n";
    cout << "2. View Note\n";
    cout << "3. Search Note\n";
    cout << "4. Exit\n";
}

void createNote()
{
    cout << "Enter note content: ";
    getline(cin, currentNote);
    cout << "Note saved.\n";
}

void viewNote()
{
    if (currentNote.empty()) {
        cout << "No note has been created yet.\n";
        return;
    }

    cout << "Current note: " << currentNote << '\n';
}

void searchNote(string note)
{
    string keyword;
    cout << "Enter search keyword: ";
    getline(cin, keyword);

    if (note.find(keyword) != string::npos) {
        cout << "Keyword found.\n";
    } else {
        cout << "Keyword not found.\n";
    }
}

int main()
{
    printWelcome();

    int choice = 0;
    while (choice != 4) {
        displayMenu();
        cout << "Choose an option: ";

        if (!(cin >> choice)) {
            cout << "Please enter a number from 1 to 4.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            createNote();
            break;
        case 2:
            viewNote();
            break;
        case 3:
            searchNote(currentNote);
            break;
        case 4:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid option. Please choose 1 to 4.\n";
        }
    }

    return 0;
}
