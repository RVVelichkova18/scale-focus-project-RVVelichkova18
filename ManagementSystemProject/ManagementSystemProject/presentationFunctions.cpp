#include <nanodbc.h>
#include <iostream>
#include <string>
#include <vector>
#include <exception> 
#include <chrono>
#include <thread>
#include "dataStructures.h"
#include "presentationFunctions.h"
using namespace std;


void wait(int delay)
{
	if (ANIMATION_ENABLED)
	{
		this_thread::sleep_for(chrono::milliseconds(delay));
	}
}

void loginMenu(nanodbc::connection conn)
{

	cout << "Enter the username: ";
	string username = cinLine();
	cout << "Enter the password: ";
	string  password = cinLine();
	
	loginDataCheck(conn, username, password);

}

void displayAdminOptions() {
	cout << "1) Users management" << endl;
	cout << "2) Teams management" << endl;
	cout << "3) Projects management" << endl;
	cout << "4) Tasks management" << endl;
	cout << "5) Work log management" << endl;
	cout << "6) Exit" << endl;
}

bool adminOptions(nanodbc::connection conn)
{
	displayAdminOptions();
	int choice;
	cout << "Enter an option: ";
	string line;
	getline(cin, line);
	choice = stoi(line);

	switch (choice)
	{
	case 1: {
		system("cls");
		createUser(conn);
		break;
	}
	case 2: {
		system("cls");
		editUser(conn);
		break;
	}
	case 3: {
		system("cls");
<<<<<<< HEAD
		loginMenu(conn);
=======
		getAllUsers(conn);
>>>>>>> parent of e09964b (Add listing to all tables)
		break;
	}
	case 4:
		return false;
	default: 
		cout << "Try again! " << endl;
	}

	return true;
}
