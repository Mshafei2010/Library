#ifndef USER_H
#define USER_H

#include<cstring>
#include<iostream>
using namespace std;

class User
{

private:
    string name;
    int age;
    int id; // Make sure that the id is incremental. First id is 1, second is 2 and so on
    string password;
    string email;
public:
    static int count;
    User();
    User(string name, int age, string email, string password);
    User(User&user);
    bool operator==(const User& user);
    void setName(string name);
    string getName() const;
    void setPassword(string password);
    string getPassword();
    void setEmail(string email);
    string getEmail();
    void setAge(int age);
    int getAge();
    void setId(int id);
    int getId();
    friend ostream &operator<<(ostream &output, const User &user );
    friend istream &operator>>( istream &input, User &user );
};

#endif // USER_H
