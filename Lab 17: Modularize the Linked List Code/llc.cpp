#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;

    int getLength() {
        int count = 0;
        const Node *current = this;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

/* 
* Used passing by reference due to its ability to modify the original pointer. This is less error-prone since
* it always guarantees the calling function will always have access to the updated pointer without needing
* programmer to reassign it. 
*/

void addNodeFront(Node *&head, float val);
void addNodeTail(Node *&head, float val);
void deleteNode(Node *&head, int position);
void insertNodeAfter(Node *&head, int position, float val);
void deleteList(Node *&head);
void output(Node *);

// Game Loop functions
void displayMenu(Node *&head);
int getValidInt(int min, int max);
float getValidFloat();

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) {
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else {
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    Node *current = head;
    Node *prev = nullptr;  // start prev as nullptr to detect head deletion

    for (int i = 0; i < (entry - 1); i++) {
        prev = current;
        current = current->next;
    }

    // at this point, delete current and reroute pointers
    if (current) {
        if (prev == nullptr) {
            // deleting the head node
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        current = nullptr;
    }
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = nullptr;  // reset prev to nullptr for same reason

    for (int i = 0; i < entry; i++) {
        prev = current;
        current = current->next;
    }

    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;

    if (prev == nullptr) {
        // inserting before the head
        head = newnode;
    } else {
        prev->next = newnode;
    }
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);

    return 0;
}

void addNodeFront(Node *&head, float val) {
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = head;
    head = newNode;
}

void addNodeTail(Node *&head, float val) {
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = nullptr;
    if (!head) {
        head = newNode;
        return;
    }
    Node *current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteNode(Node *&head, int position) {
    if(!head || position <= 0) {
        cout << "Empty List or Invalid Position.\n";
        return;
    } else if (position == 1) {
        Node *temp = head;
        head = head->next;
        delete temp;
    } else {
        Node *current = head;
        Node *prev = nullptr;
        for (int i = 1; i < position && current != nullptr; i++) {
            prev = current;
            current = current->next;
            if (!current) {
                cout << "Position out of bounds.\n";
                return;
            }
        }
        prev->next = current->next;
        delete current;
    }
    cout << "Node at position " << position << " deleted.\n";
}

void insertNode(Node *&head, int position, float val) {
    if (position < 0) {
        cout << "Invalid position.\n";
    } else if (position == 1) {
        addNodeFront(head, val);
    } else {
        Node *current = head;
        for (int i = 1; i < position && current != nullptr; i++) {
            current = current->next;
        }
        if (!current) {
            cout << "Position out of bounds. Appending to the end instead.\n";
            addNodeTail(head, val);
            return;
        }
        Node *newNode = new Node;
        newNode->value = val;
        newNode->next = current->next;
        current->next = newNode;
    }
    cout << "Node inserted at position " << position << ".\n";
}

void deleteList(Node *&head) {
    Node *current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    cout << "Entire List Deleted.\n";
}

void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void displayMenu(Node *&head) {
    cout << "\n=== Linked List Menu ===\n"
    << "1. Add Node at Front\n"
    << "2. Add Node at Tail\n"
    << "3. Delete Node at Position\n"
    << "4. Insert Node at Position\n"
    << "5. Delete the Whole List\n"
    << "6. Exit\n";
    cout << "Enter your choice: ";
    int choice = getValidInt(1, 6);
    switch (choice) {
        case 1:
            cout << "Enter the value to add at the front: ";
            float val = getValidFloat();
            addNodeFront(head, val);
            break;
        case 2:
            cout << "Enter the value to add at the end: ";
            float val = getValidFloat();
            addNodeTail(head, val);
            break;
        case 3:
            if (!head) {
                cout << "List is empty, nothing to delete.\n";
                break;
            }
            output(head);
            cout << "Enter the node number to delete: ";
            int pos = getValidInt(1, head->getLength());
            deleteNode(head, pos);
            break;
        case 4:
            output(head);
            cout << "Enter the position to insert the node: ";
            int pos = getValidInt(1, head->getLength());
            cout << "Enter the value to insert: ";
            float val = getValidFloat();
            insertNode(head, pos, val);
            break;
        case 5:
            deleteList(head);
            break;
        case 6:
            output(head);
            break;
        
        
    }
}