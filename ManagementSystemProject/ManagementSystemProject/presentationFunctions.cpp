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

//formatting
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

//greetings
void welcome()
{
	cout << endl;
	spaces(30); cout << YELLOW << u8"■■       ■■  ■■■■■  ■■     ■■■■■    ■■■    ■■     ■■  ■■■■■  ■■ " << RESET << endl;
	spaces(30); cout << YELLOW << u8"■■   ■   ■■  ■■     ■■     ■■     ■■   ■■  ■■■   ■■■  ■■     ■■ " << RESET << endl;
	spaces(30); cout << YELLOW << u8"■■  ■■■  ■■  ■■■■   ■■     ■■     ■■   ■■  ■■ ■■■ ■■  ■■■■   ■■ " << RESET << endl;
	spaces(30); cout << YELLOW << u8"■■ ■■ ■■ ■■  ■■     ■■     ■■     ■■   ■■  ■■  ■  ■■  ■■        " << RESET << endl;
	spaces(30); cout << YELLOW << u8"■■■     ■■■  ■■■■■  ■■■■■  ■■■■■    ■■■    ■■     ■■  ■■■■■  ■■ " << RESET << endl;
	cout << endl;
	wait(400);
}
void displayGreeting()
{
	spaces(20); cout << u8"                                                                                      " << endl;
	spaces(20); cout << u8"                                                                                      " << endl;
	spaces(32); cout << BLUE << u8"■■■■■■  ■■■■■■    ■■■     ■■■■■  ■■■■■  ■■■■■  ■■■■■■   ■■■■■■" << RESET << endl;
	spaces(32); cout << BLUE << u8"■■  ■■  ■■  ■■  ■■   ■■      ■■  ■■     ■■       ■■     ■■    " << RESET << endl;
	spaces(32); cout << BLUE << u8"■■■■■■  ■■■■■■  ■■   ■■      ■■  ■■■■   ■■       ■■     ■■■■■■" << RESET << endl;
	spaces(32); cout << BLUE << u8"■■      ■■ ■■   ■■   ■■  ■■  ■■  ■■     ■■       ■■         ■■" << RESET << endl;
	spaces(32); cout << BLUE << u8"■■      ■■  ■■    ■■■    ■■■■■■  ■■■■■  ■■■■■    ■■     ■■■■■■" << RESET << endl;
	wait(450);
	spaces(20); cout << u8"                                                                                     " << endl;
	spaces(20); cout << u8"                                                                                     " << endl;
	spaces(20); cout << WHITE << u8"■■     ■■   ■■■■■   ■■   ■■   ■■■■■   ■■■■■■  ■■■■■  ■■     ■■  ■■■■■  ■■   ■■  ■■■■■■" << RESET << endl;
	spaces(20); cout << WHITE << u8"■■■   ■■■  ■■   ■■  ■■■  ■■  ■■   ■■  ■■      ■■     ■■■   ■■■  ■■     ■■■  ■■    ■■  " << RESET << endl;
	spaces(20); cout << WHITE << u8"■■ ■■■ ■■  ■■■■■■■  ■■ ■ ■■  ■■■■■■■  ■■ ■■■  ■■■■   ■■ ■■■ ■■  ■■■■   ■■ ■ ■■    ■■  " << RESET << endl;
	spaces(20); cout << WHITE << u8"■■  ■  ■■  ■■   ■■  ■■  ■■■  ■■   ■■  ■■  ■■  ■■     ■■  ■  ■■  ■■     ■■  ■■■    ■■  " << RESET << endl;
	spaces(20); cout << WHITE << u8"■■     ■■  ■■   ■■  ■■   ■■  ■■   ■■  ■■■■■■  ■■■■■  ■■     ■■  ■■■■■  ■■   ■■    ■■  " << RESET << endl;
	wait(450);
	spaces(20); cout << u8"                                                                                      " << endl;
	spaces(20); cout << u8"                                                                                      " << endl;
	spaces(38); cout << BLUE << u8"■■■■■■  ■■  ■■  ■■■■■■  ■■■■■■  ■■■■■  ■■     ■■" << RESET << endl;
	spaces(38); cout << BLUE << u8"■■      ■■  ■■  ■■        ■■    ■■     ■■■   ■■■" << RESET << endl;
	spaces(38); cout << BLUE << u8"■■■■■■  ■■■■■■  ■■■■■■    ■■    ■■■■   ■■ ■■■ ■■" << RESET << endl;
	spaces(38); cout << BLUE << u8"    ■■      ■■      ■■    ■■    ■■     ■■  ■  ■■" << RESET << endl;
	spaces(38); cout << BLUE << u8"■■■■■■  ■■■■■■  ■■■■■■    ■■    ■■■■■  ■■     ■■" << RESET << endl;
	wait(450);

}

