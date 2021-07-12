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
	std::string dateOfCreation = "";
	int idCreator = 0;
	std::string dateOfLastChange = "";
	int idLastChange = 0;
	bool isAdmin;
	void displayUsers();
};

struct TEAMS {
	int id = 0;
	std::string title = "";
	std::string dateOfCreation = "";
	int idCreator = 0;
	std::string dateOfLastChange = "";
	int idLastChange = 0;
	void displayTeams();
};

struct PROJECTS {
	int id = 0;
	std::string title = "";
	std::string description = "";
	std::string dateOfCreation = "";
	int idCreator = 0;
	std::string dateOfLastChange = "";
	int idLastChange = 0;
	void displayProjects();
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
	std::string dateOfCreation = "";
	int idCreator = 0;
	std::string dateOfLastChange = "";
	int idLastChange = 0;
	void displayTasks();
};

struct LOGS {
	int id = 0;
	int taskId = 0;
	int userId = 0;
	int time = 0;
	std::string date = "";
	void displayLogs();
};

#define RESET   "\033[0m"
#define RED     "\033[1;91m" 
#define YELLOW  "\033[1;93m"  
#define PURPLE  "\033[1;95m"
#define ANIMATION_ENABLED true