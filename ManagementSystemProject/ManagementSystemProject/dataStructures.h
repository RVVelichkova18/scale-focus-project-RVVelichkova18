#pragma once
#include <nanodbc.h>
#include <iostream>
#include <string>
#include <vector>
#include <exception> 
#include "dataFunctions.h"
#include "presentationFunctions.h"


struct USER {
	int id = 0;
	std::string username = "";
	std::string password = "";
	std::string firstName = "";
	std::string lastName = "";
	nanodbc::timestamp dateOfCreation = nanodbc::timestamp{};
	int idCreator = 0;
	nanodbc::timestamp dateOfLastChange = nanodbc::timestamp{};
	int idLastChange = 0;
	bool isAdmin;
	bool isDeleted;
	void displayUsers();
	static void deleteUserById(nanodbc::connection& conn, int& id);
};

struct TEAMS {
	int id = 0;
	std::string title = "";
	nanodbc::timestamp dateOfCreation = nanodbc::timestamp{};
	int idCreator = 0;
	nanodbc::timestamp dateOfLastChange = nanodbc::timestamp{};
	int idLastChange = 0;
	bool isDeleted;
	void displayTeams();
	static void deleteTeamById(nanodbc::connection& conn, int& id);
};

struct PROJECTS {
	int id = 0;
	std::string title = "";
	std::string description = "";
	nanodbc::timestamp dateOfCreation = nanodbc::timestamp{};
	int idCreator = 0;
	nanodbc::timestamp dateOfLastChange = nanodbc::timestamp{};
	int idLastChange = 0;
	bool isDeleted;
	void displayProjects();
	static void deleteProjectById(nanodbc::connection& conn, int& id);
};

enum class TASK_STATUS {
	PENDING,
	IN_PROGRESS,
	COMPLETED
};

struct TASKS {
	int id = 0;
	int projectId = 0;
	int userId = 0;
	std::string title = "";
	std::string description = "";
	TASK_STATUS status;
	nanodbc::timestamp dateOfCreation = nanodbc::timestamp{};
	int idCreator = 0;
	nanodbc::timestamp dateOfLastChange = nanodbc::timestamp{};
	int idLastChange = 0;
	bool isDeleted;
	void displayTasks();
	static void deleteTaskById(nanodbc::connection& conn, int& id);
};

struct LOGS {
	int id = 0;
	int taskId = 0;
	int userId = 0;
	int time = 0;
	nanodbc::date date;	
	bool isDeleted;
	void displayLogs();
	static void deleteLogById(nanodbc::connection& conn, int& id);
};



#define RESET   "\033[0m"
#define RED     "\033[1;91m" 
#define GREEN   "\033[1;92m" 
#define YELLOW  "\033[1;93m"  
#define BLUE    "\033[1;96m"
#define PURPLE  "\033[1;95m"
#define WHITE   "\033[4;37m"
#define ANIMATION_ENABLED true