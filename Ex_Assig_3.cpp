#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
    char* title;
    char* author;
    int pageCount;
    bool isHardcover;
    float* chapterPages;
    int numChapters;

public:
    // Default Constructor
    Book() {
        title = new char[1];
        title[0] = '\0';
        author = new char[1];
        author[0] = '\0';
        pageCount = 0;
        isHardcover = false;
        numChapters = 0;
        chapterPages = NULL;
    }

    // Parameterized Constructor
    Book(const char* t, const char* a, int pages, bool hardcover, int chapters) {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
        author = new char[strlen(a) + 1];
        strcpy(author, a);
        pageCount = pages;
        isHardcover = hardcover;
        numChapters = chapters;
        chapterPages = new float[numChapters];
        
        // Distribute pages uniformly among chapters
        float avgPages = static_cast<float>(pages) / chapters;
        for (int i = 0; i < numChapters; i++) {
            chapterPages[i] = avgPages;
        }
    }

    // Copy Constructor (Deep Copy)
    Book(const Book& other) {
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);
        author = new char[strlen(other.author) + 1];
        strcpy(author, other.author);
        pageCount = other.pageCount;
        isHardcover = other.isHardcover;
        numChapters = other.numChapters;
        chapterPages = new float[numChapters];
        for (int i = 0; i < numChapters; i++) {
            chapterPages[i] = other.chapterPages[i];
        }
    }

    // Destructor to free allocated memory
    ~Book() {
        delete[] title;
        delete[] author;
        delete[] chapterPages;
    }

    // Modify chapter page counts
    void modifyChapterPages(int chapterIndex, float newPageCount) {
        if (chapterIndex >= 0 && chapterIndex < numChapters) {
            chapterPages[chapterIndex] = newPageCount;
        } else {
            cout << "Invalid chapter index!" << endl;
        }
    }

    // Display book details
    void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Page Count: " << pageCount << endl;
        cout << "Format: " << (isHardcover ? "Hardcover" : "Paperback") << endl;
        cout << "Number of Chapters: " << numChapters << endl;
        cout << "Chapter Pages: ";
        for (int i = 0; i < numChapters; i++) {
            cout << chapterPages[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Default constructor test
    cout << "Testing Default Constructor:" << endl;
    Book book1;
    book1.display();
    cout << endl;
    
    // Parameterized constructor test
    cout << "Testing Parameterized Constructor:" << endl;
    Book book2("C++ Primer", "Lippman", 500, true, 10);
    book2.display();
    cout << endl;
    
    // Copy constructor test
    cout << "Testing Copy Constructor:" << endl;
    Book book3 = book2;
    book3.display();
    cout << endl;
    
    // Modify a chapter and show deep copy difference
    cout << "Modifying a chapter in book3:" << endl;
    book3.modifyChapterPages(2, 75);
    cout << "After modification - book3:" << endl;
    book3.display();
    cout << "Original book2 remains unchanged:" << endl;
    book2.display();

    return 0;
}
