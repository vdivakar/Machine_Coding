#include <iostream>
#include <string>
using namespace std;


//This in an Abstract class
class Animal{
    private:
        int legs;
    public:
        void setLegs(int l=0){
            legs = l;
        }
        int getLegs(){
            return legs;
        }
        virtual string getSound()=0;

        bool isFly();

};

//Methods can also be defined outside class
//Similarly Constructors can also be defined outside
bool Animal::isFly(){
    return false;
}

//This needs to implement all the virtual functions
class Dog:public Animal{
    public:
        Dog(int l){
            setLegs(l);
        }
        string getSound(){
            return "Bark!!";
        }
        // bool isFly(){
        //     return true;
        // }
};

int main(){
    Dog dog(4);
    cout << dog.getSound() << endl;
    cout << dog.getLegs() << endl;

    //error creating object of abstract class
    Dog animal = Dog(2);
    cout << animal.isFly() << endl;
    return 0;
}