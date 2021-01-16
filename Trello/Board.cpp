#include <map>
#include <string>
#include <iostream>
using namespace std;

#include "List.cpp"
// #include "User.cpp"

enum Privacy{PUBLIC, PRIVATE};

class Board{
private:
    int boardID;
    string boardName;
    Privacy privacy;
    string url;
    map<int, User*> map_id_to_User;
    map<int, List*> map_id_to_List;

public:
    Board(int id, string name){
        boardID = id;
        boardName = name;
        privacy = PUBLIC;
        map_id_to_List.clear();
        map_id_to_User.clear();
    }
    void add_member(User* new_user){
        int id = new_user->get_userID();
        if(map_id_to_User.find(id) == map_id_to_User.end()){
            map_id_to_User[id] = new_user;
        }
    }
    int remove_member(User* old_user){
        int id = old_user->get_userID();
        if(map_id_to_User.find(id) == map_id_to_User.end())
            return -1; //User not found
        map_id_to_User.erase(id);
        return id; //Return id of the user which is deleted successfully
    }
    void add_list(List* new_list){
        int id = new_list->get_id();
        if(map_id_to_List.find(id) != map_id_to_List.end()){
            cout << "Error: List already exist in the current board!" << endl;
            return;
        }else{
            map_id_to_List[id] = new_list;
        }
    }
    int remove_list(List* old_list){
        int id = old_list->get_id();
        if(map_id_to_List.find(id) == map_id_to_List.end()){
            cout << "Error: List does not exist in the current board!" << endl;
            return -1; // List not Found
        }else{
            map_id_to_List.erase(id);
        }
    }
    Privacy get_privacy(){
        return privacy;
    }
    void set_privacy(Privacy new_privacy){
        privacy = new_privacy;
    }
    int get_id(){
        return boardID;
    }
    string get_name(){
        return boardName;
    }
    void set_name(string new_name){
        boardName.assign(new_name);
    }
};