#include <string>
#include <unordered_map>
using namespace std;
class User{
    private:
        string name, email, phone;
        int ID;
        double balance;
        unordered_map<int ,double> peers;
    public:
        User(string Name, string Email="", string Phone=""){
            name = Name;
            email = Email;
            phone = Phone;
            balance = 0.0;
            peers.clear();
        }
        double getBalance(){
            return balance;
        }
        void doTransaction(int id, double amount){
            peers[id]+=amount; //if amount>0 : current user owes to id else vice-versa
            balance+=amount;
        }
        double getPeerBalance(int id){
            if(peers.find(id) != peers.end())
                return peers[id];
            return 0.0;
        }

};