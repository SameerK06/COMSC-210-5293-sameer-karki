#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;

    cout << "What is your name? ";
    getline(cin, name);

    cout << "Hello " << name << ", this is the first lab exercise for COMSC-210" << endl;

    return 0;
}
