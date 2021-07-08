#pragma once
#include <nanodbc.h>
#include <iostream>
#include <string>
#include <vector>
#include <exception> 
#include <exception> 
#include "dataStructures.h"

int cinNumber();
std::string cinLine();
void displayUsers();
void displayTeams();
void displayProjects();
void displayTasks();
void displayLog();
void createUser(nanodbc::connection conn);
void editUser(nanodbc::connection conn);