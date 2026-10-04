#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>

using namespace std;

struct Reviews {
    double rating;
    string comment;
    Reviews* next;

    Reviews(const double r, const string& c, Reviews* n = nullptr) : rating(r), comment(c), next(n) {}
};

class Movie {
private:
    string title;
    Reviews* head;
    void clearReviews() {
        Reviews* current = head;
        while (current != nullptr) {
            Reviews* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

public:
    Movie(const string& t): title(t), head(nullptr) {}

    ~Movie() {
        clearReviews();
    }

    Movie(const Movie& other) : title(other.title), head(nullptr) {
        if (!other.head) return;
        head = new Reviews(other.head->rating, other.head->comment);
        Reviews* current = head;
        Reviews* otherCurrent = other.head->next;
        while (otherCurrent != nullptr) {
            current->next = new Reviews(otherCurrent->rating, otherCurrent->comment);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }

    Movie& operator=(const Movie& other) {
        if (this == &other) return *this;
        clearReviews();
        if (!other.head) return *this;
        head = new Reviews(other.head->rating, other.head->comment);
        Reviews* current = head;
        Reviews* otherCurrent = other.head->next;
        while (otherCurrent != nullptr) {
            current->next = new Reviews(otherCurrent->rating, otherCurrent->comment);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
        return *this;
    }

    void addReview(const double& rating, const string& comment) {
        head = new Reviews(rating, comment, head);
    }

    void printReviews() const {
        cout << "Movie Title: " << title << endl;
        Reviews* current = head;
        cout.setf(ios::fixed);
        cout.precision(1);
        int count = 1;
        double sum = 0.0;
        while (current) {
            cout << "Review " << count << ": " << current->rating << " - " << current->comment << endl;
            sum += current->rating;
            current = current->next;
            count++;
        }
        if (count > 1) {
            cout << "Average Rating: " << sum / (count - 1) << endl;
        }
        cout.unsetf(ios::fixed);
    }
};


void prepareInputFile(const string& filename);
double generateRandomRatings();


int main() {
    return 0;
}

void prepareInputFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        ofstream outFile(filename);
        outFile << "An epic journey with stunning visuals.\n";
        outFile << "Too long, but the battles are incredible.\n";
        outFile << "The best fantasy film ever made.\n";
        outFile << "A masterpiece of storytelling and acting.\n";
        outFile << "Brando's performance is unforgettable.\n";
        outFile << "Slow start, but worth every minute.\n";
        outFile << "Classic space adventure that still holds up.\n";
        outFile << "Great characters and a legendary score.\n";
        outFile << "Some effects look dated today.\n";
        outFile << "The dinosaurs still look amazing.\n";
        outFile << "Tense, fun, and perfectly paced.\n";
        outFile << "The science is shaky but who cares.\n";
        outFile.close();
        cout << "Input file doesn't exist. Creating a new one with sample reviews." << endl;
    }
}

double generateRandomRatings() {
    srand(time(0));
    double rating = 1.0 + (rand() % 50) / 10.0;
    return rating;
}