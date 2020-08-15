#include <iostream>
#include "game.cpp"

int main(){
    cout << "~~Welcome to Snakes and Ladders!~~" << endl;

    Game game;

    int total_snakes, total_ladders;
    int total_players;
    vector<pair<int,int> > snakes, ladders;
    vector<string> players;

    cin >> total_snakes;
    while(total_snakes--){
        int head, tail;
        cin >> head;
        cin >> tail;
        snakes.push_back(make_pair(head, tail));
    }

    cin >> total_ladders;
    while(total_ladders--){
        int start, end;
        cin >> start;
        cin >> end;
        ladders.push_back(make_pair(start, end));
    }

    cin >> total_players;
    while(total_players--){
        string name;
        cin >> name;
        players.push_back(name);
    }

    game.setSnakes(snakes);
    game.setLadders(ladders);
    game.setPlayers(players.size(), players);
    game.play();

return 0;
}