#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Movie {
private:
    string screenWriter;
    int yearReleased;
    string title;
public:
    Movie() : screenWriter(""), yearReleased(0), title("") {}
    Movie(string s, int y, string t) {
        setScreenWriter(s);
        setYearReleased(y);
        setTitle(t);
    }
    void setScreenWriter(string screenWriter) { this->screenWriter = screenWriter; }
    void setYearReleased(int yearReleased) { this->yearReleased = yearReleased; }
    void setTitle(string title) { this->title = title; }
    
    string getScreenWriter() const { return this->screenWriter; }
    int getYearReleased() const { return this->yearReleased; }
    string getTitle() const { return this->title; }

    void print() const {
        cout << "Movie: " << getTitle() << endl;
        cout << "   Year Released: " << getYearReleased() << endl;
        cout << "   Screenwriter: " << getScreenWriter() << endl;
    }
};

int main() {
    vector<Movie> movieList;
    string inputFile = "movielist.txt";
    ifstream inFile(inputFile);
    if (!inFile) {
        cout << "Error: Could not open " << inputFile << endl;
        return 1;
    }

    return 0;
}