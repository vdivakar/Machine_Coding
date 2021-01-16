#include <list>
#include <unordered_map>
using namespace std;

class Transaction{
    protected:
        int doer_id; //user id who makes the transaction
        double transaction_amount;
        int people_involved;
        list<int> users_involved_id;
    public:
        unordered_map<int, double> per_user_share;
};

class EqualTransaction:public Transaction{
    public:
        EqualTransaction(int Doer_id, double Transaction_amount, list<int> users):Transaction(){
            doer_id = Doer_id;
            transaction_amount = Transaction_amount;
            people_involved = users.size();
            users_involved_id = users;

            split();
        }
        int getDoerID(){
            return doer_id;
        }
    private:
        void split(){
            double per_user_amount = transaction_amount/(double)people_involved;
            for(auto it: users_involved_id){
                per_user_share[it] = per_user_amount;
            }
        }
};

class ExactTransaction:public Transaction{
    public:
        ExactTransaction(int Doer_id, double Transaction_amount, list<int> users, list<double> exact_amounts):Transaction(){
            doer_id = Doer_id;
            transaction_amount = Transaction_amount;
            people_involved = users.size();
            users_involved_id = users;

            split(exact_amounts);
        }
        int getDoerID(){
            return doer_id;
        }
    private:
        void split(list<double> exact_amounts){
            list<double>::iterator it_amt = exact_amounts.begin();
            list<int>   ::iterator it_user= users_involved_id.begin();

            for(; it_amt!=exact_amounts.end() && it_user!=users_involved_id.end(); it_amt++, it_user++){
                per_user_share[*it_user] = *it_amt;
            }
        }
};

class PercentTransaction:public Transaction{
    public:
        PercentTransaction(int Doer_id, double Transaction_amount, list<int> users, list<double> percent_amounts):Transaction(){
            doer_id = Doer_id;
            transaction_amount = Transaction_amount;
            people_involved = users.size();
            users_involved_id = users;

            split(percent_amounts);
        }
        int getDoerID(){
            return doer_id;
        }
    private:
        void split(list<double> percent_amounts){
            list<double>::iterator it_amt = percent_amounts.begin();
            list<int>   ::iterator it_user= users_involved_id.begin();

            for(; it_amt!=percent_amounts.end() && it_user!=users_involved_id.end(); it_amt++, it_user++){
                per_user_share[*it_user] = (*it_amt)*(transaction_amount)/100;
            }
        }
};