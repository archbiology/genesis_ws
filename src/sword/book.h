#ifndef SWORD_BOOK
#define SWORD_BOOK

#include <string>
#include <map>

using namespace std;

/**
 * The verses of a given chapter
 */
#define verses map<int, string>

/**
 * The parent class of books of the Holy Bible
 */
class Book
{
public:
    /**
     * Book name
     */
    string name;

    /**
     * Book order in which the book appears in the Holy Bible
     */
    int number;

    /**
     * The chapters of the book <chapter_number, verses>
     */
    map<int, verses> chapters;

    /**
     * Default constructor
     */
    Book(int number, string name, map<int, verses> chapters) : number(number), name(name), chapters(chapters) {}
};

#endif // SWORD_BOOK