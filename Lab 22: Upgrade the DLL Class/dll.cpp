#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(int value) {
        Node* newNode = new Node(value);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_after(int value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
        temp->next = newNode;
    }

    void delete_val(int value) {
        if (!head) return; // Empty list

        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; // Value not found

        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Deleting the head
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; // Deleting the tail
        }

        delete temp;
    }

    void delete_pos(int position) {
        if (position < 0) {
            cout << "Position must be greater than or equal to 0." << endl;
            return;
        }
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        if (position == 0) {
            pop_front();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position && temp; i++) {
            temp = temp->next;
        }
        if(!temp) {
            cout << "Position exceeds list size." << endl;
            return;
        }
        if (temp->prev) {
            temp->prev->next = temp->next;
        }
        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;
        }
        delete temp;
    }

    void pop_front() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    void pop_back() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->next;
        if (tail) {
            tail->prev = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};

// Driver program
int main() {
    srand(time(0));
    DoublyLinkedList list;
    int size = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;
    
    for (int i = 0; i < size; ++i)
        list.push_back(i*10);
    cout << "Initial list: " << endl;
    cout << "List forward: ";
    list.print();
    cout << "List backward: ";
    list.print_reverse();

    cout << "pop_front() testing" << endl;
    list.pop_front();
    cout << "After pop_front(): " << endl;
    list.print();

    cout << "pop_back() testing" << endl;
    list.pop_back();
    cout << "After pop_back(): " << endl;
    list.print();

    cout << "delete_val() testing" << endl;
    list.delete_val(20);
    cout << "After delete_val(20)" << endl;
    list.print();

    cout << "Adding more elements: " << endl;
    for (int i = 0; i < 10; i++) {
        list.push_back(rand() % (MAX_NR-MIN_NR+1) + MIN_NR);
    }
    cout << "Current list: " << endl;
    list.print();
    cout << "Deleting certain positions: " << endl;
    list.delete_pos(0);
    list.delete_pos(2);
    list.delete_pos(2);
    list.delete_pos(10);

    cout << "Final list: " << endl;
    list.print();
    cout << "Reversing final list: " << endl;
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}
