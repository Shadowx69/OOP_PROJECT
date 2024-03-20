#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <utility>

using namespace std;

class Book {
private:
    string title, author;
    int publicationYear;

public:
    Book(string title, string author, int publicationYear)
        : title(move(title)), author(move(author)), publicationYear(publicationYear) {}

    const string& getTitle() const { return title; }
    const string& getAuthor() const { return author; }
    int getPublicationYear() const { return publicationYear; }
};

class Library {
private:
    vector<Book> books;
    unordered_map<string, size_t> titleToIndex;

public:
    void addBook(Book book) {
        books.push_back(move(book));
        titleToIndex[books.back().getTitle()] = books.size() - 1;
    }

    void removeBook(const string& title) {
        auto it = titleToIndex.find(title);
        if (it != titleToIndex.end()) {
            books.erase(books.begin() + it->second);
            for (auto& entry : titleToIndex)
                if (entry.second > it->second) --entry.second;
            titleToIndex.erase(it);
            cout << "Book '" << title << "' removed from the library." << endl;
        } else cout << "Book not found." << endl;
    }

    void listBooks() const {
        if (books.empty()) cout << "Library is empty." << endl;
        else for (const auto& book : books)
            cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor()
                 << ", Publication Year: " << book.getPublicationYear() << endl;
    }
};


