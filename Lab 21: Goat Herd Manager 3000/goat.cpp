#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20, GOAT_ARRAY_SIZE = 15;

class Goat {
private:
    int age;
    string color;
    string name;
    string names[GOAT_ARRAY_SIZE] = {
        "Senior", "Godlike", "Old", "Mature", "Teen", 
        "Billy", "Nanny", "Gruff", "Snowy", "Shadow", 
        "Kid", "Pippin", "Vincent", "Grover", "Hazel"
    };
    string colors[GOAT_ARRAY_SIZE] = {
        "White", "Black", "Brown", "Spotted", "Ticked",
        "Light Gray", "Dark Gray", "Tan", "Beige", "Olive",
        "Chestnut", "Bay", "Sorrel", "Auburn", "Red"
    };
public:
    Goat() {
        age  = (rand() % 20) + 1;
        name = names[rand() % GOAT_ARRAY_SIZE];
        color = colors[rand() % GOAT_ARRAY_SIZE];
    }
    Goat(string n, string c, int a) {
        name = n;
        color = c;
        age = a;
    }

    string getName() const { return name;}
    string getColor() const { return color; }
    int getAge() const { return age; }
};

class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;
        Node(Goat val, Node* p = nullptr, Node* n = nullptr) {
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

    void push_back(Goat value) {
        Node* newNode = new Node(value);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat value) {
        Node* newNode = new Node(value);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_after(Goat value, int position) {
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

    void delete_node(Goat value) {
        if (!head) return; // Empty list

        Node* temp = head;
        while (temp && temp->data.getName() != value.getName())
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

    void print() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* current = head;
        if (!current) return;
        while (current) {
            cout << current->data.getName() << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) return;
        while (current) {
            cout << current->data.getName() << " ";
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

    for (int i = 0; i < size; ++i) {
        Goat newGoat;
        list.push_back(newGoat);
    }
        
    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}
