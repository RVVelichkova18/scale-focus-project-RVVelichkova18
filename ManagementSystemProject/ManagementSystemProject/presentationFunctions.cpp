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

void loginMenu(nanodbc::connection conn, USER& user)
{

	cout << "Enter the username: ";
	string username = cinLine();
	cout << "Enter the password: ";
	string  password = cinLine();

	user = loginDataCheck(conn, username, password);

	if (user.id > 0)
	{
		if (user.isAdmin) {

			adminOptions(conn, user);
		}
		else 
		{
			userOptions(conn, user);
		}
	} 
	else {
		cout << "Incorrect username or password! Please, try again!"<<endl;
		system("cls");
		loginMenu(conn, user);
	}

	}

	//USERS

	void displayUsersManagement()
	{
		cout << "1) Add new user" << endl;
		cout << "2) Edit user by Id" << endl;
		cout << "3) List all users" << endl;
		cout << "4) Delete user by Id" << endl;
		cout << "5) Return back" << endl;
	}
	bool usersManagement(nanodbc::connection conn, USER& user)
	{
		displayUsersManagement();
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
			adminOptions(conn, user);
			break;
		}
		case 2: {
			system("cls");
			editUser(conn);
			adminOptions(conn, user);
			break;
		}
		case 3: {
			system("cls");
			listAllUsers(conn);
			adminOptions(conn, user);
			break;
		}
		case 4: {
			system("cls");
			deleteUser(conn);
			cout << "Delete functionality is just a future idea :)" << endl;
			break;
		}
		case 5:
			return false;
		default:
			cout << "Try again! " << endl;
		}

		return true;
	}

	//TEAMS

	void displayTeamsManagement()
	{
		cout << "1) Add new team" << endl;
		cout << "2) Edit team by Id" << endl;
		cout << "3) List all teams" << endl;
		cout << "4) Delete team by Id" << endl;
		cout << "5) Return back" << endl;
	}
	bool teamsManagement(nanodbc::connection conn, USER& user)
	{
		displayTeamsManagement();
		int choice;
		cout << "Enter an option: ";
		string line;
		getline(cin, line);
		choice = stoi(line);

		switch (choice)
		{
		case 1: {
			system("cls");
			createTeam(conn);
			break;
		}
		case 2: {
			system("cls");
			if (user.id == user.idCreator or user.isAdmin)
			{
				editTeam(conn);
			}
			else {
				cout << "You cannot edit this team :)"<<endl;
			}
			break;
		}
		case 3: {
			system("cls");
			listAllTeams(conn);
			break;
		}
		case 4: {
			system("cls");
			cout << "Delete functionality is just a future idea :)" << endl;
			break;
		}
		case 5:
			return false;
		default:
			cout << "Try again! " << endl;
		}

		return true;
	}

	//PROJECTS

	void displayProjectsManagement()
	{
		cout << "1) Add new project" << endl;
		cout << "2) Edit project by Id" << endl;
		cout << "3) List all projects" << endl;
		cout << "4) Delete projects by Id" << endl;
		cout << "5) Return back" << endl;
	}
	bool projectsManagement(nanodbc::connection conn, USER& user)
	{
		displayProjectsManagement();
		int choice;
		cout << "Enter an option: ";
		string line;
		getline(cin, line);
		choice = stoi(line);

		switch (choice)
		{
		case 1: {
			system("cls");
			createProject(conn);
			break;
		}
		case 2: {
			system("cls");
			if (user.id == user.idCreator or user.isAdmin)
			{
				editProject(conn);
			}
			else {
				cout << "You cannot edit this team :)" << endl;
			}
			break;
		}
		case 3: {
			system("cls");
			listAllProjects(conn);
			break;
		}
		case 4: {
			system("cls");
			cout << "Delete functionality is just a future idea :)" << endl;
			break;
		}
		case 5:
			return false;
		default:
			cout << "Try again! " << endl;
		}

		return true;
	}

	//TASKS

	void displayTasksManagement()
	{
		cout << "1) Add new task" << endl;
		cout << "2) Edit task by Id" << endl;
		cout << "3) List all tasks" << endl;
		cout << "4) Delete task by Id" << endl;
		cout << "5) Return back" << endl;
	}
	bool tasksManagement(nanodbc::connection conn, USER& user)
	{
		displayTasksManagement();
		int choice;
		cout << "Enter an option: ";
		string line;
		getline(cin, line);
		choice = stoi(line);

		switch (choice)
		{
		case 1: {
			system("cls");
			createTask(conn);
			break;
		}
		case 2: {
			system("cls");
			if (user.id == user.idCreator or user.isAdmin)
			{
				editTask(conn);
			}
			else {
				cout << "You cannot edit this team :)" << endl;
			}
			break;
		}
		case 3: {
			system("cls");
			listAllTasks(conn);
			break;
		}
		case 4: {
			system("cls");
			cout << "Delete functionality is just a future idea :)" << endl;
			break;
		}
		case 5:
			return false;
		default:
			cout << "Try again! " << endl;
		}

		return true;
	}

	//LOGS

	void displayLogsManagement()
	{
		cout << "1) Add new work log" << endl;
		cout << "2) Edit work log by Id" << endl;
		cout << "3) List all work logs" << endl;
		cout << "4) Delete work log by Id" << endl;
		cout << "5) Return back" << endl;
	}
	bool logManagement(nanodbc::connection conn, USER& user)
	{
		displayLogsManagement();
		int choice;
		cout << "Enter an option: ";
		string line;
		getline(cin, line);
		choice = stoi(line);

		switch (choice)
		{
		case 1: {
			system("cls");
			createLog(conn);
			break;
		}
		case 2: {
			system("cls");
			if (user.id == user.idCreator or user.isAdmin)
			{
				editLog(conn);
			}
			else {
				cout << "You cannot edit this team :)" << endl;
			}
			break;
		}
		case 3: {
			system("cls");
			listAllLogs(conn);
			break;
		}
		case 4: {
			system("cls");
			cout << "Delete functionality is just a future idea :)" << endl;
			break;
		}
		case 5:
			return false;
		default:
			cout << "Try again! " << endl;
		}

		return true;
	}


	void displayAdminOptions()
	{
		cout << "1) Users management" << endl;
		cout << "2) Teams management" << endl;
		cout << "3) Projects management" << endl;
		cout << "4) Tasks management" << endl;
		cout << "5) Work log management" << endl;
		cout << "6) Exit" << endl;
	}

	bool adminOptions(nanodbc::connection conn, USER& user)
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
			usersManagement(conn, user);
			adminOptions(conn, user);
			break;
		}
		case 2: {
			system("cls");
			teamsManagement(conn, user);
			adminOptions(conn, user);
			break;
		}
		case 3: {
			system("cls");
			projectsManagement(conn, user);
			adminOptions(conn, user);
			break;
		}
		case 4: {
			system("cls");
			tasksManagement(conn, user);
			adminOptions(conn, user);
			break;
		}
		case 5: {
			system("cls");
			logManagement(conn, user);
			adminOptions(conn, user);
			break;
		}
		case 6:
			return false;
		default:
			cout << "Try again! " << endl;
		}

		return true;
	}

	void displayUserOptions()
	{
		cout << "1) Teams management" << endl;
		cout << "2) Projects management" << endl;
		cout << "3) Tasks management" << endl;
		cout << "4) Work log management" << endl;
		cout << "5) Exit" << endl;
	}

	bool userOptions(nanodbc::connection conn,USER& user)
	{
		displayUserOptions();
		int choice;
		cout << "Enter an option: ";
		string line;
		getline(cin, line);
		choice = stoi(line);

		switch (choice)
		{
		case 1: {
			system("cls");
		    teamsManagement(conn, user);
			userOptions(conn, user);
			break;
		}
		case 2: {
			system("cls");
			projectsManagement(conn, user);
			userOptions(conn, user);
			break;
		}
		case 3: {
			system("cls");
			tasksManagement(conn, user);
			userOptions(conn, user);
			break;
		}
		case 4: {
			system("cls");
			logManagement(conn, user);
			userOptions(conn, user);
			break;
		}
		case 5:
			return false;
		default:
			cout << "Try again! " << endl;
		}

		return true;
	}

