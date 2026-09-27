#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Movie {
private:
    string title;
    int yearReleased;
    string screenWriter;
public:
    Movie() : title(""), yearReleased(0), screenWriter("") {}
    Movie(string t, int y, string s) {
        setTitle(t);
        setYearReleased(y);
        setScreenWriter(s);
    }
    void setTitle(string title) { this->title = title; }
    void setYearReleased(int yearReleased) { this->yearReleased = yearReleased; }
    void setScreenWriter(string screenWriter) { this->screenWriter = screenWriter; }
    
    string getTitle() const { return this->title; }
    int getYearReleased() const { return this->yearReleased; }
    string getScreenWriter() const { return this->screenWriter; }
};

int main() {
    return 0;
}