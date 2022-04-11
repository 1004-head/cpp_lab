#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
	private:
		string name ="";
		float gpa = 0.0;
	public:
		void getName(string getName){
			name = getName;
		}
		void getGpa(float getGpa){
			gpa = getGpa;
		}
		string getterName(){
			return name;
		}
		float getterGpa(){
			return gpa;
		}
		void setName(string setName){
			name = setName;
		}
		void setGPA(float setGpa){
			gpa = setGpa;
		}
};

class School {
	private:
		string schoolName;
		vector<Student> students;
	public:
		int studentNum = 0;
		School(string inputSchool){
			schoolName = inputSchool;
		}
		void addStudent(string inputName, float inputScore = 0.0){
			Student student;
			student.getName(inputName);
			student.getGpa(inputScore);
			students.push_back(student);
			studentNum++;
		}
		void print(){
			vector <Student>::iterator it;
			cout << "School Name: " << schoolName << ", Count: " << studentNum  << endl;
			for (it = students.begin(); it != students.end(); it++){ 
				cout << "\tName: " << it->getterName() << "\tGPA: " << it->getterGpa() << endl;
			}
		}
		Student& findStudentWithName(string findName){
			vector <Student>::iterator it;
			for (it = students.begin(); it != students.end(); it++){
				if (it->getterName() == findName){
					return *it;
				}
			}
			cout << "Error" << endl;
		}
		void sort(){
			int i = 0;
			int j = 0;
			vector <Student>::iterator it1, it2;
			for (it1 = students.begin(); it1 != students.end()-1; it1++){
				j = i + 1;
				for (it2 = students.begin()+1; it2 != students.end(); it2++){
					if (it1->getterGpa() < it2->getterGpa()){
						swap(students[i], students[j]);
					}
					j++;
				}
				i++;
			}
		}

};


int main() {
	School pnu("PNU");
	
	pnu.addStudent("Kim", 2.7F);
	pnu.addStudent("Hong", 3.5F);
	pnu.addStudent("Lee");
	pnu.addStudent("Joo", 1.5F);
	
	pnu.print();
	
	pnu.sort(); // descending
	pnu.print();
	
	School knu("KNU");
	knu.addStudent("Seo", 2.5F);
	knu.addStudent("Lee", 3.8F);
	knu.print();
	
	Student& lee = pnu.findStudentWithName("Lee");
	lee.setGPA(3.3F);
	lee.setName("Yoon");
	
	pnu.print();
	
	knu.addStudent("Hong", 4.3F);
	Student& hong = knu.findStudentWithName("Hong");
	hong.setGPA(3.3F);
	hong.setName("Joon");
	knu.print();
}