#include <string>
#include <list>
#include <map>
#include <vector>
using namespace std;

#include "User.h"

class Card{
private:
    int cardID;
    string cardName;
    string description;
    bool isAssigned;
    map<int, User*> map_id_to_User;

public:
    Card(int id, string name, string description_);

    int get_id();
    string get_name();
    void set_name(string new_name);
    string get_description();
    void set_description(string new_description);
    vector<int> get_assigned_user_ids();
    void assign_user(User &new_user);
    int unassign_user(User* old_user);
};