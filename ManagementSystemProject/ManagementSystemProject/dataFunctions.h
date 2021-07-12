#pragma once
#include <nanodbc.h>
#include <iostream>
#include <string>
#include <vector>
#include <exception> 
#include "dataStructures.h"

struct USER;

int cinNumber();
std::string cinLine();

//users
void createUser(nanodbc::connection conn);
void editUser(nanodbc::connection conn);
std::vector<USER> getUsers(nanodbc::connection conn);
void listAllUsers(nanodbc::connection conn);

//teams
void createTeam(nanodbc::connection conn);
void editTeam(nanodbc::connection conn);
std::vector<TEAMS> getTeams(nanodbc::connection conn);
void listAllTeams(nanodbc::connection conn); 

//projects
void createProject(nanodbc::connection conn);
void editProject(nanodbc::connection conn);
std::vector<PROJECTS> getProjects(nanodbc::connection conn);
void listAllProjects(nanodbc::connection conn);

//tasks
void createTask(nanodbc::connection conn);
void editTask(nanodbc::connection conn);
std::vector<TASKS> getTasks(nanodbc::connection conn);
void listAllTasks(nanodbc::connection conn);

//logs
void createLog(nanodbc::connection conn);
void editLog(nanodbc::connection conn);
std::vector<LOGS> getLogs(nanodbc::connection conn);
void listAllLogs(nanodbc::connection conn);