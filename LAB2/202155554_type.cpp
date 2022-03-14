#include <iostream>
#include <limits>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char **)
{
    string typeString;
    int charCount = 0, intCount = 0, longCount = 0, floatCount = 0, doubleCount = 0;

    do{
        cin >> typeString;
        transform(typeString.begin(), typeString.end(), typeString.begin(), ::tolower);

        if(typeString == "char"){
            cout << numeric_limits<char>::min() << " " << numeric_limits<char>::max() << endl;
            charCount++;
        }
        if(typeString == "int"){
            cout << numeric_limits<int>::min() << " " << numeric_limits<int>::max() << endl;
            intCount++;
        }
        if(typeString == "long"){
            cout << numeric_limits<long>::min() << " " << numeric_limits<long>::max() << endl;
            longCount++;
        }
        if(typeString == "float"){
            cout << numeric_limits<float>::min() << " " << numeric_limits<float>::max() << endl;
            floatCount++;
        }
        if(typeString == "double"){
            cout << numeric_limits<double>::min() << " " << numeric_limits<double>::max() << endl;
            doubleCount++;
        }

    }while(typeString != "quit");

    cout << "=== A List of # of types ===" << endl;
    cout << "int:" << intCount << endl;
    cout << "long:" << longCount << endl;
    cout << "float:" << floatCount << endl;
    cout << "double:" << doubleCount << endl;
    cout << "char:" << charCount << endl;

}