# 🏦 Banking Management System

A console-based Banking Management System developed using **C++**. The project simulates basic banking operations and provides different access levels for Clients, Employees, and Administrators.

## 📌 Project Overview

The system allows clients to manage their bank accounts, employees to manage client information, and administrators to view and manage employee records.

It uses Object-Oriented Programming (OOP) principles and text files for data storage and persistence.

## ✨ Features

### 👤 Client
- Login using ID and password.
- Deposit money.
- Withdraw money.
- Transfer money between clients.
- Check account balance.
- Change account password.

### 💼 Employee
- Secure employee login.
- Add new clients.
- Display all clients.
- Search for clients by ID.
- Edit client information.

### 🔐 Administrator
- Admin login.
- Display employee records.

## 🛠️ Technologies & Concepts

- **Language:** C++
- **IDE:** Microsoft Visual Studio
- **OOP Concepts:**
  - Classes and Objects
  - Inheritance
  - Encapsulation
  - Static Members and Functions
  - Pointers
  - Polymorphism
- **Data Structures:** STL Vectors
- **File Handling:** Reading and writing data using `.txt` files.
- **Input Validation:** Validating names, passwords, balances, and salaries.

## 📂 Project Structure

```text
BankSystem/
│
├── BankSystem.cpp
├── Person.h
├── Client.h
├── Employee.h
├── Admin.h
│
├── ClientManager.h
├── EmployeeManager.h
├── AdminManager.h
├── Screen.h
│
├── Validation.h
├── Parser.h
├── FileManager.h
├── FilesHelper.h
├── DataSourceInterface.h
│
├── Clients.txt
├── Employees.txt
├── Admins.txt
│
└── README.md
```

## 🚀 How to Run


1. Clone or download this repository.
2. Open `BankSystem.sln` using Microsoft Visual Studio.
3. Make sure the required text data files are available.
4. Build the solution.
5. Run the project.

**Note:** This project is designed for Windows and uses Windows console features.

## 📸 Screenshots
<img width="675" height="458" alt="Welcome-panel png" src="https://github.com/user-attachments/assets/16978d20-3c67-4c40-a4ed-90a12db1023c" />
<img width="617" height="421" alt="Employee-panel png" src="https://github.com/user-attachments/assets/f6f96b2c-ca11-49c1-9818-b75f81943185" />
<img width="768" height="497" alt="Client-panel png" src="https://github.com/user-attachments/assets/a47fd80d-e44b-4aec-ab13-f9ef24775aaf" />
<img width="786" height="630" alt="Admin-dashboard png" src="https://github.com/user-attachments/assets/a2f9bf5b-d9c9-40ad-8b75-1f849ab8cfca" />


## 🎯 Project Purpose

This project was developed to practice C++ programming, strengthen Object-Oriented Programming concepts, and understand how to build a simple banking application with file-based data management.

---

**Developed by Loay Alhassan**
Connect with me on [LinkedIn](https://www.linkedin.com)
)
