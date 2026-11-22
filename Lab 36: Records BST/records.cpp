#include <iostream>
#include <string>
#include <fstream>
#include "StringBinaryTree.h"
using namespace std;

void displayMenu();

int main() {
    StringBinaryTree tree;
    ifstream inputFile("codes.txt");
    if (!inputFile) {
        cout << "Error opening file." << endl;
        return 1;
    }
    string code;
    int count = 0;
    while (inputFile >> code) {
        tree.insertNode(code);
        count++;
    }
    inputFile.close();
    cout << "Inserted " << count << " records into the BST" << endl;

    int choice;
    string target;
    
    do {
        displayMenu();
        while (!(cin >> choice)) {
            cout << "-- Invalid input. Please enter a number between 1 and 6: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
            case 1:
                cout << "-- Enter code to add: ";
                getline(cin, target);
                if (tree.searchNode(target)) {
                    cout << "-- Code already exists in the BST" << endl;
                } else {
                    tree.insertNode(target);
                    cout << "-- Code \"" << target << "\" added to the BST" << endl;
                }
                break;
            case 2:
                cout << "-- Enter code to delete: ";
                getline(cin, target);
                if (tree.searchNode(target)) {
                    tree.remove(target);
                    cout << "-- Code \"" << target << "\" deleted from the BST" << endl;
                } else {
                    cout << "-- Code not found in the BST" << endl;
                }
                break;
            case 3:
                cout << "-- Enter code to search: ";
                getline(cin, target);
                if (tree.searchNode(target)) {
                    cout << "-- Code \"" << target << "\" found in the BST" << endl;
                } else {
                    cout << "-- Code not found in the BST" << endl;
                }
                break;
            case 4:
                cout << "-- Enter code to change: ";
                getline(cin, target);
                if (tree.searchNode(target)) {
                    cout << "-- Enter new code: ";
                    string newCode;
                    getline(cin, newCode);
                    if (tree.searchNode(newCode)) {
                        cout << "-- New code already exists in the BST" << endl;
                    } else {
                        tree.remove(target);
                        tree.insertNode(newCode);
                        cout << "-- Code \"" << target << "\" changed to \"" << newCode << "\" in the BST" << endl;
                    }
                } else {
                    cout << "-- Code not found in the BST" << endl;
                }
                break;
            case 5:
                cout << "-- How would you like to display the records? --" << endl;
                cout << "1. In Order" << endl;
                cout << "2. Pre Order" << endl;
                cout << "3. Post Order" << endl;
                cout << "Select an option: ";
                int displayChoice;
                while (!(cin >> displayChoice) || (displayChoice < 1 || displayChoice > 3)) {
                    cout << "-- Invalid input. Please enter a number between 1 and 3: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (displayChoice == 1) {
                    cout << "-- In Order Traversal" << endl;
                    tree.displayInOrder();
                } else if (displayChoice == 2) {
                    cout << "-- Pre Order Traversal" << endl;
                    tree.displayPreOrder();
                } else {
                    cout << "-- Post Order Traversal" << endl;
                    tree.displayPostOrder();
                }
                break;
            case 6:
                cout << "-- Exiting program" << endl;
                break;
            default:
                cout << "-- Invalid choice. Please select a number between 1 and 6" << endl;
        }
    } while (choice != 6);
    return 0;
}

void testCodeDriver() {
    StringBinaryTree tree;
    cout << "-- Inserting nodes" << endl;
    tree.insertNode("Apples");
    tree.insertNode("Bananas");
    tree.insertNode("Balloons");
    tree.insertNode("Cherries");
    tree.insertNode("Dates");
    tree.insertNode("Elderberries");
    tree.insertNode("Figs");
    tree.insertNode("Grapes");
    tree.insertNode("Guavas");
    cout << "-- in order traversal" << endl;
    tree.displayInOrder();
    cout << "-- pre order traversal" << endl;
    tree.displayPreOrder();
    cout << "-- post order traversal" << endl;
    tree.displayPostOrder();
    cout << "-- Search for Figs" << endl;
    if (tree.searchNode("Figs")) {
        cout << "--* Found Figs" << endl;
    } else {
        cout << "--* Figs not found" << endl;
    }
    cout << "-- Delete node Dates" << endl;
    tree.remove("Dates");
    cout << "-- in order traversal" << endl;
    tree.displayInOrder();
    return;
}

void displayMenu() {
    cout << "-- BST Menu --" << endl;
    cout << "1. Insert a node" << endl;
    cout << "2. Delete a node" << endl;
    cout << "3. Search for a node" << endl;
    cout << "4. Change a node" << endl;
    cout << "5. Display all nodes" << endl;
    cout << "6. Exit" << endl;
    cout << "Select an option: ";
}