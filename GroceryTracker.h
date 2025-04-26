#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <string>
#include <map>

class GroceryTracker {
private:
    std::map<std::string, int> itemFrequencies;

public:
    void loadItemsFromFile(const std::string& filename);
    int getItemFrequency(const std::string& itemName) const;
    void printAllFrequencies() const;
    void printHistogram() const;
    void saveFrequenciesToFile(const std::string& filename) const;
};

#endif
