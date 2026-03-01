#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

int main() {
    string inputFileName = "CS_210_Project_3_Input_File.txt";
    string backupFileName = "frequency.dat";

    ifstream inFile(inputFileName);
    if (!inFile) {
        cerr << "Error: Cannot open input file: " << inputFileName << endl;
        return 1;
    }

    map<string, int> itemFrequency;
    string item;
    while (inFile >> item) {
        itemFrequency[item]++;
    }
    inFile.close();

    ofstream backupFile(backupFileName);
    for (auto const& pair : itemFrequency) {
        backupFile << pair.first << " " << pair.second << endl;
    }
    backupFile.close();

    int choice = 0;
    do {
        cout << "\n=== Corner Grocer Menu ===\n";
        cout << "1. Search for an item frequency\n";
        cout << "2. Print frequency of all items\n";
        cout << "3. Print histogram of items\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number 1-4." << endl;
            continue;
        }

        switch (choice) {
        case 1: {
            string searchItem;
            cout << "Enter item to search: ";
            cin >> searchItem;
            if (itemFrequency.find(searchItem) != itemFrequency.end()) {
                cout << searchItem << " occurs " << itemFrequency[searchItem] << " times.\n";
            }
            else {
                cout << searchItem << " does not appear in the list.\n";
            }
            break;
        }
        case 2:
            cout << "\nItem Frequency List:\n";
            for (auto const& pair : itemFrequency) {
                cout << pair.first << " " << pair.second << endl;
            }
            break;
        case 3:
            cout << "\nItem Histogram:\n";
            for (auto const& pair : itemFrequency) {
                cout << pair.first << " ";
                for (int i = 0; i < pair.second; ++i) cout << "*";
                cout << endl;
            }
            break;
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice! Please enter 1-4." << endl;
        }
    } while (choice != 4);

    return 0;
}

