#include <iostream>

using namespace std;

int main(){
    int score = 0;
    string name;

    do{
        cout << "Enter a name and score ";
        cin >> name >> score;

        if(score > 100 || score < 0){
            cout << "Bye " << name << endl;
        }else if(score >= 90){
            cout << "Hi " << name << "! Your grade is A" << endl;
        }else if(score >= 80){
            cout << "Hi " << name << "! Your grade is B" << endl;
        }else if(score >= 70){
            cout << "Hi " << name << "! Your grade is C" << endl;
        }else if(score >= 60){
            cout << "Hi " << name << "! Your grade is D" << endl;
        }else{
            cout << "Hi " << name << "! Your grade is F" << endl;
        }
    }while(score <= 100 && score >= 0);

    return 0;
}