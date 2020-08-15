#include <iostream>
using namespace std;

class Shape{
    protected:
        int height;
        int width;
    public:
        Shape(int h, int w){
            height = h;
            width = w;
        }

        //1. without "virtual" getArea() will be statically linked
        //2. if getArea() is not in base class, then shape ptr will give error
        //on this method
        virtual int getArea(){
            cout << "Base class Area" << endl;
            return 0;
        }

        //Pure abstraction using pure virtual method. 
        //This make the class an abstract class
        // virtual int getAreaPure() =0;
};

class Rectange:public Shape{
    public:
        Rectange(int a, int b):Shape(a,b){

        }
        int getArea(){
            cout << "Rectange Area" << endl;
            return height * width;
        }
};

class Triangle:public Shape{
    public:
        Triangle(int a, int b):Shape(a,b){}

        int getArea(){
            cout << "Triangle Area" << endl;
            return (height*width)/2.0; 
        }
};

int main(){
    Rectange rect = Rectange(2,3);
    int area = rect.getArea();
    cout << area << endl;

    Triangle triangle = Triangle(2,3);
    int triangle_area = triangle.getArea();
    cout << triangle_area << endl;

    Shape* shape;
    shape = &rect;
    cout << shape->getArea() << endl;

    shape = &triangle;
    cout << shape->getArea() << endl;

    Shape shape_err(5,2);
    cout << shape_err.getArea() << endl;
    return 0;
}