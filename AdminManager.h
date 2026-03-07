#pragma once
#include "Admin.h"
#include "FileManager.h"
#include <iostream>
using namespace std;
#include"EmployeeManager.h"
class AdminManager
{
public:
	static void printEmployeeMenu()
	{
		cout << "1- Display my ifo: " << endl;
		cout << "2- Update password " << endl;
		cout << "3- Add new client: " << endl;
		cout << "4- Search for client: " << endl;
		cout << "5- List all clients: " << endl;
		cout << "6- Edit client info: " << endl;
		cout << "7- Add new Employee: " << endl;
		cout << "8- Search for employee: " << endl;
		cout << "9- List all employees: " << endl;
		cout << "10- Edit employee info: " << endl;
		cout << "11- Logout";
	}
	static Admin* login(int id, string password)
	{
		for (auto a : admins)
		{
			if (a.getid() == id && a.getpassword() == password)
				return &a;
		}
		return nullptr;
	}
	static void newEmployee(Admin* admin)
	{
		Employee e;
		e.setid(FilesHelper::getLast("Employeelastid.txt")+1);
		e.setname(Validation::entername());
		e.setpassword(Validation::enter_password());
		e.setsalary(Validation::enterSlary());
		admin->addEmployee(e);
		cout << "\n Added successfully \n";
	}
	static void Searchemployee(Admin* admin)
	{
		int id;
		system("cls");
		cout << "Enter Employee id: ";
		cin >> id;
		if (admin->searchEmployee(id) == nullptr) cout << "\nEmployee not found\n";
		else admin->searchEmployee(id)->display();

	}
	static void editEmployee(Admin* admin)
	{
		int id;
		cout << "Enter Employee id: ";
		cin >> id;
		if (admin->searchEmployee(id) == nullptr) cout << "\n Employee not fount \n";
		else
		{
			string name = Validation::entername();
			string password = Validation::enter_password();
			double salary = Validation::enterSlary();
			admin->editEmployee(id, name, password , salary);
			cout << "\nEmployee Added successfully\n";
		}
	}
	static bool AdminOptions(Admin* admin)
	{
		int choice;
		printEmployeeMenu();
		cin >> choice;


		switch(choice)
		{
		case 1:
		{
			system("cls");
			admin->display();
			break;
		}
		case 2:
		{
			ClientManager::Updatepassword(admin);
			FileManager f;
			f.updateClients();
			break;
		}
		case 3:
		{
			EmployeeManager::newClient(admin);
			FileManager f;
			f.updateClients();
			break;
		}
		case 4:
		{
			EmployeeManager::searchclient(admin);
		}
		case 5:
		{
			EmployeeManager::listallclients(admin);
			break;
		}
		case 6:
		{
			EmployeeManager::editClientInfo(admin);
			FileManager f;
			f.updateClients();
			break;
		}
		case 7:
		{
			newEmployee(admin);
			FileManager f;
			f.updateClients();
			break;
		}
		case 8:
		{
			Searchemployee(admin);
			break;
		}
		case 9:
		{
			admin->listEmployee();
			break;
		}
		case 10:
		{
			editEmployee(admin);
			FileManager f;
			f.updateClients();
		}
		case 11:
		{
			return false;
		}
		}
		return true;

	}
};
