#pragma once
#include "Person.h"
#include<iostream>
#include<vector>
using namespace std;
class Client :public Person
{
	double balance;
public:
	Client() : Person(), balance(0)  {};
	Client(int id, string name, string password, double balance) :Person(id, name, password), balance(balance) {};
	void setbalance(double balance)
	{
			this->balance = balance;

	}
	double getbalance()
	{
		return balance;
	}
	void deposit(double amount)
	{
		if (amount > 0)
			balance += amount;
	}
	void withdraw(double amount)
	{
		if (amount > 0 && balance - amount >= 1500)
		{
			balance -= amount;
		}
		else
		{
			cout << "Withdraw failed: insufficient balance" << endl;
		}
	}
	void transferto(double amount, Client& recipient)
	{
		if (amount > 0 && balance - amount >= 1500)
		{
			balance -= amount;
			recipient.balance += amount;
		}
	}
	void checkbalance()
	{
		cout << "Balance: " << balance << endl;
	}
	void display()
	{
		Person::display();
		cout << "Balance: " << balance << endl;
	}
	
	
};

static vector<Client>clients;
vector<Client>::iterator cit;