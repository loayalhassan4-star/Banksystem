#pragma once
#include<string>
#include"Validation.h"
using namespace std;
class Person
{
protected:
	int id;
	string name,password;
public:
	Person() : id(0), name(""), password("") {};
	Person(int id, string name, string password) :id(id), name(name), password(password) {};
	void setname(const string& name)
	{
		this->name = name;
	}
	void setpassword(string password)
	{
		this->password = password;
	}
	void setid(int id)
	{
		this->id = id;
	}
	string getname()
	{
		return name;
	}
	string getpassword()
	{
		return password;
	}
	int getid()
	{
		return id;
	}
	void display()
	{
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
	}
};

