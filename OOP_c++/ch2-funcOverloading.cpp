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

class Rectangle:public Shape, public PaintCost{
	public:
		int getArea(){
			return getWidth()*getHeight();
		}
		int getPaintCost(){
			return (-100);
		}
		int getPaintCost(int area){
			return area * 10;
		}
		int getPaintCost(float area){
			return area*1.5;
		}
};

int main(){
	cout << "Testing Rectangle Class" << endl;
	Rectangle rect = Rectangle();
	rect.setWidth(9);
	rect.setHeight(10);
	cout << rect.getArea() << endl;
	int area = rect.getArea();
	int cost = rect.getPaintCost((float)area);
	cout << "Rs. " << cost << endl;

	return 0;
}
