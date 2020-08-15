#include <iostream>
//#include <stdio.h>

using namespace std;

class Shape{
	private:
		int width;
		int height;
	public:
		void setWidth(int w){
			width = w;
		}
		void setHeight(int h){
			height = h;
		}
		int getWidth(){
			return width;
		}
		int getHeight(){
			return height;
		}
};

class PaintCost{
	public:
		int getPaintCost(int area){
			return area*1000;
		}
};

// Multiple inheritance possible
class Rectangle:public Shape, public PaintCost{
	public:
		int getArea(){
			return getWidth()*getHeight();
		}
};

int main(){
	cout << "Testing Rectangle Class" << endl;
	Rectangle rect = Rectangle();
	rect.setWidth(9);
	rect.setHeight(10);
	int area = rect.getArea();
	cout << area << endl;

	cout << rect.getPaintCost(area) << endl;

	return 0;
}
