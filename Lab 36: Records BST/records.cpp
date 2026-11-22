#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

int main() {
    IntBinaryTree tree;
    cout << "Inserting nodes" << endl;
    tree.insertNode(5);
    tree.insertNode(3);
    tree.insertNode(9);
    tree.insertNode(12);

    cout << "in order traversal" << endl;
    tree.displayInOrder();
    cout << "pre order traversal" << endl;
    tree.displayPreOrder();
    cout << "post order traversal" << endl;
    tree.displayPostOrder();

    cout << "Search for number 3" << endl;
    if (tree.searchNode(3)) {
        cout << "Found 3" << endl;
    } else {
        cout << "3 not found" << endl;
    }

    cout << "Delete node 9" << endl;
    tree.remove(9);
    cout << "in order traversal" << endl;
    tree.displayInOrder();

    return 0;
}