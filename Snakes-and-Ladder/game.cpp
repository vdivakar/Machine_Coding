#include <iostream>
using namespace std;
#include "dice.cpp"
#include "board.cpp"
#include "player.cpp"

class Game{
    private:
        Board game_board;
        Dice dice;
        int total_players;
        vector<Player> players;
        bool isFinished;
        string winner;
    public:
        Game(){
            isFinished = false;
        }

        void setBoardValues(vector<pair<int,int> > vec){
            for(pair<int,int> p : vec){
                int key = p.first;
                int val = p.second;
                game_board.setValue(key, val);
            }
        }
        void setSnakes(vector<pair<int,int> > snakes){
            setBoardValues(snakes);
        }
        void setLadders(vector<pair<int,int> > ladders){
            setBoardValues(ladders);
        }
        void setPlayers(int num_players, vector<string> player_names){
            total_players = num_players;
            for(int i=0; i<num_players; i++){
                players.push_back(Player(player_names[i]));
            }
        }
        void move_player(int p_idx, int dice_value){
            Player* player = &players[p_idx];
            int current_pos = player->getPos();
            int destination = current_pos + dice_value;
            if(destination > game_board.getBoardSize()){
                destination = current_pos;
            }else{
                while(game_board.getValue(destination) != 0){
                    //Move while you encounter ladders or snakes
                    destination = game_board.getValue(destination);
                }
            }
            player->setPos(destination);

            cout << player->getName() << " rolled a " << dice_value << " and moved from " << 
                current_pos << " to " << destination << endl;

            if(destination == game_board.getBoardSize()){
                //Game Won by the current player
                isFinished = true;
                winner = player->getName();
                cout << winner << " wins the game" << endl;
            }
        }
        void play(){
            int player_id = 0;

            while(isFinished==false){
                int dice_value = dice.roll();
                move_player(player_id, dice_value);
                player_id = (player_id+1)%total_players; //change player turn
            }
        }
};


int main(){
    cout << "Welcome to Jumanji!" << endl;

    Game game;
    vector<string> player_names;
    player_names.push_back("denis");
    player_names.push_back("verma");
    player_names.push_back("Priyanka");
    player_names.push_back("DV");
    game.setPlayers(player_names.size(), player_names);
    game.play();
    return 0;
}