//login menu
void displayLogin()
{
	spaces(34);  cout << endl;
	spaces(34);  cout << BLUE << "_______________________________________________________" << RESET << endl;
	spaces(34);  cout << BLUE << "|                                                     |" << RESET << endl;
	spaces(34);  cout << BLUE << u8"|                   L  O  G  I  N                     |" << RESET << endl;
	spaces(34);  cout << BLUE << "|                                                     |" << RESET << endl;
	spaces(34);  cout << BLUE << "|             Username:                               |" << RESET << endl;
	spaces(34);  cout << BLUE << "|                                                     |" << RESET << endl;
	spaces(34);  cout << BLUE << "|                                                     |" << RESET << endl;
	spaces(34);  cout << BLUE << "|             Password:                               |" << RESET << endl;
	spaces(34);  cout << BLUE << "|                                                     |" << RESET << endl;
	spaces(34);  cout << BLUE << "|_____________________________________________________|" << RESET << endl;
}

void loginMenu(nanodbc::connection conn, USER& user)
{

	displayGreeting();
	/*string username = "sandonova";
	string  password = "sandonovapass";*/
	displayLogin();
	cursor(59, 26);
	string username = cinLine();
	if (username.length() > 15)
	{
		spaces(45); cout << RED << "Your username have to be with  max 15 characters: " << RESET;
		username = cinLine();
	}
	cursor(59, 29);
	string password = cinLine();
	if (password.length() > 15)
	{
		spaces(45); cout <<RED<< "Your password have to be with max 15 characters: "<<RESET;
		password = cinLine();
	}
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
	wait(400);
	spaces(32); cout << YELLOW << " ________________________________________________________________" << RESET << endl;
	spaces(32); cout << YELLOW << "|                                                               |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                       O P T I O N S                           |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                                                               |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                       1) Add new user                         |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                       2) Edit user by Id                      |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                       3) List all users                       |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                       4) Delete user by Id                    |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                       5) Return back                          |" << RESET << endl;
	spaces(32); cout << YELLOW << "|_______________________________________________________________|" << RESET << endl;
	cout << endl;
}
bool usersManagement(nanodbc::connection conn, USER& user)
{
	displayUsersManagement();
	int choice;
	spaces(34); cout << "Enter an option: ";
	string line;
	getline(cin, line);
	choice = stoi(line);

	switch (choice)
	{
	case 1: {
		system("cls");
		spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━─╮" << RESET << endl;
		spaces(56); cout << GREEN << "     Add user   " << RESET << endl;
		spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━─╯" << RESET << endl;
		createUser(conn);
		wait(400);
		system("cls");
		adminOptions(conn, user);
		break;
	}
	case 2: {
		system("cls");
		spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━─╮" << RESET << endl;
		spaces(56); cout << GREEN << "    Edit user   " << RESET << endl;
		spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━─╯" << RESET << endl;
		editUser(conn);
		wait(400);
		system("cls");
		adminOptions(conn, user);
		break;
	}
	case 3: {
		system("cls");
		spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━─╮" << RESET << endl;
		spaces(56); cout << GREEN << "    List user   " << RESET << endl;
		spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━─╯" << RESET << endl;

		listAllUsers(conn);
		adminOptions(conn, user);
		break;
	}
	case 4: {
		system("cls");
		spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━─╮" << RESET << endl;
		spaces(56); cout << GREEN << "   Delete user  " << RESET << endl;
		spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━─╯" << RESET << endl;

		deleteUser(conn);
		wait(400);
		system("cls");
		adminOptions(conn, user);
		break;
	}
	case 5:
		return false;
	default:
		spaces(56); cout << RED << "Try again! " << RESET << endl;
		usersManagement(conn, user);
	}

	return true;
}

