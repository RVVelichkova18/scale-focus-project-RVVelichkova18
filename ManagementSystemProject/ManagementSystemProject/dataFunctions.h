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
void createUser(nanodbc::connection conn);
void editUser(nanodbc::connection conn);
std::vector<USER> getAllUsers(nanodbc::connection conn);