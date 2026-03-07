#pragma once
#include "Client.h"
#include "Validation.h"
#include "FileManager.h"
#include <iostream>
class ClientManager
{
public:
    static void printClientMenu()
    {
        cout << "\n1- Deposit\n";
        cout << "2- Withdraw\n";
        cout << "3- Transfer\n";
        cout << "4- Check Balance\n";
        cout << "5- Change Password\n";
        cout << "6- Logout\n";
    }
    static void Updatepassword(Person* person)
    {
        cout << "Enter new password: ";
        string pass = Validation::enter_password();
        person->setpassword(pass);
        cout << "Password Updated Successfully\n";
    }
    static Client* login(int id , string password)
    {
        for (auto& c : clients)
        {
            if (c.getid() == id && c.getpassword() == password)
            {
                return &c;
            }
        }
        return nullptr;
    }
    static bool clientOptions(Client* client)
    {
        int options;
        printClientMenu();
        cin >> options;
        switch (options)
        {
        case 1:
        {
            double amount;
            cout << "Enter amount: \n";
            cin >> amount;
            client->deposit(amount);
            FileManager f;
            f.updateClients();
            break;

        }
        case 2:
        {
            double amount;
            cout << "Enter amount: \n";
            cin >> amount;
            client->withdraw(amount);
            FileManager f;
            f.updateClients();
            break;

        }
        case 3:
        {
            int id;
            double amount;
            cout << "Enter recipient ID: ";
            cin >> id;

            Client* recipient = nullptr;
            for (auto& c : clients)
                if (c.getid() == id)
                    recipient = &c;

            if (recipient)
            {
                cout << "Enter amount: ";
                cin >> amount;
                client->transferto(amount, *recipient);
                FileManager f;
                f.updateClients();
            }
            break;
        }
        case 4:
        {
            client->checkbalance();
            break;
        }
        case 5:
        {
            Updatepassword(client);
            FileManager f;
            f.updateClients();
            break;
        }
        case 6:
            return false;
        }
        return true;
    }
};

