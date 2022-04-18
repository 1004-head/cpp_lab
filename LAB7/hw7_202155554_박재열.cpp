#include <iostream>
#include <cstring>

using namespace std;

class MyString {
    char *str;
    int size;

public:
    MyString() {}

    MyString(const MyString& myString)
        :size(myString.size),str(new char[myString.size]) {
        for (int i = 0; i < size; i++){
            str[i] = myString.str[i];
        }
    }

    MyString(const char* checkString) {
        str = new char[strlen(checkString)];
        size = strlen(checkString);
        for (int i = 0; i < size; i++){
            str[i] = checkString[i];
        }
    }

    void set(const char* setString) {
        str = new char[strlen(setString)];
        size = strlen(setString);
        for (int i = 0; i < size; i++){
            str[i] = setString[i];
        }
    }

    void print() const {
        for (int i = 0; i < size; i++){
            cout << str[i];
        }
        cout << endl;
    }

    bool isEqual(const MyString& myString) const {
        int cnt = 0;
        if (size == myString.size) {
            for (int i = 0; i < size; i++) {
                if (str[i] == myString.str[i]) {
                    cnt++;
                }
            }
            
            if (cnt == size) {
                return 1;
            }
        } else {
            return 0;
        }
    }

    ~MyString() {}
};

int main() {
    MyString strs[] = {
        MyString("C"),
        MyString(),
        MyString("Java")
    };
    strs[1].set("C++");

    const int arraySize = sizeof(strs) / sizeof(MyString);

    const MyString target("Java");
    for (int i = 0; i < arraySize; i++){
        const MyString str(strs[i]);
        if (str.isEqual(target))
        {
            cout << "[" << i << "]: ";
            str.print();
            break;
        }
    }
    for(const MyString& str : strs){
        str.print();
    }
}