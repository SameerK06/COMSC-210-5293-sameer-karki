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
        cout << endl;
    }
};

int main() {
    vector<Movie> movieList;
    string inputFile = "movieList.txt";
    string tempScreenWriter;
    string tempYearReleased;
    string tempTitle;
    ifstream inFile(inputFile);
    if (!inFile) {
        cout << "Error: Could not open " << inputFile << endl;
        return 1;
    }
    while (getline(inFile, tempScreenWriter) && getline(inFile, tempYearReleased) && getline(inFile, tempTitle)) {
        movieList.emplace_back(tempScreenWriter, stoi(tempYearReleased), tempTitle);
    }
    inFile.close();

    for (Movie movie: movieList) {
        movie.print();
    }
    return 0;
}