#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Load items from input file and count their frequencies
void GroceryTracker::loadItemsFromFile(const string& filename) {
    ifstream inFile(filename);
    string item;

    if (!inFile) {
        cerr << "Error: Unable to open input file: " << filename << endl;
        return;
    }

    while (inFile >> item) {
        itemFrequencies[item]++;
    }

    inFile.close();
}

// Get frequency of a specific item
int GroceryTracker::getItemFrequency(const string& itemName) const {
    auto it = itemFrequencies.find(itemName);
    if (it != itemFrequencies.end()) {
        return it->second;
    }
    return 0;
}

// Print all items and their frequencies
void GroceryTracker::printAllFrequencies() const {
    cout << "\nItem Frequency List:\n";
    for (const auto& pair : itemFrequencies) {
        cout << setw(12) << left << pair.first << " " << pair.second << endl;
    }
}

// Print a histogram of all items
void GroceryTracker::printHistogram() const {
    cout << "\nItem Frequency Histogram:\n";
    for (const auto& pair : itemFrequencies) {
        cout << setw(12) << left << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

// Save frequencies to backup file
void GroceryTracker::saveFrequenciesToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Unable to open output file: " << filename << endl;
        return;
    }

    for (const auto& pair : itemFrequencies) {
        outFile << pair.first << " " << pair.second << endl;
    }

    outFile.close();
}
