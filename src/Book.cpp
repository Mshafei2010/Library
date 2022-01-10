#include "Book.h"
int Book::count=0;
Book::Book()
{
    count++;
    title="";
    isbn="";
    id=count;
    category="";
    averageRating=0;
    author;
}
Book::Book(string title, string isbn, string category)
{
    count++;
    id=count;
    averageRating=0;
    this->title=title;
    this->isbn=isbn;
    this->category=category;
}
Book::Book(const Book& book)
{
    title=book.title;
    isbn=book.isbn;
    id=book.id;
    category=book.category;
    averageRating=book.averageRating;
    author=book.author;
}
//Title
void Book::setTitle(string title)
{
    this->title=title;
}
string Book:: getTitle()
{
    return title;
}
//ISBN
void Book:: setISBN(string isbn)
{
    this->isbn=isbn;
}
string Book:: getISBN()
{
    return isbn;
}
//Id
void Book::setId(int id)
{
    this->id=id;
}
int Book::getId()
{
    return id;
}
//Category
void Book::setCategory(string category)
{
    this->category=category;
}
string Book::getCategory()
{
    return category;
}
//Author
void Book::setAuthor(User user)
{
    author=user;
}
User Book::getAuthor()
{
    return author;
}
bool Book::operator==(const Book& book)
{
    bool flag=0;
    if(author==book.author&& title==book.title&& isbn==book.isbn&& id==book.id && category==book.category)
    {
        flag=1;
    }
    return flag;
}
ostream &operator<<(ostream &output, const Book &book )
{
    output<<"\n========Book"<<book.id<<" info========\n"<<"Title: "<<book.title<<"|ISBN: "<< book.isbn<<"|id: "<<book.id<<"|Category: "<<book.category<<"|Avg Rating: "<<book.averageRating<<"\n===============================\n\n";
}
istream &operator>>( istream &input, Book &book )
{
    input>>book.title>>book.isbn>>book.category;
}
void Book::rateBook(int rating)
{
    averageRating=((averageRating*(num-1))+rating)/num;
    num++;
}
double Book::getrating()
{
    return averageRating;
}
