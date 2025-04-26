#include <iostream>
#include <string>
#include "GroceryTracker.h"

using namespace std;

int main() {
    GroceryTracker tracker;
    string inputFilename = "CS210_Project_Three_Input_File.txt";
    string outputFilename = "frequency.dat";

    // Load items from input and save to backup file
    tracker.loadItemsFromFile(inputFilename);
    tracker.saveFrequenciesToFile(outputFilename);

    int choice = 0;

    while (choice != 4) {
        cout << "\n======= Corner Grocer Menu =======\n";
        cout << "1. Search for an item's frequency\n";
        cout << "2. Print all item frequencies\n";
        cout << "3. Print histogram of item frequencies\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // clear newline from buffer

        switch (choice) {
        case 1: {
            string item;
            cout << "\nEnter item name: ";
            getline(cin, item);
            int count = tracker.getItemFrequency(item);
            cout << item << " was purchased " << count << " times.\n";
            break;
        }
        case 2:
            tracker.printAllFrequencies();
            break;
        case 3:
            tracker.printHistogram();
            break;
        case 4:
            cout << "\nExiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please enter 1–4.\n";
            break;
        }
    }

    return 0;
}
