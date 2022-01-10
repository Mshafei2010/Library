#include "UserList.h"
int UserList :: counter=0;
UserList::UserList(int capacity)
{
    this ->capacity = capacity;
    users=new User[capacity];
}
void UserList::addUser(User user)
{
    users[counter]=user;
    users[counter].setId(counter+1);
    counter++;
}
ostream &operator<<( ostream &output, UserList &userList )
{
    for(int i = 0 ; i < userList.counter ; i++)
    {
        cout
        <<"========User "<<userList.users[i].getId()<<" info ========\n"
        <<"Name: "<<userList.users[i].getName()
        <<"\nAge: "<<userList.users[i].getAge()
        <<"\nId: "<<userList.users[i].getId()
        <<"\nEmail: "<<userList.users[i].getEmail()
        <<"\n======================================\n";
    }
}
User& UserList:: searchUser(string name)
{
    for(int i = 0 ; i < counter ; i++)
    {
        if(users[i].getName()==name)
        {
            return users[i];
        }
    }
}
User& UserList::searchUser(int id)
{
    for(int i = 0 ; i < counter ; i++)
    {
        if(users[i].getId()==id)
        {
            return users[i];
        }
    }
}
void UserList:: deleteUser(int id)
{
    int s;
    for(int i = 0 ; i < counter ; i++)
    {
        if(users[i].getId()==id)
        {
            //delete &users[i];
            s=i;
            break;
        }
    }
    for(int i=s ; i<counter-1 ; i++)
    {
        users[i]=users[i+1];
    }
    counter--;
}
UserList::~UserList()
{
    delete [] users;
    counter=0;
    users=NULL;
}
