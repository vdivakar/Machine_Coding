#include <iostream>
using namespace std;

class Adder{
    private:
        //Abstraction. Hidden from the outside world
        int total;
    public:
        Adder(int i=0){
            total = i;
        }
        
        void add(int a){
            total+=a;
        }

        int getTotal(){
            return total;
        }
};

int main(){
    Adder adder(10);
    adder.add(4);
    adder.add(6);

    cout << adder.getTotal() << endl;

    return 0;
}