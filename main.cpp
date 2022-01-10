#include <iostream>
#include "User.h"
#include "Book.h"
#include "Userlist.h"
#include "BookList.h"
using namespace std;

int main()
{
    cout << "Select one of the following choices:\n" << "1-Books Menu\n"<<"2-User Menu\n"<<"3-Exit\n";
    int choicem;
    cin >> choicem;
    int capacity=100;
    int idusercounter=0;
    //to assign users
    if(choicem==2)
    {
        cout << "How many users will be add?\n";
        cin >> capacity;
    }
    int flaguser=0;
    User user[capacity];
    UserList one (capacity);
    //Menus
    while (1)
    {
        // Exit
        if(choicem==3)
        {
            return 0;
        }
        //Users
        else if(choicem==2)
        {
            int choicea;
            if(flaguser!=0)
            {
                cout << "How many users will be add?\n";
                cin >> capacity;
                idusercounter=0;
                User user[capacity];
                UserList one (capacity);
            }
            //Users Menu
            while(1)
            {
                cout
                        <<"USERS MENU\n"
                        << "1-Create a USER and add it to the list\n"
                        <<"2-Search for a user\n"
                        <<"3-Display all users\n"
                        <<"4-Back to the main menu\n";
                cin >>choicea;
                //Enter User
                if(choicea==1)
                {
                    cout <<"Enter the user information in this order\n"<<"Name Age Email Password (Space separated)\n";
                    cin>>user[idusercounter];
                    one.addUser(user[idusercounter]);
                    idusercounter++;
                }
                //Search
                else if(choicea==2)
                {
                    int choicese=0;
                    while(choicese!=3)
                    {
                        cout
                                <<"SEARCH FOR A USER\n"
                                <<"1- Search by name\n"
                                <<"2- Search by id\n"
                                <<"3- Back to Users Menu\n";
                        cin >> choicese;
                        //Search by Name
                        if(choicese==1)
                        {
                            string namee;
                            cout << "Enter Name\n";
                            cin>>namee;
                            User ptr;
                            ptr=one.searchUser(namee);
                            int choiced;
                            cout
                                    <<"========User "<<ptr.getId()<<" info ========\n"
                                    <<"Name: "<<ptr.getName()
                                    <<"\nAge: "<<ptr.getAge()
                                    <<"\nId: "<<ptr.getId()
                                    <<"\nEmail: "<<ptr.getEmail()
                                    <<"\n======================================\n"
                                    <<"1- Delete user\n"
                                    <<"2- Return to Users Menu\n";
                            cin>>choiced;
                            //delete
                            if(choiced==1)
                            {
                                one.deleteUser(ptr.getId());
                                for(int i=0 ; i < idusercounter ; i++)
                                {
                                    if(user[i].getId()==ptr.getId())
                                    {
                                        user[i].setAge(0);
                                        user[i].setEmail("");
                                        user[i].setId(0);
                                        user[i].setName("");
                                    }
                                }
                            }
                        }
                        //Search by ID
                        else if(choicese==2)
                        {
                            int id;
                            cout << "Enter id\n";
                            cin>>id;
                            User ptr;
                            ptr=one.searchUser(id);
                            int choiced;
                            cout
                                    <<"========User "<<ptr.getId()<<" info ========\n"
                                    <<"Name: "<<ptr.getName()
                                    <<"\nAge: "<<ptr.getAge()
                                    <<"\nId: "<<ptr.getId()
                                    <<"\nEmail: "<<ptr.getEmail()
                                    <<"\n======================================\n"
                                    <<"1- Delete user\n"
                                    <<"2- Return to Users Menu\n";
                            cin>>choiced;
                            //Delete
                            if(choiced==1)
                            {
                                one.deleteUser(ptr.getId());
                                for(int i=0 ; i < idusercounter ; i++)
                                {
                                    if(user[i].getId()==ptr.getId())
                                    {
                                        user[i].setAge(0);
                                        user[i].setEmail("");
                                        user[i].setId(0);
                                        user[i].setName("");
                                    }
                                }
                            }
                        }
                    }
                }
                //Display
                else if(choicea==3)
                {
                    cout<<one;
                }
                //exit user menu
                else if(choicea==4)
                {
                    flaguser=1;
                    break;
                }
            }
        }
        //Books
        else if (choicem==1)
        {
            cout << "How many books will be add?\n";
            cin>>capacity;
            Book book[capacity];
            BookList onebook (capacity);
            int idbookcounter=0;
            //Book Menu
            while(1)
            {
                cout<<"BOOK MENU\n"
                    <<"1-Create a book and add it to the list\n"
                    << "2-Search for a book\n"
                    << "3-Display all books(with book rating)\n"
                    << "4-Get the highest rating book\n"
                    << "5-Get all books for a user\n"
                    << "6-Copy the current book list to a new book list and switch to it\n"
                    << "7-Back to the main menu\n";
                int choicea;
                cin >>choicea;
                //Enter book
                if(choicea==1)
                {
                    cout
                            <<"Enter the book information in this order\n"
                            <<"Title ISBN Category (Space separated)\n";
                    cin >> book[idbookcounter];
                    onebook.addBook(book[idbookcounter],1);
                    idbookcounter++;
                    int choiceathr;
                    int id1;
                    while(1)
                    {
                        cout
                                <<"1- Assign author\n"
                                <<"2- Continue\n";
                        cin>>choiceathr;
                        if(choiceathr==1)
                        {
                            cout << "Enter author (user) id\n";
                            cin>>id1;
                            bool flag = 0;
                            User r=one.searchUser(id1);
                            book[idbookcounter-1].setAuthor(r);
                            onebook.addBook(book[idbookcounter-1],0);
                            flag=1;
                            /*
                            for(int i =0 ; i <idusercounter; i++)
                            {
                                if(user[i].getId()==id1)
                                {
                                    //User x= one.users[i];
                                    book[idbookcounter-1].setAuthor(user[i]);
                                    onebook.addBook(book[idbookcounter-1],0);
                                    flag=1;
                                }
                            }*/
                            if(flag==0)
                            {
                                cout<<"No Author Found with id ="<<id1<<"\n";
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                //Search book
                else if(choicea==2)
                {
                    cout
                            <<"SEARCH FOR A Book\n"
                            <<"1- Search by name\n"
                            <<"2- Search by id\n"
                            <<"3- Back to Books Menu\n";
                    int choicese;
                    cin >>choicese;
                    Book book22;
                    //Search by Name
                    if(choicese==1)
                    {
                        string name;
                        cout <<"Enter name\n";
                        cin >> name;
                        book22= onebook.searchBook(name);
                    }
                    //Search by ID
                    else if(choicese==2)
                    {
                        int id;
                        cout <<"Enter id\n";
                        cin >> id;
                        book22= onebook.searchBook(id);
                    }
                    //exit Search
                    else if(choicese==3)
                    {
                        continue;
                    }
                    //Display result of search
                    cout
                            <<"\n========Book "<<book22.getId()<<" info========\n"
                            <<"Title: "<<book22.getTitle()
                            <<"\nISBN: "<< book22.getISBN()
                            <<"\nid: "<<book22.getId()
                            <<"\nCategory: "<<book22.getCategory()
                            <<"\nAvg Rating: "<<book22.getrating();
                    User newe ;
                    newe= book22.getAuthor();
                    cout <<"\nAuthor: "<<newe.getName()<<"\n\n";
                    //Function for searched book
                    while(1)
                    {
                        cout
                                <<"\n1- Update author"
                                <<"\n2- Update name"
                                <<"\n3- Update Category"
                                <<"\n4- Delete Book"
                                <<"\n5- Rate Book"
                                <<"\n6- Get back to books menu\n";
                        int choicesearch;
                        cin>>choicesearch;
                        string namew;
                        //Update author
                        if(choicesearch==1)
                        {
                            cout <<"Enter Author name\n";
                            cin >>namew;
                            for(int i =0 ; i <idusercounter; i++)
                            {
                                if(user[i].getName()==newe.getName())
                                {
                                    user[i].setName(namew);
                                    newe.setName(namew);
                                    onebook.setauthor(book22.getId(),user[i]);
                                }
                            }
                        }
                        //Update name
                        else if(choicesearch==2)
                        {
                            cout <<"Enter Title\n";
                            cin >>namew;
                            onebook.setname(book22.getId(),namew);
                        }
                        //Update Category
                        else if(choicesearch==3)
                        {
                            cout <<"Enter Category\n";
                            cin >>namew;
                            onebook.setcategory(book22.getId(),namew);
                        }
                        //Delete Book
                        else if(choicesearch==4)
                        {
                            onebook.deleteBook(book22.getId());
                            for(int i=0 ; i < idbookcounter ; i++)
                            {
                                if(book[i].getId()==book22.getId())
                                {
                                    book[i].setId(0);
                                    book[i].setCategory("");
                                    book[i].setISBN("");
                                    book[i].setTitle("");
                                    book[i].rateBook(0);
                                }
                            }
                        }
                        //Rate Book
                        else if(choicesearch==5)
                        {
                            int rate ;
                            cout<<"Enter book rate\n";
                            cin >> rate;
                            onebook.setrate(book22.getId(),rate);
                        }
                        //exit
                        else if(choicesearch==6)
                        {
                            break;
                        }
                    }
                }
                //Display all Books in list
                else if(choicea==3)
                {
                    cout<<onebook;
                }
                //Get the highest rating book
                else if(choicea==4)
                {
                    Book newboook =onebook.getTheHighestRatedBook();
                    cout
                            <<"\n========Book "<<newboook.getId()<<" info========\n"
                            <<"Title: "<<newboook.getTitle()
                            <<"\nISBN: "<< newboook.getISBN()
                            <<"\nid: "<<newboook.getId()
                            <<"\nCategory: "<<newboook.getCategory()
                            <<"\nAvg Rating: "<<newboook.getrating();
                    User newew;
                    newew = newboook.getAuthor();
                    //display the book with high rating and if is put to not put a book that has no data
                    if(newew.getName()!="")
                    {
                        cout<<"\n========Author info ========\n"
                            <<"Name: " << newew.getName()
                            <<"\nAge: "<<newew.getAge()
                            <<"\nId: "<<newew.getId()
                            <<"\nEmail: "<<newew.getEmail()
                            <<"\n=================================\n\n";
                    }

                }
                //getting one user books'
                else if(choicea==5)
                {
                    cout << "Enter User ID\n";
                    int iddd;
                    cin>>iddd;
                    User userr = one.searchUser(iddd);
                    Book * ptrbook;
                    ptrbook=onebook.getBooksForUser(userr);
                    int icounter=0;
                    while(ptrbook[icounter].getTitle()!="")
                    {
                        cout
                                <<"\n========Book "<<ptrbook[icounter].getId()<<" info========\n"
                                <<"Title: "<<ptrbook[icounter].getTitle()
                                <<"\nISBN: "<< ptrbook[icounter].getISBN()
                                <<"\nid: "<<ptrbook[icounter].getId()
                                <<"\nCategory: "<<ptrbook[icounter].getCategory()
                                <<"\nAvg Rating: "<<ptrbook[icounter].getrating()<<"\n\n";
                        icounter++;
                    }
                }
                //Copy current list
                else if(choicea==6)
                {
                    BookList twobook (onebook);
                    cout<<"Copied current list ("<<idbookcounter<<" books) to a new list and switched to it\n";
                }
                else if(choicea==7)
                {
                    break;
                }
            }
        }
        //choose menu or to exit
        cout << "=======================================================\n";
        cout << "Select one of the following choices:\n" << "1-Books Menu\n"<<"2-User Menu\n"<<"3-Exit\n";
        cin >> choicem;
    }
}


// Assignment 1 code
/*cout << "Let's add a user" << endl<<"Enter the user information in this order\n"<<"Name Age Email Password (Space separated)\n";
    User one;
    string name,email,password;
    int age;
    //cin>>name>>age>>email>>password;
    /*one.setName(name);
    one.setAge(age);
    one.setEmail(email);
    one.setPassword(password);
    *//*cin>>one;//    also for input
    cout<<"========User 1 info========\n";
    cout <<"Name: "<<one.getName()<<"|Age: "<< one.getAge()<<"|id: "<<one.getId()<<"|Email: "<<one.getEmail()<<"\n===============================\n\n";
    cout << "Let's add a user" << endl<<"Enter the user information in this order\n"<<"Name Age Email Password (Space separated)\n";
    //User 2
    cin>>name>>age>>email>>password;
    User two(name,age,email,password);
    cout<<"========User 2 info========\n";
    //cout <<"Name: "<<two.getName()<<"|Age: "<< two.getAge()<<"|id: "<<two.getId()<<"|Email: "<<two.getEmail()<<"\n===============================\n\n";
    cout<<two;
    //Book
    cout << "Let's add a book" << endl<<"Enter the book information in this order\n"<<"Title ISBN Category (Space separated)\n";
    Book first;
    string TITILE , ISBN , CATEGORY;
    cin >> TITILE >> ISBN >>CATEGORY;
    first.setTitle(TITILE);
    first.setISBN(ISBN);
    first.setCategory(CATEGORY);
    cout<<"========Book 1 info========\n";
    cout <<"Title: "<<first.getTitle()<<"|ISBN: "<< first.getISBN()<<"|id: "<<first.getId()<<"|Category: "<<first.getCategory()<<"|Avg Rating: "<<first.getrating()<<"\n===============================\n\n";
    cout << "Let's add another book" << endl<<"Enter the book information in this order\n"<<"Title ISBN Category (Space separated)\n";
    cin >> TITILE >> ISBN >>CATEGORY;
    Book fir(TITILE , ISBN ,CATEGORY);
    cout<<"========Book 2 info========\n";
    cout <<"Title: "<<fir.getTitle()<<"|ISBN: "<< fir.getISBN()<<"|id: "<<fir.getId()<<"|Category: "<<fir.getCategory()<<"|Avg Rating: "<<fir.getrating()<<"\n===============================\n\n";
    cout << "Let's assign an author for the first book , set the first user as an author\n"<<"Let's rate the first book with : ";
    int rate;
    cin >>rate;
    first.setAuthor(one);
    first.rateBook(rate);
    cout << " another rating :";
    cin >>rate;
    first.rateBook(rate);
    cout << first;
    cout<<"========User 1 info========\n";
    cout<<first.getAuthor();
    cout << "let's add a new rating for b1 with : ";
    cin >> rate;
    first.rateBook(rate);
    cout << first;
    cout<<"========User 1 info========\n";
    cout<<first.getAuthor();
    return 0;*/
//id increase
