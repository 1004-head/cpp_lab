#include <iostream>
#include <vector>
using namespace std;

const int SUBJECT_NO = 3;

struct StudentInfo {
	string name;
    int scores[SUBJECT_NO] = { 0, };
	int sum = 0;
	float average = 0;
};

void printStudent(const StudentInfo& student, const int n, int i) {
    
    cout << i + 1 << "\t";
    cout << student.name << "\t";

    for (int subject = 0; subject < n; subject++){
        cout << student.scores[subject] << "\t";
    }

    cout << student.sum << "\t" << student.average << endl;
}

void printStudentVector(vector<StudentInfo> students, const int num){
    
    vector<StudentInfo>::iterator studentIterator;
    
    int i = 0;
    for (studentIterator = students.begin(); studentIterator != students.end(); studentIterator++){
        printStudent(*studentIterator, SUBJECT_NO, i);
        i++;
    }

    int sum0 = 0;
    int sum1 = 0;
    int sum2 = 0;

    for (int j=0;j<num;j++){
        sum0 = sum0 + students[j].scores[0];
        sum1 = sum1 + students[j].scores[1];
        sum2 = sum2 + students[j].scores[2];
    }

    cout << "Total" << "\t\t" << sum0 << "\t" << sum1 << "\t" << sum2 << "\t" << sum0 + sum1 + sum2;
}

int main(){

	int studentNum;
	cin >> studentNum;

	vector <StudentInfo> students;
	StudentInfo student;

	for (int i = 0; i < studentNum; i++){
        
		cin >> student.name >> student.scores[0] >> student.scores[1] >> student.scores[2];
        		
        student.sum = student.scores[0] + student.scores[1] + student.scores[2];
        student.average = float(student.sum) / SUBJECT_NO;

        students.push_back(student);
	}

    printStudentVector(students, studentNum);

    return 0;

}