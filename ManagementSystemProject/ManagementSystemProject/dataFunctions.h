#pragma once
#include <nanodbc.h>
#include <iostream>
#include <string>
#include <vector>
#include <exception> 
#include "dataStructures.h"

struct USER;
struct TEAMS;
struct PROJECTS;
struct TASKS;
struct LOGS;

std::string timestampToString(nanodbc::timestamp);



int cinNumber();
std::string cinLine();
//user
void createUser(nanodbc::connection conn);
void editUser(nanodbc::connection conn);
std::vector<USER> getUsers(nanodbc::connection conn);
void listAllUsers(nanodbc::connection conn);
void deleteUser(nanodbc::connection conn);
int countUsers(nanodbc::connection conn);

//teams
void createTeam(nanodbc::connection conn);
void editTeam(nanodbc::connection conn);
std::vector<TEAMS> getTeams(nanodbc::connection conn);
void listAllTeams(nanodbc::connection conn); 
void deleteTeam(nanodbc::connection conn);
int countTeams(nanodbc::connection conn);

//projects
void createProject(nanodbc::connection conn);
void editProject(nanodbc::connection conn, const int& id);
std::vector<PROJECTS> getProjects(nanodbc::connection conn);
void listAllProjects(nanodbc::connection conn);
PROJECTS getProjectById(nanodbc::connection conn, int& id);
int countProjects(nanodbc::connection conn);

//tasks
void createTask(nanodbc::connection conn);
void editTask(nanodbc::connection conn, const int& id);
std::vector<TASKS> getTasks(nanodbc::connection conn);
void listAllTasks(nanodbc::connection conn);
TASKS getTaskById(nanodbc::connection conn, int& id);
int countTasks(nanodbc::connection conn);

//logs
void createLog(nanodbc::connection conn);
void editLog(nanodbc::connection conn, const int& id);
std::vector<LOGS> getLogs(nanodbc::connection conn);
void listAllLogs(nanodbc::connection conn);
LOGS getLogById(nanodbc::connection conn, int& id);
LOGS getLogByTaskId(nanodbc::connection conn, int& taskId);
int countLogs(nanodbc::connection conn);

//login
USER loginDataCheck(nanodbc::connection conn, std::string username, std::string pass);
