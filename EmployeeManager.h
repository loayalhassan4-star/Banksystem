#pragma once
#include "Employee.h"
#include "Validation.h"
#include"Admin.h"
#include "ClientManager.h"
#include "FileManager.h"
#include <iostream>
class EmployeeManager
{   
public:
   static void printEmployeMenu()
   {
            cout << "\n1- Add Client\n";
            cout << "2- List Clients\n";
            cout << "3- Search Client\n";
            cout << "4- Edit Client\n";
            cout << "5- Logout\n";
   }
   static Employee* login(int id, string password)
   {
       for (auto& e : employees)
       {
           if (e.getid() == id && e.getpassword() == password)
           {
               return &e;
          }
       }
       return nullptr;
   }
   static void newClient(Employee* employee)
   {
       string name, password;
       double balance;
       cout << "Enter name:";
       name = Validation::entername();
       cout << "Enter Password: ";
       password = Validation::enter_password();
       cout << "Enter balance: ";
       balance = Validation::enterbalance();
       Client c(0, name, password, balance);
       employee->addClient(c);
   }
   static void listallclients(Employee* employee)
   {
       employee->listClient();
   }
   static void searchclient(Employee* employee)
   {
       int id;
       cout << "Enter ID: ";
       cin >> id;
       Client* c = employee->searchClient(id);
       if (c)
       {
           c->display();
       }
       cout << "Client not found";
   }
   static void editClientInfo(Employee* employee)
   {
       int id;
       cout << "Enter Id:";
       cin >> id;
       string name, password;
       double balance;
       if (employee->searchClient(id))
       {
           cout << "Enter new name: ";
           name = Validation::entername();

           cout << "Enter new password: ";
           password = Validation::enter_password();

           cout << "Enter new balance: ";
           balance = Validation::enterbalance();
           employee->editClient(id, name, password, balance);

       }

   }
   static bool employeeOptions(Employee* employee)
   {
       int choice;
       printEmployeMenu();
       cin >> choice;

       switch (choice)
       {
       case 1: newClient(employee);   break;
       case 2: listallclients(employee); break;
       case 3: searchclient(employee); break;
       case 4: editClientInfo(employee);  break;
       case 5: return false;
       }

       return true;
   }

};

