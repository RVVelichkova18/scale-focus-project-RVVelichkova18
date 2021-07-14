#include <nanodbc.h>
#include <iostream>
#include <string>
#include <vector>
#include <exception> 
#include <chrono>
#include <thread>
#include <windows.h>
#include <conio.h>
#include "dataStructures.h"
#include "presentationFunctions.h"
using namespace std;

void cursor(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

void spaces(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " ";
	}
}

void wait(int delay)
{
	if (ANIMATION_ENABLED)
	{
		this_thread::sleep_for(chrono::milliseconds(delay));
	}
}

void displayGreeting()
{
	spaces(20); cout << u8"                                                                                      " << endl;
	spaces(20); cout << u8"                                                                                      " << endl;
	spaces(32); cout <<BLUE<< u8"■■■■■■  ■■■■■■    ■■■     ■■■■■  ■■■■■  ■■■■■  ■■■■■■   ■■■■■■" <<RESET<<endl;
	spaces(32); cout <<BLUE<< u8"■■  ■■  ■■  ■■  ■■   ■■      ■■  ■■     ■■       ■■     ■■    " <<RESET<<endl;
	spaces(32); cout <<BLUE<< u8"■■■■■■  ■■■■■■  ■■   ■■      ■■  ■■■■   ■■       ■■     ■■■■■■" <<RESET<<endl;
	spaces(32); cout <<BLUE<< u8"■■      ■■ ■■   ■■   ■■  ■■  ■■  ■■     ■■       ■■         ■■" <<RESET<<endl;
	spaces(32); cout <<BLUE<< u8"■■      ■■  ■■    ■■■    ■■■■■■  ■■■■■  ■■■■■    ■■     ■■■■■■" <<RESET<<endl;
	wait(450);
	spaces(20); cout <<u8"                                                                                     " << endl;
	spaces(20); cout <<u8"                                                                                     " << endl;
	spaces(20); cout <<u8"■■     ■■   ■■■■■   ■■   ■■   ■■■■■   ■■■■■■  ■■■■■  ■■     ■■  ■■■■■  ■■   ■■  ■■■■■■"  <<endl;
	spaces(20); cout <<u8"■■■   ■■■  ■■   ■■  ■■■  ■■  ■■   ■■  ■■      ■■     ■■■   ■■■  ■■     ■■■  ■■    ■■  "  <<endl;
	spaces(20); cout <<u8"■■ ■■■ ■■  ■■■■■■■  ■■ ■ ■■  ■■■■■■■  ■■ ■■■  ■■■■   ■■ ■■■ ■■  ■■■■   ■■ ■ ■■    ■■  "  <<endl;
	spaces(20); cout <<u8"■■  ■  ■■  ■■   ■■  ■■  ■■■  ■■   ■■  ■■  ■■  ■■     ■■  ■  ■■  ■■     ■■  ■■■    ■■  "  <<endl;
	spaces(20); cout <<u8"■■     ■■  ■■   ■■  ■■   ■■  ■■   ■■  ■■■■■■  ■■■■■  ■■     ■■  ■■■■■  ■■   ■■    ■■  "  <<endl;
	wait(450);
	spaces(20); cout << u8"                                                                                      " << endl;
	spaces(20); cout << u8"                                                                                      " << endl; 
	spaces(38); cout <<BLUE<< u8"■■■■■■  ■■  ■■  ■■■■■■  ■■■■■■  ■■■■■  ■■     ■■" <<RESET<<endl;
	spaces(38); cout <<BLUE<< u8"■■      ■■  ■■  ■■        ■■    ■■     ■■■   ■■■" <<RESET<<endl;
	spaces(38); cout <<BLUE<< u8"■■■■■■  ■■■■■■  ■■■■■■    ■■    ■■■■   ■■ ■■■ ■■" <<RESET<<endl;
	spaces(38); cout <<BLUE<< u8"    ■■      ■■      ■■    ■■    ■■     ■■  ■  ■■" <<RESET<<endl;
	spaces(38); cout <<BLUE<< u8"■■■■■■  ■■■■■■  ■■■■■■    ■■    ■■■■■  ■■     ■■" <<RESET<<endl;
	wait(450);
									  
}
void displayLogin()
{
	spaces(34);  cout << endl;
	spaces(34);  cout << YELLOW << "-------------------------------------------------------" << RESET << endl;
	spaces(34);  cout << YELLOW << "|                                                     |" << RESET << endl;
	spaces(34);  cout << YELLOW << u8"|                   L  O  G  I  N                     |" << RESET << endl;
	spaces(34);  cout << YELLOW << "|                                                     |" << RESET << endl;
	spaces(34);  cout << YELLOW << "|             Username:                               |" << RESET << endl;
	spaces(34);  cout << YELLOW << "|                                                     |" << RESET << endl;
	spaces(34);  cout << YELLOW << "|                                                     |" << RESET << endl;
	spaces(34);  cout << YELLOW << "|             Password:                               |" << RESET << endl;
	spaces(34);  cout << YELLOW << "|                                                     |" << RESET << endl;
	spaces(34);  cout << YELLOW << "|                                                     |" << RESET << endl;
	spaces(34);  cout << YELLOW << "-------------------------------------------------------" << RESET << endl;
}

