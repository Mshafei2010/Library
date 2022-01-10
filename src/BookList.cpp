#include "BookList.h"
#include "UserList.h"
BookList::BookList(int capacity)
{
    this->capacity=capacity;
    books= new Book[capacity];
}

BookList :: BookList(const BookList& anotherList)
{
    this->capacity=anotherList.capacity;
    books= new Book[capacity];
    for (int i=0 ; i < capacity;i++)
    {
        books[i]=anotherList.books[i];
    }
}

void BookList:: addBook (Book mybook,int x)
{
    if(x==1)
        {
            books[booksCount]=mybook;
            books[booksCount].setId(booksCount+1);
            booksCount++;
        }
    else if(x==0)
    {
        books[booksCount-1]=mybook;
    }
}
Book& BookList:: searchBook(string name)
{
    for(int i = 0 ; i < booksCount ; i++)
    {
        if(books[i].getTitle()==name)
        {
            return books[i];
        }
    }
}

Book& BookList:: searchBook(int id)
{
    for(int i = 0 ; i < booksCount ; i++)
    {
        if(books[i].getId()==id)
        {
            return books[i];
        }
    }
}

void BookList :: deleteBook(int id)
{
    int s;
    for(int i = 0 ; i < booksCount; i++)
    {
        if(books[i].getId()==id)
        {
            //delete &books[i];
            s=i;
            break;
        }
    }
    for(int i=s ; i<booksCount-1 ; i++)
    {
        books[i]=books[i+1];
    }
    booksCount--;
}

Book BookList:: getTheHighestRatedBook()
{
    int Max=books[0].getrating();
    int index=0;
    for(int i = 1 ; i < booksCount; i++)
    {
        if(Max<books[i].getrating())
        {
            Max=books[i].getrating();
            index=i;
        }
    }
    return books[index];
}
ostream &operator<<( ostream &output, BookList &booklist )
{
    for(int i = 0 ; i < booklist.booksCount; i++)
    {
        cout
        <<"========Book "<<booklist.books[i].getId()<<" info ========\n"
        <<"Title: "<<booklist.books[i].getTitle()
        <<"\nISBN: "<<booklist.books[i].getISBN()
        <<"\nId: "<<booklist.books[i].getId()
        <<"\nCategory: "<<booklist.books[i].getCategory()
        <<"\nAVG Rating:"<<booklist.books[i].getrating()
        <<"\n======================================\n";
        User x;
        x=booklist.books[i].getAuthor();
        if(x.getName()!="")
        {
            cout<<"========Author info ========\n"
            <<"Name: " << x.getName()
            <<"\nAge: "<<x.getAge()
            <<"\nId: "<<x.getId()
            <<"\nEmail: "<<x.getEmail()
            <<"\n=================================\n\n";
        }
    }
}

void BookList:: setauthor(int id, User user)
{
    int ida;
    for(int i = 0 ; i < booksCount ; i++ )
    {
        if(books[i].getId()==id)
        {
            ida=books[i].getAuthor().getId();
            user.setId(ida);
            books[i].setAuthor(user);
        }
    }
}
void BookList :: setname (int id,string name)
{
    for(int i = 0 ; i < booksCount ; i++ )
    {
        if(books[i].getId()==id)
        {
            books[i].setTitle(name);
        }
    }
}
void BookList::setcategory(int id , string name)
{
    for(int i = 0 ; i < booksCount ; i++ )
    {
        if(books[i].getId()==id)
        {
            books[i].setCategory(name);
        }
    }
}
void BookList :: setrate (int id , int rate)
{
    for(int i = 0 ; i < booksCount ; i++ )
    {
        if(books[i].getId()==id)
        {
            books[i].rateBook(rate);
        }
    }
}

Book* BookList:: getBooksForUser(User userb)
{
    Book *ptr;
    ptr= new Book [capacity];
    int counter=0;
    for(int i =0 ; i <booksCount ; i++)
    {
        if(books[i].getAuthor().getName()==userb.getName())
        {
            ptr[counter]=books[i];
            counter++;
        }
    }
    return ptr;
}

BookList::~BookList()
{
    delete [] books;
    booksCount=0;
    books=NULL;
}
Book & BookList:: operator [ ] (int position)
{
    if(position<0 || position>=capacity)
    {
        cout<<"you reached your limit of Books\n";

    }
    else
    {
        return books[position];
    }
}