//TEAMS

void displayTeamsManagement()
{
	wait(400);
	spaces(32); cout << YELLOW << " ________________________________________________________________" << RESET << endl;
	spaces(32); cout << YELLOW << "|                                                               |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                       O P T I O N S                           |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                                                               |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                       1) Add new team                         |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                       2) Edit team by Id                      |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                       3) List all teams                       |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                       4) Delete team by Id                    |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                       5) Return back                          |" << RESET << endl;
	spaces(32); cout << YELLOW << "|_______________________________________________________________|" << RESET << endl;
	cout << endl;
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
		spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━─╮" << RESET << endl;
		spaces(56); cout << GREEN << "   Create team  " << RESET << endl;
		spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━─╯" << RESET << endl;

		createTeam(conn);
		break;
	}
	case 2: {
		system("cls");
		if (user.id == user.idCreator or user.isAdmin)
		{
			spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━─╮" << RESET << endl;
			spaces(56); cout << GREEN << "   Edit team    " << RESET << endl;
			spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━─╯" << RESET << endl;

			editTeam(conn);
		}
		else {
			spaces(34); cout << "You cannot edit this team :)" << endl;
		}
		break;
	}
	case 3: {
		system("cls");
		spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━─╮" << RESET << endl;
		spaces(56); cout << GREEN << "   List teams   " << RESET << endl;
		spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━─╯" << RESET << endl;

		listAllTeams(conn);
		break;
	}
	case 4: {
		system("cls");
		if (user.id == user.idCreator or user.isAdmin)
		{
			spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━─╮" << RESET << endl;
			spaces(56); cout << GREEN << "   Delete team  " << RESET << endl;
			spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━─╯" << RESET << endl;

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
		spaces(34); cout <<RED<< "Try again! " <<RESET<< endl;
		teamsManagement(conn, user);
	}

	return true;
}

//PROJECTS

void displayProjectsManagement()
{
	wait(400);
	spaces(32); cout << YELLOW << " ________________________________________________________________" << RESET << endl;
	spaces(32); cout << YELLOW << "|                                                               |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                       O P T I O N S                           |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                                                               |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                     1) Add new project                        |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                     2) Edit project by Id                     |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                     3) List all projects                      |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                     4) Delete projects by Id                  |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                     5) Return back                            |" << RESET << endl;
	spaces(32); cout << YELLOW << "|_______________________________________________________________|" << RESET << endl;
	cout << endl;
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
		spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━─╮" << RESET << endl;
		spaces(56); cout << GREEN << " Create project " << RESET << endl;
		spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━─╯" << RESET << endl;

		createProject(conn);
		break;
	}
	case 2: {
		system("cls");
		spaces(32); cout << "Enter id of the project that you want edit: " << endl; int id = cinNumber();
		PROJECTS project = getProjectById(conn, id);
		if (user.id == project.idCreator or user.isAdmin)
		{
			spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━─╮" << RESET << endl;
			spaces(56); cout << GREEN << " Edit project   " << RESET << endl;
			spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━─╯" << RESET << endl;

			editProject(conn, id);
		}
		else {
			spaces(34); cout << "You cannot edit this project :)" << endl;
		}
		break;
	}
	case 3: {
		system("cls");
		spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━━─╮" << RESET << endl;
		spaces(56); cout << GREEN << "  List projects " << RESET << endl;
		spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━━─╯" << RESET << endl;

		listAllProjects(conn);
		break;
	}
	case 4: {
		system("cls");
		spaces(32); cout << "Enter id of the project that you want delete: " << endl; int id = cinNumber();
		if (user.id == user.idCreator or user.isAdmin)
		{
			spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━━─╮" << RESET << endl;
			spaces(56); cout << GREEN << "  Delete project " << RESET << endl;
			spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━━─╯" << RESET << endl;

			PROJECTS::deleteProjectById(conn, id);
			cout << endl;
			cout << GREEN << "Deleted successfully!" << endl;
			wait(400);
		}
		else {
			spaces(34);	cout << "You cannot delete this project :)" << endl;
		}
		break;
	}
	case 5:
		return false;
	default:
		spaces(34);	cout << RED << "Try again! " << RESET << endl;
		projectsManagement(conn, user);
	}

	return true;
}

