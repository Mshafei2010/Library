#include "User.h"
//default constructor
int User::count=0;
User::User()
{
    count++;
    name="";
    id=0;
    age=0;
    password="";
    email="";
    id=count;
}
//constructor
User::User(string name, int age, string email, string password)
{
    count++;
    id=count;
    this->name=name;
    this->age=age;
    this->email=email;
    this->password=password;
    //cout <<"E"<<email<<" ";
}
//copy constructor
User::User(User &user)
{
    id=user.id;
    name=user.name;
    age=user.age;
    email=user.email;
    password=user.password;
}
//for username
void User::setName(string name)
{
    this->name=name;
}
string User::getName() const
{
    return name;
}
//for Password
void User::setPassword(string password)
{
    this->password=password;
}
string User::getPassword()
{
    return password;
}
//for Email
void User::setEmail(string email)
{
    this->email=email;
}
string User::getEmail()
{
    return email;
}
//for age
void User::setAge(int age)
{
    this->age=age;
}
int User::getAge()
{
    return age;
}
//for id
void User::setId(int id)
{
    this->id=id;
}
int User::getId()
{
    return id;
}
bool User::operator ==(const User& user)
{
    bool flag=0;
    if(email ==user.email && age==user.age && name==user.name && id==user.id)
    {
        flag=1;
    }
    return flag;
}
ostream &operator<<(ostream &output, const User &user )
{
    output<<"Name: "<<user.name<<"|Age: "<<user.age<<"|id: "<<user.id<<"|Email: "<<user.email<<"\n===============================\n\n";
    return output;
}
istream &operator>>( istream &input, User &user )
{
    input>>user.name>>user.age>>user.email>>user.password;
    return input;
}
