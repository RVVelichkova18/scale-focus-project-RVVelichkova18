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
//USERS

void displayUsersManagement()
{
	cout << "1) Add new user" << endl;
	cout << "2) Edit user by Id" << endl;
	cout << "3) List all users" << endl;
	cout << "4) Delete user by Id" << endl;
	cout << "5) Return back" << endl;
}
bool usersManagement(nanodbc::connection conn)
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
		break;
	}
	case 2: {
		system("cls");
		editUser(conn);
		break;
	}
	case 3: {
		system("cls");
		listAllUsers(conn);
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

//TEAMS

void displayTeamsManagement()
{
	cout << "1) Add new team" << endl;
	cout << "2) Edit team by Id" << endl;
	cout << "3) List all teams" << endl;
	cout << "4) Delete team by Id" << endl;
	cout << "5) Return back" << endl;
}
bool teamsManagement(nanodbc::connection conn)
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
		editTeam(conn);
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
bool projectsManagement(nanodbc::connection conn)
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
		editProject(conn);
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
bool tasksManagement(nanodbc::connection conn)
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
		editTask(conn);
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
bool logManagement(nanodbc::connection conn)
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
		editLog(conn);
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
		usersManagement(conn);
		break;
	}
	case 2: {
		system("cls");
		teamsManagement(conn);
		break;
	}
	case 3: {
		system("cls");
		projectsManagement(conn);
		break;
	}
	case 4: {
		system("cls");
		tasksManagement(conn);
		break;
	}
	case 5: {
		system("cls");
		logManagement(conn);
		break;
	}
	case 6:
		return false;
	default:
		cout << "Try again! " << endl;
	}

	return true;
}
