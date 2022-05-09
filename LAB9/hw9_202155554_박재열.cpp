#include <iostream>
#include <vector>

using namespace std;

enum EmployeeLevel { 사원, 대리, 과장, 차장, 부장 };

class Employee {
	string name;
	const EmployeeLevel level;
public:
	Employee(string inputName, EmployeeLevel inputLevel)
		:level(inputLevel){
		name = inputName;
	}
	string gettername() const{
		return name;
	}

	EmployeeLevel getterlevel() const{
		return level;
	}

	friend ostream& operator << (ostream& os, const Employee& employee);
};

class Manager : public Employee {
	vector<Employee*> group;
public:
	Manager(string managerName, EmployeeLevel managerEmployee)
		:Employee(managerName, managerEmployee)	{}

	void addEmployee(Employee* classEmployee){
		group.push_back(classEmployee);
	}

	friend ostream& operator << (ostream& os, const Manager& manager);
};

ostream& operator << (ostream& os, const Employee& employee){
	os << employee.level << "\t" << employee.name << endl;
	return os;
}

ostream& operator << (ostream& os, const Manager& manager){
	os << manager.getterlevel()<< "\t" << manager.gettername() << endl;
    cout << "List of employees managed by me" << endl;
	
    for (int i = 0; i < manager.group.size(); i++){
		os << manager.group[i]->getterlevel() << '\t' << manager.group[i]->gettername() << endl;
	}

	return os;
}

int main() {
	Employee e1("홍", 사원), e2("김", 대리), e3("차", 사원);
	cout << e1 << e2 << e3;
    
	Manager m1("Tom", 차장);
	m1.addEmployee(&e1);
	m1.addEmployee(&e2);
	m1.addEmployee(&e3);
	cout << endl << "Information for Manager" << endl;
	cout << m1;
}