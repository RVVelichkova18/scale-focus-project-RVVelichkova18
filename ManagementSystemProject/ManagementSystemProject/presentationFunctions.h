#pragma once
#include <nanodbc.h>
#include <iostream>
#include <string>
#include <vector>
#include <exception> 

struct USER;

void wait(int delay = 350);
bool adminOptions(nanodbc::connection conn);
void loginMenu(nanodbc::connection conn, USER& user);