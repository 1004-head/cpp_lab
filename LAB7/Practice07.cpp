# include <iostream>
# include <string>
# include <cstring>

using namespace std ;

class MyString {
	char* str ;
	int size ;
public:
	MyString(const char* const s="") {
		set(s);
	}
	MyString(const MyString& myString) {
		set(myString.str);
	}
	~MyString() {
		delete [] str;
	}
	void set(const char* const s) {
		size = strlen(s);
		str = new char[size+1];
		strcpy(str, s);
	}
	bool isEqual(const MyString& myString) const {
		const bool same = (size == myString.size && strcmp(str, myString.str) == 0) ;
		return same;
	}
	void print() const {
		cout << str << endl;
	}
} ;


int main() {
	MyString strs[] = {
		MyString("C"),
		MyString(),
		MyString("Java")
	} ;
	strs[1].set("C++") ;

	const int arraySize = sizeof(strs) / sizeof(MyString);

	const MyString target("Java") ;
	for ( int i = 0 ; i < arraySize ; i ++ ) {
		const MyString str(strs[i]) ;
		if ( str.isEqual(target) ) {
			cout << "[" << i << "]: " ;
			str.print() ;
			break ;
		}
	}

	for ( const MyString& str : strs ) {
		str.print() ;
	}
}

