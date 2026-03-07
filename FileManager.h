#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"
#include<iostream>
using namespace std;
class FileManager :public DataSourceInterface
{ 

	 void addClient(Client& obj) override
	{
		int lastID = FilesHelper::getLast("Clientlastid.txt");
		int newId = lastID + 1;
		obj.setid(newId);
		FilesHelper::saveClient(obj);
	}
	void addEmployee(Employee& obj) 
	{
		int lastID = FilesHelper::getLast("Employeelastid.txt");
		int newId = lastID + 1;
		obj.setid(newId);
		FilesHelper::saveEmployee("Employees.txt", "Employeelastid.txt", obj);
	}
	void addAdmin(Admin& obj) 
	{
		int lastID = FilesHelper::getLast("Adminlastid.txt");
		int newId = lastID + 1;
		obj.setid(newId);
		FilesHelper::saveEmployee("Admin.txt", "Adminlastid.txt", obj);
	}
	void getallClients() override
	{
		FilesHelper::getClients();
	}
	void getallEmployees() override
	{
		FilesHelper::getEmployee();
	}
	void getallAdmins() override
	{
		FilesHelper::getAdmins();
	}
	 void removeallClients() override
	{
		FilesHelper::Clearfile("Clients.txt", "Clientlastid.txt");
	}
	void removeallEmployees() override
	{
		FilesHelper::Clearfile("Employees.txt", "Employeelastid.txt");
	}
	void removeallAdmins() override
	{
		FilesHelper::Clearfile("Admin.txt", "Adminlastid.txt");
	}
public:
	 void updateClients() {
		removeallClients();
		for (cit = clients.begin(); cit != clients.end(); cit++) addClient(*cit);
	}

	void updateEmployees() {
		removeallEmployees();
		for (eit = employees.begin(); eit != employees.end(); eit++) addEmployee(*eit);
	}

	 void updateAdmins() {
		removeallAdmins();
		for (ait = admins.begin(); ait != admins.end(); ait++) addAdmin(*ait);
	}
};


