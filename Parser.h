#pragma once
#include<vector>
#include<string>
#include<sstream>
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
using namespace std;
class Parser
{
public:
	static vector<string>split(string line)
	{
		vector<string> myvalues;
		stringstream ss(line);
		string items;
		while (getline(ss, items , '&'))
		{
			myvalues.push_back(items);
		}
		return myvalues;

	}
	
	static Client parseToClient(string line)
	{
		vector<string> Cparts = split(line);
		return Client(stoi(Cparts[0]), Cparts[1], Cparts[2], stod(Cparts[3]));
	}
	static Employee parseToEmployee(string line)
	{
		vector<string>Eparts = split(line);
		return Employee(stoi(Eparts[0]), Eparts[1], Eparts[2], stod(Eparts[3]));
	}
	static Admin parseToAdmin(string line)
	{
		vector<string> Aparts = split(line);
		return Admin(stoi(Aparts[0]), Aparts[1], Aparts[2], stod(Aparts[3]));
	}

};

