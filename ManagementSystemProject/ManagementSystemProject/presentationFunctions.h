#pragma once
#include <nanodbc.h>
#include <iostream>
#include <string>
#include <vector>
#include <exception> 

void wait(int delay = 350);
bool menu(nanodbc::connection conn);