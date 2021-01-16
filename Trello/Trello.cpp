#include "Board.cpp"
// #include "List.cpp"
// #include "Card.cpp"
// #include "User.cpp"
using namespace std;

class Trello{
private:
    int unique_board_id;
    int unique_list_id;
    int unique_card_id;
    int unique_user_id;

    map<int, Board*> map_Boards;
    map<int, List*> map_Lists;
    map<int, Card*> map_Cards;
    map<int, User*> map_Users;

public:
    Trello(){
        unique_board_id = 1;
        unique_list_id = 1;
        unique_card_id = 1;
        unique_user_id = 1;
        map_Boards.clear();
        map_Lists.clear();
        map_Cards.clear();
        map_Users.clear();
    }

    //Would have been better if you create
    //Board manager, List manager, Card manager separately

    //Board modifications
    int create_board(string name){
        int id = unique_board_id++;
        Board *new_board = new Board(id, name);
        map_Boards[id] = new_board;
        cout << "New Board created. ID: " << id << " | Name: " << name << endl;
        return id;
    }
    int delete_board(int id){
        if(map_Boards.find(id) == map_Boards.end()){
            cout << "Error: Board with id " << id << " does not exist!" << endl;
            return -1;
        }else{

            map_Boards.erase(id);
            cout << "Board with id " << id << " deleted successfully!" << endl;
            return id;
        }
    }
    void set_board_name(int id, string new_name){
        if(map_Boards.find(id) == map_Boards.end()){
            cout << "Error: Board does not exist!" << endl;
            return;
        }else{
            Board *board = map_Boards[id];
            board->set_name(new_name);
        }
    }
    void set_board_privacy(int id, Privacy new_privacy){
        if(map_Boards.find(id) == map_Boards.end()){
            cout << "Error: Board does not exist!" << endl;
        }else{
            Board *board = map_Boards[id];
            board->set_privacy(new_privacy);
        }
    }
    void add_board_member(int id, User *new_user){
        if(map_Boards.find(id) != map_Boards.end()){
            Board* board = map_Boards[id];
            board->add_member(new_user);
        }
    }
    void remove_board_member(int id, User *old_user){
        if(map_Boards.find(id) != map_Boards.end()){
            Board* board = map_Boards[id];
            board->remove_member(old_user);
        }
    }
    void add_list_to_board(int boardID, int listID){
        if(map_Boards.find(boardID) == map_Boards.end() || map_Lists.find(listID)==map_Lists.end()){
            cout << "Error: Board or List does not exist!" << endl;
            return;
        }
        Board *board = map_Boards[boardID];
        board->add_list(map_Lists[listID]);
    }

    //List modifications
    int create_list(int board_id, string name){
        int id = unique_list_id++;
        List *list_ = new List(id, name);
        map_Lists[id] = list_;
        add_list_to_board(board_id, id);
        return id;
    }
    int delete_list(int id){
        if(map_Lists.find(id) == map_Lists.end()){
            cout << "Error: List does not exist!" << endl;
            return -1;
        }else{
            List *list_ = map_Lists[id];
            list_->remove_all_cards();
            map_Lists.erase(id);
            return id;
        }
    }
    void add_card_to_list(int list_id, int card_id){
        if(map_Lists.find(list_id)==map_Lists.end() || map_Cards.find(card_id) == map_Cards.end()){
            cout << "Error: Card or List not found!" << endl;
        }else{
            List *list_ = map_Lists[list_id];
            list_->add_card(map_Cards[card_id]);
        }
    }

    //Card modifications
    int create_card(int list_id, string name){
        int id = unique_card_id++;
        Card *card = new Card(id, name);
        map_Cards[id] = card;
        add_card_to_list(list_id, id);
        return id;
    }
    void set_card_name(int card_id, string new_name){
        if(map_Cards.find(card_id) != map_Cards.end()){
            Card *card = map_Cards[card_id];
            card->set_name(new_name);
        }
    }
    void set_card_description(int card_id, string new_description){
        if(map_Cards.find(card_id) != map_Cards.end()){
            Card *card = map_Cards[card_id];
            card->set_description(new_description);
        }
    }
    void assign_user_to_card(int card_id, User* user){
        if(map_Cards.find(card_id) != map_Cards.end()){
            Card *card = map_Cards[card_id];
            card->assign_user(user);
        }
    }
    void unassign_user_from_card(int card_id, User *user){
        if(map_Cards.find(card_id) != map_Cards.end()){
            Card *card = map_Cards[card_id];
            card->unassign_user(user);
        }
    }
    //Not implemented: Card move from 1 list to another.
    //Will have to add parent of Card if not given as input.



};