//TASKS

void displayTasksManagement()
{
	wait(400);
	spaces(32); cout << YELLOW << " ________________________________________________________________" << RESET << endl;
	spaces(32); cout << YELLOW << "|                                                               |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                       O P T I O N S                           |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                                                               |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                      1) Add new task                          |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                      2) Edit task by Id                       |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                      3) List all tasks                        |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                      4) Delete task by Id                     |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                      5) View work logs for task by Id         |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                      6) Return back                           |" << RESET << endl;
	spaces(32); cout << YELLOW << "|_______________________________________________________________|" << RESET << endl;
	cout << endl;
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
		spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━━─╮" << RESET << endl;
		spaces(56); cout << GREEN << "   Create task   " << RESET << endl;
		spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━━─╯" << RESET << endl;

		createTask(conn);
		break;
	}
	case 2: {
		system("cls");

		spaces(32); cout << "Enter id of the task that you want edit: " << endl; int id = cinNumber();
		TASKS task = getTaskById(conn, id);
		if (user.id == task.idCreator or user.isAdmin)
		{
			spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━━─╮" << RESET << endl;
			spaces(56); cout << GREEN << "    Edit task    " << RESET << endl;
			spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━━─╯" << RESET << endl;

			editTask(conn, id);
		}
		else {
			spaces(34);	cout << "You cannot edit this task :)" << endl;
		}
		break;
	}
	case 3: {
		system("cls");
		spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━━─╮" << RESET << endl;
		spaces(56); cout << GREEN << "   List tasks    " << RESET << endl;
		spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━━─╯" << RESET << endl;

		listAllTasks(conn);
		break;
	}
	case 4: {
		system("cls");
		spaces(32); cout << "Enter id of the task that you want delete: " << endl; int id = cinNumber();
		TASKS task = getTaskById(conn, id);
		if (user.id == task.idCreator or user.isAdmin)
		{
			spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━━─╮" << RESET << endl;
			spaces(56); cout << GREEN << "   Delete task   " << RESET << endl;
			spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━━─╯" << RESET << endl;

			TASKS::deleteTaskById(conn, id);
			cout << endl;
			cout << GREEN << "Deleted successfully!" << endl;
			wait(400);
		}
		else {
			spaces(34);	cout << RED << "You cannot delete this task :)" << RESET << endl;
		}
		break;
	}
	case 5: {
		system("cls");
		spaces(32); cout << "Enter id of the task that you want work log for: " << endl; int id = cinNumber();
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
		spaces(34); cout <<RED<< "Try again! "<<RESET << endl;
		tasksManagement(conn, user);
	}

	return true;
}

