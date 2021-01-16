#include <string>
using namespace std;
class User{
    private:
        int userID;
        string name;
        string emailID;
    
    public:
        User(int ID, string name_, string email){};
        // User(int ID, string name_, string email){
        // userID = ID;
        // name.assign(name_);
        // emailID.assign(email);
        // }

        string get_emailID();
        string get_name();
        int get_userID(){
            return userID;
        }
};