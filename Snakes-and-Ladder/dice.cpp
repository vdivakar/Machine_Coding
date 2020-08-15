#include <iostream>
#include <time.h>
using namespace std;

class Dice{
    public:
        Dice(int seed=time(0)){
            srand(seed);
        }
        int roll(){
            return rand()%6 + 1;
        }
};