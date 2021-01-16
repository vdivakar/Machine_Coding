#include <string>
using namespace std;
class User{
    private:
        int userID;
        string name;
        string emailID;
    
    public:
        User(int ID, string name_, string email){
            userID = ID;
            name.assign(name_);
            emailID.assign(email);
        }

        string get_emailID(){
            return emailID;
        }
        string get_name(){
            return name;
        }
        int get_userID(){
            return userID;
        }
};



/*
#include "User.h"

User::User(int ID, string name_, string email){
    userID = ID;
    name.assign(name_);
    emailID.assign(email);
}

string User::get_emailID(){
    return emailID;
}
string User::get_name(){
    return name;
}
int User::get_userID(){
    return userID;
}

*/