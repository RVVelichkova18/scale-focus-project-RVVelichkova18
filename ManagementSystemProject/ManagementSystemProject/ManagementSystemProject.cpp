#include <nanodbc.h>
#include <iostream>
#include <string>
#include <vector>
#include <exception> 
#include "dataStructures.h"
using namespace std;

int main() {
	system("chcp 65001");
	system("cls");
	try
	{
		nanodbc::string connstr = NANODBC_TEXT("DRIVER={ODBC Driver 17 for SQL Server};SERVER=DESKTOP-IR9IA03\\SQLExpress;DATABASE=ManagementSystemProject;Trusted_Connection=yes;");
		nanodbc::connection conn(connstr);
		USER currentUser{};

		loginMenu(conn, currentUser);

		return EXIT_SUCCESS;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

}