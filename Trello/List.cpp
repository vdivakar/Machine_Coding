#include <string>
#include <map>
#include <list>
using namespace std;
#include "Card.cpp"

class List{
private:
    int listID;
    string listName;
    map<int, Card*> map_id_to_Card;

public:
    List(int id, string name){
        listID = id;
        listName.assign(name);
    }
    int get_id(){
        return listID;
    }
    string get_name(){
        return listName;
    }
    void set_name(string new_name){
        listName.assign(new_name);
    }
    vector<Card*> get_all_card_ids(){
        vector<Card*> vec;
        for(auto it: map_id_to_Card){
            vec.push_back(it.second);
        }
        return vec;
    }

    int add_card(Card *new_card){
        int id = new_card->get_id();
        if(map_id_to_Card.find(id) != map_id_to_Card.end()){
            cout << "Error: Card already exist!" << endl;
            return -1;
        }else{
            map_id_to_Card[id] = new_card;
            return id;
        }
    }
    int remove_card(Card *old_card){
        int id = old_card->get_id();
        if(map_id_to_Card.find(id) == map_id_to_Card.end()){
            cout << "Error: Add does not exist in the current List!" << endl;
            return -1;
        }else{
            map_id_to_Card.erase(id);
            return id;
        }
    }
    void remove_all_cards(){
        vector<Card*> all_cards;
        all_cards = get_all_card_ids();
        for(Card* card: all_cards){
            remove_card(card);
        }
    }
};