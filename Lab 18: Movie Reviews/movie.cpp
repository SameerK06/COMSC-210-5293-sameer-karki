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

    Reviews(const double& r, const string& c, Reviews* n = nullptr) : rating(r), comment(c), next(n) {}
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
        Reviews* newReview = new Reviews(rating, comment);
        head = new Reviews(rating, comment);
    }

};

int main() {
    return 0;
}