void loginMenu(nanodbc::connection conn, USER& user)
{
	displayGreeting();
	/*string username = "sandonova";
	string  password = "sandonovapass";*/
	displayLogin();
	cursor(59,26);	
	string username = cinLine();
	cursor(59, 29);
	string password = cinLine();
	cout << endl;
	cout << endl;
	wait(400);
	system("cls");
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
		
		spaces(34); cout << RED << "Incorrect username or password! Please, try again!" << RESET << endl;
		wait(700);
		system("cls");
		loginMenu(conn, user);
	}

	}

	//USERS

	void displayUsersManagement()
	{
		cout << endl;
		spaces(34); cout << "1) Add new user" << endl;
		spaces(34); cout << "2) Edit user by Id" << endl;
		spaces(34); cout << "3) List all users" << endl;
		spaces(34); cout << "4) Delete user by Id" << endl;
		spaces(34); cout << "5) Return back" << endl;
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
			adminOptions(conn, user);
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
		cout << endl;
		spaces(34); cout << "1) Add new team" << endl;
		spaces(34); cout << "2) Edit team by Id" << endl;
		spaces(34); cout << "3) List all teams" << endl;
		spaces(34); cout << "4) Delete team by Id" << endl;
		spaces(34); cout << "5) Return back" << endl;
	}
	bool teamsManagement(nanodbc::connection conn, USER& user)
	{
		displayTeamsManagement();
		int choice;
		spaces(34); cout << "Enter an option: ";
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
				spaces(34); cout << "You cannot edit this team :)"<<endl;
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
			if (user.id == user.idCreator or user.isAdmin)
			{
				deleteTeam(conn);
			}
			else {
				spaces(34); cout << "You cannot edit this team :)" << endl;
			}
			break;
		}
		case 5:
			return false;
		default:
			spaces(34); cout << "Try again! " << endl;
		}

		return true;
	}

	//PROJECTS

	void displayProjectsManagement()
	{
		cout << endl;
		spaces(34); cout << "1) Add new project" << endl;
		spaces(34); cout << "2) Edit project by Id" << endl;
		spaces(34); cout << "3) List all projects" << endl;
		spaces(34); cout << "4) Delete projects by Id" << endl;
		spaces(34); cout << "5) Return back" << endl;
	}
	bool projectsManagement(nanodbc::connection conn, USER& user)
	{
		displayProjectsManagement();
		int choice;
		spaces(34); cout << "Enter an option: ";
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
			spaces(34); cout << "Enter id of the project that you want edit: " << endl;
			int id = cinNumber();
			PROJECTS project = getProjectById(conn, id);
			if (user.id == project.idCreator or user.isAdmin)
			{
				editProject(conn, id);
			}
			else {
				spaces(34); cout << "You cannot edit this team :)" << endl;
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
			spaces(34); cout << "Enter id of the project that you want delete: " << endl;
			int id = cinNumber();
			if (user.id == user.idCreator or user.isAdmin)
			{
					PROJECTS::deleteProjectById(conn, id);
			}
			else {
				spaces(34);	cout << "You cannot delete this team :)" << endl;
			}
			break;
		}
		case 5:
			return false;
		default:
			spaces(34);	cout << "Try again! " << endl;
		}

		return true;
	}

	//TASKS

	void displayTasksManagement()
	{
		cout << endl;
		spaces(34); cout << "1) Add new task" << endl;
		spaces(34); cout << "2) Edit task by Id" << endl;
		spaces(34); cout << "3) List all tasks" << endl;
		spaces(34); cout << "4) Delete task by Id" << endl;
		spaces(34); cout << "5) View work logs for task by Id" << endl;
		spaces(34); cout << "6) Return back" << endl;
	}
	bool tasksManagement(nanodbc::connection conn, USER& user)
	{
		displayTasksManagement();
		int choice;
		spaces(34); cout << "Enter an option: ";
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

			spaces(34); cout << "Enter id of the task that you want edit: " << endl;
			 int id = cinNumber();
			 TASKS task = getTaskById(conn, id);
			if (user.id == task.idCreator or user.isAdmin)
			{
				editTask(conn, id);
			}
			else {
				spaces(34);	cout << "You cannot edit this task :)" << endl;
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
			spaces(34); cout << "Enter id of the task that you want delete: " << endl;
			int id = cinNumber();
			TASKS task = getTaskById(conn, id);
			if (user.id == task.idCreator or user.isAdmin)
			{
				TASKS::deleteTaskById(conn, id);
			}
			else {
				spaces(34);	cout << "You cannot delete this task :)" << endl;
			}
			break;
		}
		case 5: {
			system("cls");
			spaces(34); cout << "Enter id of the task that you want work log for: " << endl;
			int id = cinNumber();
			TASKS task = getTaskById(conn, id);
			LOGS log = getLogByTaskId(conn, task.id);
			if (task.id == log.taskId)
			{
				logManagement(conn, user);
			}
			else {
				spaces(34);	cout << "You cannot see this work log :)" << endl;
			}
			break;
		}
		case 6:
			return false;
		default:
			spaces(34); cout << "Try again! " << endl;
		}

		return true;
	}

	//LOGS
	void displayLogsManagement()
	{
		cout << endl;
		spaces(34); cout << "1) Add new work log" << endl;
		spaces(34); cout << "2) Edit work log by Id" << endl;
		spaces(34); cout << "3) List all work logs" << endl;
		spaces(34); cout << "4) Delete work log by Id" << endl;
		spaces(34); cout << "5) Return back" << endl;
	}
	bool logManagement(nanodbc::connection conn, USER& user)
	{
		displayLogsManagement();
		int choice;
		spaces(34); cout << "Enter an option: ";
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
			spaces(34);	cout << "Enter id of the task that you want edit: " << endl;
			int id = cinNumber();
			LOGS log = getLogById(conn, id);
			if (user.id == log.userId or user.isAdmin)
			{
				editLog(conn, id);
			}
			else {
				spaces(34);	cout << "You cannot edit this team :)" << endl;
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
			spaces(34);	cout << "Enter id of the task that you want edit: " << endl;
		    int id = cinNumber();
			LOGS log = getLogById(conn, id);
			if (user.id == log.userId or user.isAdmin)
			{
				LOGS::deleteLogById(conn, id);
			}
			else {
				spaces(34);	cout << "You cannot edit this team :)" << endl;
			}
			break;
		}
		case 5:
			return false;
		default:
			spaces(34);	cout << "Try again! " << endl;
		}

		return true;
	}


	void displayAdminOptions()
	{
		cout << endl;
		spaces(34); cout << "1) Users management" << endl;
		spaces(34); cout << "2) Teams management" << endl;
		spaces(34); cout << "3) Projects management" << endl;
		spaces(34); cout << "4) Tasks management" << endl;
		spaces(34); cout << "5) Work log management" << endl;
		spaces(34); cout << "6) Exit" << endl;
	}

	bool adminOptions(nanodbc::connection conn, USER& user)
	{
		displayAdminOptions();
		int choice;
		spaces(34); cout << "Enter an option: ";
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
			spaces(34);	cout << "Try again! " << endl;
		}

		return true;
	}

	void displayUserOptions()
	{
		cout << endl;
		spaces(34); cout << "1) Projects management" << endl;
		spaces(34); cout << "2) Tasks management" << endl;
		spaces(34); cout << "3) Exit" << endl;
	}

	bool userOptions(nanodbc::connection conn,USER& user)
	{
		displayUserOptions();
		int choice;
		spaces(34); cout << "Enter an option: ";
		string line;
		getline(cin, line);
		choice = stoi(line);

		switch (choice)
		{
		
		case 1: {
			system("cls");
			projectsManagement(conn, user);
			userOptions(conn, user);
			break;
		}
		case 2: {
			system("cls");
			tasksManagement(conn, user);
			userOptions(conn, user);
			break;
		}
		case 3:
			return false;
		default:
			spaces(34);	cout << "Try again! " << endl;
		}

		return true;
	}

