#pragma once
#include "Employee.h"
using namespace std;
class Admin : public Employee
{
public:
	Admin(int id, string name, string password, double salary) :Employee(id, name, password, salary) {};
	void addEmployee(Employee& e)
	{
		employees.push_back(e);
	}
	Employee* searchEmployee(int id)
	{
		for ( Employee &e : employees)
		{
			if (e.getid() == id)
			{
				return &e;
			}
		}
		return nullptr;
	}
	void editEmployee(int id, string name, string password, double salary)
	{
			searchEmployee(id)->setid(id);
			searchEmployee(id)->setname(name);
			searchEmployee(id)->setpassword(password);
			searchEmployee(id)->setsalary(salary);
	}
	void listEmployee()
	{
		for (Employee& e : employees)
		{
			e.display();
			cout << endl;
		}
	}
	
};

static vector<Admin> admins;
vector<Admin>::iterator ait;