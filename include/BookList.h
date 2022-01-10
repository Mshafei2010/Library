#ifndef BOOKLIST_H
#define BOOKLIST_H
#include "Book.h"
#include "UserList.h"
class BookList
{
private:
    Book* books;
    int capacity;
    int booksCount=0;
public:
    BookList(const BookList& anotherList);//copy list
    BookList(int capacity);//create list
    Book& searchBook(string name);//search for book by name
    Book& searchBook(int id);//search for book by Id
    void deleteBook(int id); //delete a book
    Book getTheHighestRatedBook();//get high rating book
    Book* getBooksForUser(User); // get all books of this author
    Book & operator [ ] (int position);//to prevent any error while input
    friend ostream &operator<<( ostream &output, BookList &booklist ); //to display all books
    ~BookList();//delete dynamic arrays
    void addBook (Book mybook,int x);//to add book to list
    void setauthor(int id,User user);//to set author in book
    void setname (int id,string name);//to set name of book
    void setcategory(int id , string name);//to set category of book
    void setrate (int id , int rate);//to set rate of book
    void getauthor();//to get author
};

#endif // BOOKLIST_H
