#include <iostream>
#include <string>
#include <fstream>
#include "StringBinaryTree.h"
using namespace std;

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
    cout << "-- In Order Traversal --" << endl;
    tree.displayInOrder();
    cout << "-- Pre Order Traversal --" << endl;
    tree.displayPreOrder();
    cout << "-- Post Order Traversal --" << endl;
    tree.displayPostOrder();
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