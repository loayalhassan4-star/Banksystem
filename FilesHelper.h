#pragma once
#include<string>
#include<fstream>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include"Parser.h"
using namespace std;
class FilesHelper
{
public:
	static void Savelast(string filename, int id)
	{
		ofstream file (filename);
		file << id;
		file.close();
	}
	static int getLast(string filename)
	{
		ifstream file(filename);
		int id = 0;
		file >> id;
		file.close();
		return id;
	}
	static void saveClient(Client c)
	{ 
		int id =getLast("Clientlastid.txt");
		ofstream file("Clients.txt", ios::app);
		{
			file << id+1 << "&" << c.getname() << "&" << c.getpassword() << "&" << c.getbalance() << endl;
			file.close();
			Savelast("Clients.txt", id+1);
		}
	}
	static void saveEmployee(string filename,string lastidfile, Employee e)
	{
		int id=getLast("Employeelastid.txt");
		ofstream file(filename,ios::app);
		file << id+1 << "&" << e.getname() << "&" << e.getpassword() << "&" << e.getsalary() << endl;
		file.close();
		Savelast( lastidfile,id+1);
	}
	static void getClients()
	{
		ifstream file("Clients.txt");
		string line;
		while (getline(file, line))
		{
			Client c = Parser::parseToClient(line);
			clients.push_back(c);
		}

		file.close();
		
	}
	static void getEmployee()
	{
	
		ifstream file("Employees.txt");
		string line;
		while (getline(file, line))
		{
			Employee e= Parser::parseToEmployee(line);
			employees.push_back(e);
		}
		file.close();
	}
	static void getAdmins()
	{

		ifstream file("Admins.txt");
		string line;
		while (getline(file, line))
		{
			Admin a = Parser::parseToAdmin(line);
			admins.push_back(a);
		}
		file.close();
	}
	static void Clearfile(string filename, string lastfileid)
	{
		ofstream file(filename, ios::trunc);
		file.close();
		Savelast(lastfileid , 0);
	}
};

