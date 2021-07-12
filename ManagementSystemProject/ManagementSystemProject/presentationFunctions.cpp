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


bool menu(nanodbc::connection conn)
{
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
		
		break;
	}
	case 4:
		return false;
	default: 
		cout << "Try again! " << endl;
	}

	return true;
}
