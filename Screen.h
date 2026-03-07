#pragma once
#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>
#include "AdminManager.h"
using namespace std;
class Screen
{
	static void setColor(int color)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}
public:
	static void blinkTitle()
	{
		for (int i = 0; i < 3; i++)
		{
			system("cls");
			this_thread::sleep_for(chrono::milliseconds(300));

			cout << "\n\n\tLOAY BANK SYSTEM";
			this_thread::sleep_for(chrono::milliseconds(300));
		}
	}
	static void loading()
	{
		setColor(10);
		cout << "\n\tLoading";

		for (int i = 0; i < 5; i++)
		{
			cout << "." << flush;
			this_thread::sleep_for(chrono::milliseconds(400));
		}

		setColor(7);
		system("cls");
	}
	static void typeEffect(string text, int delay = 50)
	{
		for (char c : text)
		{
			cout << c << flush;
			this_thread::sleep_for(chrono::milliseconds(delay));
		}
	}
	static void Bankname()
	{
		

		cout << "\n\n\t\t   WELCOME TO LOAY BANK\n\n";

		system("pause");
	}
	static void Welcome()
	{
		setColor(14); 
		cout << "\t        Welcome To Our Bank\n\n";
		setColor(7);
	}
	static void loginOptions()
	{
		setColor(10); 
		cout << "\t1- Client Login\n";
		cout << "\t2- Employee Login\n";
		cout << "\t3- Admin Login\n";
		cout << "\t0- Exit\n\n";
		setColor(7);
	}
	static int  loginAs()
	{
		int choice;
		cout << "Enter choice: ";
		cin >> choice;
		return choice;
	}
	static void invalid(int choice)
	{
		setColor(12); 
		cout << "\n\tInvalid Option!\n";
		setColor(7);
		system("pause");

	}
	static void logout()
	{
		setColor(13); 
		cout << "\n\tLogged Out Successfully!\n";
		setColor(7);
		system("pause");
	}
	static void loginscreen(int choice)
	{
		system("cls");
		int id;
		string pass;
		cout << "Enter ID: " << endl;
		cin >> id;
		cout << "Enter Password: " << endl;
		cin >> pass;
		if (choice == 1)
		{
			Client* client = ClientManager::login(id, pass);
			if (client)
			{
				setColor(10);
				cout << "\n\tLogin Successful!\n";
				setColor(7);
				system("pause");

				while (ClientManager::clientOptions(client))
				{
					system("cls");
				}
				logout();
			}
			else
			{
				invalid(choice);
			}

		}
		else if (choice == 2)
		{
			Employee* employee = EmployeeManager::login(id, pass);
			if (employee)
			{
				setColor(10);
				cout << "\n\tLogin Successful!\n";
				setColor(7);
				system("pause");
				while (EmployeeManager::employeeOptions(employee))
				{
					system("cls");
				}
				logout();
		
			}
			else
			{
				invalid(choice);
			}
		}
		else if (choice == 3)
		{
			Admin* admin = AdminManager::login(id, pass);

			if (admin)
			{
				setColor(10);
				cout << "\n\tLogin Successful!\n";
				setColor(7);
				system("pause");
				
				while (AdminManager::AdminOptions(admin))
				{
					system("cls");
				}
				logout();
			}
			else
			{
					invalid(choice);
			}
		}
	}
	static void startScreen()
	{
		system("cls");
		blinkTitle();  
		loading(); 
	}
	static void runApp()
	{
		startScreen();
		
		while (true)
		{
			FilesHelper::getClients();
			FilesHelper::getEmployee();
			FilesHelper::getAdmins();
			Bankname();
			Welcome();
			loginOptions();


			int choice = loginAs();

			if (choice == 0)
				break;

			if (choice >= 1 && choice <= 3)
				loginscreen(choice);
			else
				invalid(choice);
		}
	}

};

