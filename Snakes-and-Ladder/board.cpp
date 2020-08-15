#include <vector>
using namespace std;

class Board{
    private:
        int size;
        vector<int> board;

    public:
        Board(int s=100){
            size = s;
            board = vector<int>(s+1, 0);
        }
        void setValue(int idx, int val){
            board[idx] = val;
        }
        int getValue(int idx){
            return board[idx];
        }
        int getBoardSize(){
            return size;
        }
};