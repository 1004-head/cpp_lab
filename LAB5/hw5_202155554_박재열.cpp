#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

struct Rectangle {
	int width;
	int height;
};

enum CommandKind { ADD, SORT, PRINT, CLEAR, EXIT, INVALID };

void sort(vector<Rectangle>& rec) {
	for (int i = 0; i < rec.size(); i++) {
		for (int j = i + 1; j < rec.size(); j++) {
			int area1 = rec[i].width * rec[i].height;
			int area2 = rec[j].width * rec[j].height;
			if (area1 > area2) {
				swap(rec[i], rec[j]);
			}
		}
	}
}

void print(const vector<Rectangle>& rec){
	vector<Rectangle> recs = rec;
	vector <Rectangle>::iterator it;
	
	cout << "Rectangle Count: " << recs.size() << endl;
	for (it = recs.begin(); it != recs.end(); it++)
	{
		int RectArea = it->width * it->height;
		cout << "\t" << it->width << "\t" << it->height << "\t" << RectArea << endl;
	}
}

Rectangle getRectangle() {
	Rectangle rec;
	int a = 0;
	int b = 0;
	cin >> a;
	cin >> b;
	rec.width = a;
	rec.height = b;
	return rec;
}

CommandKind getCommandKind(string getString) {
	vector <CommandKind> vectorCommand;
	vectorCommand = { ADD, SORT, PRINT, CLEAR, EXIT, INVALID };
	if (getString == "ADD")
		return vectorCommand[0];
	else if (getString == "SORT")
		return vectorCommand[1];
	else if (getString == "PRINT")
		return vectorCommand[2];
	else if (getString == "CLEAR")
		return vectorCommand[3];
	else if (getString == "EXIT")
		return vectorCommand[4];
	else if (getString == "INVALID")
		return vectorCommand[5];
}

int main() {
	vector<Rectangle> rectangles;
	
	while (true) {
		string commandString;
		cin >> commandString;
		const CommandKind command = getCommandKind(commandString);
		switch (command) {
			case ADD: {
				const Rectangle& newRectangle = getRectangle();
				rectangles.push_back(newRectangle);
				break;
			}
			case PRINT: {
				print(rectangles);
				//use const_iterator in print()
				//define and call print(const vector<Rectangle>&)
				break;
			}
			case SORT: {
				sort(rectangles); //define and call swap in sort()
				print(rectangles);
				break;
			}
			case CLEAR: rectangles.clear();	break;
			case EXIT: break;
			default: assert(false); break;
		}
		if (command == EXIT) break;
	}

	return 0;
}
