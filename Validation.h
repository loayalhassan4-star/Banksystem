#pragma once
#include<string>
#include<iostream>
using namespace std;
class Validation
{
public:
	static bool validatename(const string& name)
	{
		if (name.length() < 3 || name.length() > 20)
		{	return false;
		}
		for (int i = 0; i < name.length();i++)
		{
			char c = name[i];
			if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
				return false; 
		}
		return true;
		
	}
	static string entername()
	{
		string name;
		cin >> name;
		while (!validatename(name))
		{
			cout << "Invalid name \n";
			cout << "Name must be between 3 and 20 characters \n";
			cout << "Enter name" << endl;
			cin >> name;
		}
		return name;
	}
	static bool validatepassword(const string& password)
	{
		if (password.length() < 8 || password.length() > 20)
		{
			return false;
		}
		for (int i = 0; i < password.length(); i++)
		{
			if (password[i] == ' ')
			{
				return false;
			}
		}
		return true;
	}
	static string enter_password()
	{
		string password;
		cin >> password;
		while (!validatepassword(password))
		{
			cout << "Invalid password \n";
			cout << "Name must be in range between 8 and 20  \n";
			cout << "Enter password" << endl;
			cin >> password;
		}
		return password;
	}
	static bool validatebalance(double balance)
	{
		if (balance < 1500)
		{
			cout << "balance is less than 1500" << endl;
			return false;
		}
		return true;
		
	}
	static double enterbalance()
	{
		double balance;
		cin >> balance;
		while (!validatebalance(balance))
		{
			cout << "Invalid balance" << endl;
			cout << "Enter balance: " << endl;
			cin >> balance;
		}
		return balance;
	}
	static bool validateSalary(double salary)
	{
		if (salary < 5000)
		{
			cout << "Salary is less than min" << endl;
			return false;
		}
		return true;
	}
	static double enterSlary()
	{
		double salary;
		cin >> salary;
		while (!validateSalary(salary))
		{
			cout << "Invalid amount" << endl;
			cout << "Enter amount: " << endl;
			cin >> salary;
		}
		return salary;
	}
};

