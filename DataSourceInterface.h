#pragma once

class DataSourceInterface
{
public:
	virtual void addClient(Client& obj) = 0;
	virtual void addEmployee(Employee& obj) = 0;
	virtual void addAdmin(Admin& obj) = 0;
	virtual void getallClients() = 0;
	virtual void getallEmployees() = 0;
	virtual void getallAdmins() = 0;
	virtual void removeallClients() = 0;
	virtual void removeallEmployees() = 0;
	virtual void removeallAdmins() = 0;
	virtual ~DataSourceInterface() {};
};

