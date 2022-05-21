#include <iostream>
#include <vector>

using namespace std;

enum Color { RED, BLUE, YELLOW };

class Shape {
	Color lineColor;
public:
	Color getLineColor() const { return lineColor; }
	virtual Shape* clone() const = 0;
	virtual void print() const = 0;
	virtual float getLength() const = 0;
};

class ClosedShape : public Shape {
public:
	virtual Shape* clone() const = 0;
	virtual void print() const = 0;
	virtual float getLength() const = 0;
};

class Polygon : public ClosedShape {
public:
	virtual Shape* clone() const = 0;
	virtual void print() const = 0;
	virtual float getLength() const = 0;
};

class Point {
	int pointX;
	int pointY;
public :
	Point(int inputX =0, int inputY = 0) {
		pointX = inputX;
		pointY = inputY;
	}
	void print_point() const {
		cout << "(" << pointX << "," << pointY << ")";
	}
	int get_x() const {
		return pointX;
	}
	int get_y() const {
		return pointY;
	}
};

class Rectangle : public Polygon {
	Point p1, p2, p3, p4;
public :
	Rectangle(const Point& p_1, const Point& p_2, const Point& p_3, const Point& p_4) {
		p1 = p_1;
		p2 = p_2;
		p3 = p_3;
		p4 = p_4;
	}
	Shape* clone() const {
		Shape* newRectangle = new Rectangle(p1,p2,p3,p4);
		return newRectangle;
	}

	void print() const {
		cout << "Rectangle: ";
		p1.print_point();
		p2.print_point();
		p3.print_point();
		p4.print_point();
		cout << endl;
    }

	float getLength() const {
		float a = (p3.get_x() - p1.get_x()) * (p3.get_y() - p2.get_y());
		return a;
	}
};

class Triangle : public Polygon {
	Point p1, p2, p3;
public:
	Triangle(const Point& p_1, const Point& p_2, const Point& p_3) {
		p1 = p_1;
		p2 = p_2;
		p3 = p_3;
	}
	Shape* clone() const {
		Shape* newTriangle = new Triangle(p1, p2, p3);
		return newTriangle;
	}
	void print() const {
		cout << "Triangle: ";
		p1.print_point();
		p2.print_point();
		p3.print_point();
		cout << endl;
	}
	float getLength() const {
		float a = (p3.get_x() - p1.get_x()) * p2.get_y() / 2;
		return a;
	}
};

class ShapeList {
	vector <Shape*> vecShape;
public:
	void addShape(Shape* s1) {
		vecShape.push_back(s1->clone());
	}
	void print() {
		for (int i = 0; i < vecShape.size(); i++)
			vecShape[i]->print();
	}
	float getTotalArea() {
		float totalArea = 0;
		for (int i = 0; i < vecShape.size(); i++) {
			totalArea += vecShape[i]->getLength();
		}
		return totalArea;
	}
};

int main() {
	Point p1(0, 0), p2(0, 10), p3(20, 20), p4(20, 30);
	
    Shape* const r = new Rectangle(p1, p2, p3, p4);
	Shape* const t = new Triangle(p1, p2, p3);
	
    ShapeList list{};
	list.addShape(r);
	list.addShape(t);
	delete r;
	delete t;
	
    list.print();
	cout << list.getTotalArea() << endl;
}