//LOGS
void displayLogsManagement()
{
	wait(400);
	spaces(32); cout << YELLOW << " ________________________________________________________________" << RESET << endl;
	spaces(32); cout << YELLOW << "|                                                               |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                       O P T I O N S                           |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                                                               |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                     1) Add new work log                       |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                     2) Edit work log by Id                    |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                     3) List all work logs                     |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                     4) Delete work log by Id                  |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                     5) Return back                            |" << RESET << endl;
	spaces(32); cout << YELLOW << "|_______________________________________________________________|" << RESET << endl;
	cout << endl;
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
		spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━━─╮" << RESET << endl;
		spaces(56); cout << GREEN << "   Create log    " << RESET << endl;
		spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━━─╯" << RESET << endl;

		createLog(conn);
		break;
	}
	case 2: {
		system("cls");
		spaces(32);	cout << "Enter id of the task that you want edit: " << endl; int id = cinNumber();
		LOGS log = getLogById(conn, id);
		if (user.id == log.userId or user.isAdmin)
		{
			spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━━─╮" << RESET << endl;
			spaces(56); cout << GREEN << "    Edit log     " << RESET << endl;
			spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━━─╯" << RESET << endl;

			editLog(conn, id);
		}
		else {
			spaces(34);	cout << "You cannot edit this work log :)" << endl;
		}
		break;
	}
	case 3: {
		system("cls");
		spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━━─╮" << RESET << endl;
		spaces(56); cout << GREEN << "    List logs    " << RESET << endl;
		spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━━─╯" << RESET << endl;

		listAllLogs(conn);
		break;
	}
	case 4: {
		system("cls");
		spaces(32);	cout << "Enter id of the log that you want edit: " << endl; int id = cinNumber();
		LOGS log = getLogById(conn, id);
		if (user.id == log.userId or user.isAdmin)
		{
			spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━━─╮" << RESET << endl;
			spaces(56); cout << GREEN << "   Delete task   " << RESET << endl;
			spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━━─╯" << RESET << endl;

			LOGS::deleteLogById(conn, id);
			cout << endl;
			cout << GREEN << "Deleted successfully!" << endl;
			wait(400);
		}
		else {
			spaces(34);	cout << RED << "You cannot delete this work log :)" << RESET << endl;
		}
		break;
	}
	case 5:
		return false;
	default:
		spaces(34);	cout <<RED<< "Try again! " <<RESET<< endl;
		logManagement(conn,user);
	}

	return true;
}

//authentication
void displayAdminOptions()
{
	spaces(32); cout << YELLOW << " ________________________________________________________________" << RESET << endl;
	spaces(32); cout << YELLOW << "|                                                               |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                       O P T I O N S                           |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                                                               |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                    1) Users management                        |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                    2) Teams management                        |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                    3) Projects management                     |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                    4) Tasks management                        |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                    5) Work log management                     |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                    6) Statistics                              |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                    7) Exit                                    |" << RESET << endl;
	spaces(32); cout << YELLOW << "|_______________________________________________________________|" << RESET << endl;
	cout << endl;
}

bool adminOptions(nanodbc::connection conn, USER& user)
{
	welcome();
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
	case 6: {
		system("cls");
		cout << "users: "<<countUsers(conn);
		adminOptions(conn, user);
		break;
	}
	case 7:
		return false;
	default:
		spaces(34);	cout << RED << "Try again! " << RESET << endl;
	}

	return true;
}

void displayUserOptions()
{
	spaces(32); cout << YELLOW << " ________________________________________________________________" << RESET << endl;
	spaces(32); cout << YELLOW << "|                                                               |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                       O P T I O N S                           |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                                                               |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                    1) Projects management                     |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                    2) Tasks management                        |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                    3) View all users                          |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                    4) View all teams                          |" << RESET << endl;
	spaces(32); cout << YELLOW << "|                    5) Exit                                    |" << RESET << endl;
	spaces(32); cout << YELLOW << "|_______________________________________________________________|" << RESET << endl;
	cout << endl;
}

bool userOptions(nanodbc::connection conn, USER& user)
{
	welcome();
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
	case 3: {
		system("cls");
		spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━─╮" << RESET << endl;
		spaces(56); cout << GREEN << "    List users  " << RESET << endl;
		spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━─╯" << RESET << endl;
		cout << endl;
		listAllUsers(conn);
		userOptions(conn, user);
		break;
	}
	case 4: {
		system("cls");
		spaces(56); cout << GREEN << u8"╭─━━━━━━━━━━━━─╮" << RESET << endl;
		spaces(56); cout << GREEN << "    List teams  " << RESET << endl;
		spaces(56); cout << GREEN << u8"╰─━━━━━━━━━━━━─╯" << RESET << endl;
		cout << endl;
		listAllTeams(conn);
		userOptions(conn, user);
		break;
	}
	case 5:
		return false;
	default:
		spaces(34);	cout << RED << "Try again! " << RESET << endl;
	}

	return true;
}

