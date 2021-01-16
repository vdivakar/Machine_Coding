#include <string>
#include <list>
#include <map>
#include <vector>
using namespace std;

#include "User.cpp"

class Card{
private:
    int cardID;
    string cardName;
    string description;
    bool isAssigned;
    map<int, User*> map_id_to_User;

public:
    Card(int id, string name){
        cardID = id;
        cardName = name;
        description = "";
        isAssigned = false;
        map_id_to_User.clear();
    }

    int get_id(){
        return cardID;
    }
    string get_name(){
        return cardName;
    }
    void set_name(string new_name){
        cardName.assign(new_name);
    }
    string get_description(){
        return description;
    }
    void set_description(string new_description){
        description.assign(new_description);
    }
    vector<int> get_assigned_user_ids(){
        vector<int> vec;
        if(isAssigned == false)
            return vec;
        for(auto it: map_id_to_User){
            vec.push_back(it.first);
        }
        return vec;
    }
    void assign_user(User *new_user){
        int id = new_user->get_userID();
        if(map_id_to_User.find(id) != map_id_to_User.end()){
            cout << "Error: This user is already assigned to this Card!" << endl;
        }else{
            map_id_to_User[id] = new_user;
            isAssigned = true;
            // map_id_to_User.insert(make_pair(id, new_user));
        }
    }
    int unassign_user(User* old_user){
        int id = old_user->get_userID();
        if(map_id_to_User.find(id) == map_id_to_User.end()){
            cout << "Error: This user is not a part of this Card" << endl;
            return -1;
        }else{
            map_id_to_User.erase(id);
            if(map_id_to_User.size() == 0)
                isAssigned = false;
            return id;
        }
    }
};


/*
#include "Card.h"
Card::Card(int id, string name, string description_){
        cardID = id;
        cardName = name;
        description = description_;
        isAssigned = false;
        map_id_to_User.clear();
}

int Card::get_id(){
        return cardID;
}
string Card::get_name(){
    return cardName;
}
void Card::set_name(string new_name){
    cardName.assign(new_name);
}
string Card::get_description(){
    return description;
}
void Card::set_description(string new_description){
    description.assign(new_description);
}
vector<int> Card::get_assigned_user_ids(){
    vector<int> vec;
    if(isAssigned == false)
        return vec;
    for(auto it: map_id_to_User){
        vec.push_back(it.first);
    }
    return vec;
}
void Card::assign_user(User &new_user){
    int id = new_user.get_userID();
    if(map_id_to_User.find(id) != map_id_to_User.end()){
        cout << "Error: This user is already assigned to this Card!" << endl;
    }else{
        // map_id_to_User[id] = &new_user;
        // map_id_to_User.insert(make_pair(id, new_user));
    }
}
int Card::unassign_user(User* old_user){
    int id = old_user->get_userID();
    if(map_id_to_User.find(id) == map_id_to_User.end()){
        cout << "Error: This user is not a part of this Card" << endl;
        return -1;
    }else{
        map_id_to_User.erase(id);
        return id;
    }
}
*/