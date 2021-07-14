#pragma once
#include <nanodbc.h>
#include <iostream>
#include <string>
#include <vector>
#include <exception> 

struct USER;
struct TEAMS;
struct PROJECTS;
struct TASKS;
struct LOGS;

void wait(int delay = 350);
bool adminOptions(nanodbc::connection conn, USER& user);
bool userOptions(nanodbc::connection conn, USER& user);
void loginMenu(nanodbc::connection conn, USER& user);
void displayLogsManagement();
bool logManagement(nanodbc::connection conn, USER& user);