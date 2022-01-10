#ifndef USERLIST_H
#define USERLIST_H
#include <iostream>
#include "User.h"

class UserList
{
private:
    User* users;
    int capacity;
    int usersCount;
public:
    UserList(int capacity);//to create list
    void addUser(User user); // at the end of the array.
    User& searchUser(string name);//to search for a user by name
    User& searchUser(int id);//to search for a user by id
    void deleteUser(int id);//to delete User
    friend ostream &operator<<( ostream &output, UserList &userList );//to display all books
    static int counter;//used to move through array
    ~UserList();//to delete dynamic array
};

#endif // USERLIST_H
