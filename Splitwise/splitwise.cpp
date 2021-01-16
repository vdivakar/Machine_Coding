#include <vector>
using namespace std;
#include "transaction.cpp"
#include "user.cpp"

class Splitwise{
    private:
        int UID;
        vector<User> users;
    public:
        Splitwise(){
            UID=0;
            users.clear();
        }
        void showAllBalances(){

        }
        void showUserBalances(int uid){
            
        }
};