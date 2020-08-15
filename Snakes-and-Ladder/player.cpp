#include <string>
using namespace std;

class Player{
    private:
        string name;
        int pos;
    public:
        Player(string playername){
            name = playername;
            pos = 0;
        }
        int getPos(){
            return pos;
        }
        void setPos(int new_position){
            pos = new_position;
        }
        string getName(){
            return name;
        }
};