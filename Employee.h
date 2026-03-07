#pragma once
#include "Person.h"
#include "Client.h"
#include <vector>
#include<iostream>
class Employee :public Person
{
	double salary;
public:
	Employee() {};
	Employee(int id, string name, string password, double salary) :Person(id, name, password), salary(salary) {};
	
	void setsalary(double salary)
	{
		if(Validation::validateSalary(salary))
		this->salary = salary;
	}
	double getsalary()
	{
		return salary;
	}
	void display()
	{
		Person::display();
		cout << "Salary: " << salary << endl;
	}
	void addClient(Client& client)
	{
		clients.push_back(client);
	}
	Client* searchClient(int id)
	{
		for (auto &c : clients)
		{
			if (c.getid() == id)
			{
				return &c;
			}
		}
		return nullptr;
	}
	void editClient(int id, string name, string password, double balance)
	{
		searchClient(id)->setid(id);
		searchClient(id)->setname(name);
		searchClient(id)->setpassword(password);
		searchClient(id)->setbalance(balance);
	}
	void listClient()
	{
		for (auto c : clients)
		{
			c.display();
			cout << endl;
		}
	}
};
static vector<Employee> employees;
vector<Employee>::iterator eit;
