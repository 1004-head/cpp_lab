#include <iostream>

using namespace std;

long func(long x){
    int result = 0;
    if(x == 1){
        return 0;
    }else{
        result += func(x-1);
    }
    return result;
}

int main()
{
    
    cout << func(5) << endl;

    return 0;

}