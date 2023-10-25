#include <iostream>
#include <fstream>
#include <map>
using namespace std;

class ItemTracker {
private:
    map<string, int> frequencyMap;

public:
    ItemTracker() {}

    // This function reads the input file and stores the frequency of each item in the map
    void readInputFile(string fileName) {
        ifstream inputFile(fileName);
        string item;
        while (inputFile >> item) {
            frequencyMap[item]++;
        }
        inputFile.close();
    }

    // This function prints the frequency of a specific item
    void printItemFrequency(string item) {
        if (frequencyMap.count(item) > 0) {
            cout << item << " " << frequencyMap[item] << endl;
        }
        else {
            cout << item << " Item not found." << endl;
        }
    }

    // This function prints the frequency of all items in the input file
    void printAllFrequencies() {
        for (auto itr = frequencyMap.begin(); itr != frequencyMap.end(); itr++) {
            cout << itr->first << " " << itr->second << endl;
        }
    }

    // This function prints the frequency of all items in the input file as a histogram
    void printHistogram() {
        for (auto itr = frequencyMap.begin(); itr != frequencyMap.end(); itr++) {
            cout << itr->first << " ";
            for (int i = 0; i < itr->second; i++) {
                cout << "*";
            }
            cout << endl;
        }
    }

    // This function writes the frequency map to a backup file
    void writeFrequencyFile(string fileName) {
        ofstream frequencyFile(fileName);
        for (auto itr = frequencyMap.begin(); itr != frequencyMap.end(); itr++) {
            frequencyFile << itr->first << " " << itr->second << endl;
        }
        frequencyFile.close();
    }
};

int main() {
    ItemTracker tracker;
    tracker.readInputFile("CS210_Project_Three_Input_File.txt");

    int choice;


    //menu for each choice 1-5 
    // added extra menu to include creating a backup file. Just so there is an option to be chosen for backing up
    do {
        cout << "Menu:" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Print frequency of all items" << endl;
        cout << "3. Print histogram of all items" << endl;
        cout << "4. Create a backup file." << endl;
        cout << "5. Exit program" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        // created switches for the menu choice that the user inputs
        switch (choice) {
        case 1:
        {
            string item;
            cout << "Enter item to search for: ";
            cin >> item;
            cout << endl;
            tracker.printItemFrequency(item);
            cout << endl;
            break;
        }
        case 2:
        {
            cout << endl;
            tracker.printAllFrequencies();
            cout << endl;
            break;
        }
        case 3:
        {
            cout << endl;
            tracker.printHistogram();
            cout << endl; 

            break;
        }
        case 4:
        {
            cout << endl;
            tracker.writeFrequencyFile("frequency.dat");
            cout << "frequency.dat is created" << endl;
            cout << endl;
        break; 
        }

        case 5:
        {
            cout << endl;
            cout << "Exiting program..." << endl;
            break;
        }

        default:
        {
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        break; 
        }
        }
    } while (choice != 5);

    return 0;
}
