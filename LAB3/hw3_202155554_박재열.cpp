#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

char toLowerCase(const char ch) {
	char lowerCh;
	if ( ch >= 'A' && ch <= 'Z') // portability
		lowerCh = ch + ( 'a' - 'A' );
	else
		lowerCh = ch;
	return lowerCh;
}
string toLowerCase(const string& str) { // stack
	string lowerCase{str}; // copy constructor
	for ( int i{0}; i < str.length(); i ++ ) {
		const char ch = str.at(i);
		
		lowerCase[i] = toLowerCase(ch);
	}
	return lowerCase;
}

int main()
{
	cout << "Enter the score count: ";
	int maxSize ;
	cin >> maxSize;

	int* const scores = new int[maxSize];
   	int i = 0;
    int sum = 0;
    float average = 0;
	
    while (1){
		string inputString;
		cout << "Enter command: (add,sum,average,quit) ";
		cin >> inputString;

        inputString = toLowerCase(inputString);
		
		if (inputString == "add"){
			if (i < maxSize){
                cout << "Enter score: " ;
				int inputNum = 0;
				cin >> inputNum;
				if (inputNum < 100 && inputNum > 0){
					scores[i] = inputNum;
         
                    cout << "   " << scores[i] << " added" << endl;
                    i++;
				}else
					cout << "Scores should be between 0 and 100" << endl;
			}else
                cout << "Too many scores" << endl;
		}
        
        if (inputString == "sum"){
			sum = 0;
			for (int j = 0; j < i; j++){
				sum = sum + scores[j];
			}

            cout << "   Sum: "<< sum << endl;
        }
        
        if (inputString == "average"){
            average = (float)sum / i;
            cout << "   Average :" << average << endl;
        }

        if (inputString == "list"){
            int j;
            for(j = 0; j < i-1; j++){
                cout << scores[j] << ", ";
            }
            cout << scores[j] << endl;
        }
        
        if (inputString == "quit"){
            delete[] scores;
            cout << "   Bye" << endl;
            break;
        }

	}
    return 0;
}