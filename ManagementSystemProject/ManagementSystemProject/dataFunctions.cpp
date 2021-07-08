#include <nanodbc.h>
#include <iostream>
#include <string>
#include <vector>
#include <exception> 
#include "dataFunctions.h"
#include "dataStructures.h"

using namespace std;

string cinLine()
{
	//cin.ignore(1, '\n');
	string line;
	getline(cin, line);
	return line;
}

int cinNumber()
{
	//cin.ignore(1, '\n');
	string line;
	getline(cin, line);
	return stoi(line);
}

void USER::displayUsers()
{
	cout << "User id: " << this->id << endl;
	cout << "Username: " << this->username << endl;
	cout << "Password: " << this->password << endl;
	cout << "First Name: " << this->firstName << endl;
	cout << "Last Name: " << this->lastName << endl;
	cout << "Date of creation: " << this->dateOfCreation << endl;
	cout << "Id of the creator: " << this->idCreator << endl;
	cout << "Date of last change: " << this->dateOfLastChange << endl;
	cout << "Id of the last changer: " << this->idLastChange << endl;
}
void TEAMS::displayTeams()
{
	cout << "Team id: " << this->id << endl;
	cout << "Title: " << this->title << endl;
	cout << "Date of creation: " << this->dateOfCreation << endl;
	cout << "Id of the creator: " << this->idCreator << endl;
	cout << "Id of the last changer: " << this->idLastChange << endl;
}
void PROJECTS::displayProjects()
{
	cout << "Project id: " << this->id << endl;
	cout << "Title: " << this->title << endl;
	cout << "Description: " << this->description << endl;
	cout << "Date of creation: " << this->dateOfCreation << endl;
	cout << "Id of the creator: " << this->idCreator << endl;
	cout << "Id of the last changer: " << this->idLastChange << endl;
}

string getTaskStatusName(TASK_STATUS& ts)
{
	switch (ts)
	{
	case TASK_STATUS::PENDING: return "pending";
	case TASK_STATUS::IN_PROGRESS: return "in progress";
	case TASK_STATUS::COMPLETED: return "completed";
	};
}

void TASKS::displayTasks()
{
	cout << "Task id: " << this->id << endl;
	cout << "Project id: " << this->projectId << endl;
	cout << "User id: " << this->userId << endl;
	cout << "Title: " << this->title << endl;
	cout << "Description: " << this->description << endl;
	cout << "Status: " << getTaskStatusName(this->status) << endl;
	cout << "Date of creation: " << this->dateOfCreation << endl;
	cout << "Id of the creator: " << this->idCreator << endl;
	cout << "Id of the last changer: " << this->idLastChange << endl;

	// task.status = (TASK_STATUS)result.get<int>("Status")

}

void LOGS::displayLogs() {
	cout << "Log id: " << this->id << endl;
	cout << "Task id: " << this->taskId << endl;
	cout << "User id: " << this->userId << endl;
	cout << "Time: " << this->time << endl;
	cout << "Date: " << this->date << endl;
}



void createUser(nanodbc::connection conn)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        INSERT INTO
           [ManagementSystemProject].[dbo].[Users]
            (username, password, FirstName, LastName, DateOfCreation, IdCreator, DateOfLastChange, IdLastChange, isAdmin)
            VALUES
            ( ?, ?, ?, ?, GETDATE(), ?,GETDATE(), ?,0)
    )"));

	cout << "Enter the username: ";
	const string username = cinLine();
	statement.bind(0, username.c_str());
	cout << "Enter the password: ";
	const string password = cinLine();
	statement.bind(1, password.c_str());
	cout << "Enter the first name: ";
	const string firstName = cinLine();
	statement.bind(2, firstName.c_str());
	cout << "Enter the last name: ";
	const string lastName = cinLine();
	statement.bind(3, lastName.c_str());
	cout << "Enter the id of the creator: ";
	const int idCreator = cinNumber();
	statement.bind(4, &idCreator);
	cout << "Enter the id of the person that did the last change: ";
	const int idLastChange = cinNumber();
	statement.bind(5, &idLastChange);

	execute(statement);
}


void editUser(nanodbc::connection conn)
{

	nanodbc::statement statement(conn);
	
	cout << "Enter id of the user that you want edit: " << endl;
	const int id = cinNumber();
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
      UPDATE [ManagementSystemProject].[dbo].[Users]
	  SET
			Username = ?
			,Password = ?
			,FirstName = ?
			,LastName = ?
			,DateOfLastChange = GETDATE()
			,IdLastChange = ?
	  WHERE Id=?;
    )"));

	cout << "Enter the username: ";
	const string username = cinLine();
	statement.bind(0, username.c_str());

	cout << "Enter the password: ";
	const string password = cinLine();
	statement.bind(1, password.c_str());

	cout << "Enter the first name: ";
	const string firstName = cinLine();
	statement.bind(2, firstName.c_str());

	cout << "Enter the last name: ";
	const string lastName = cinLine();
	statement.bind(3, lastName.c_str());

	cout << "Enter the id of the person that did the last change: ";
	const int idLastChange = cinNumber();
	statement.bind(4, &idLastChange);

	statement.bind(5, &id);

	execute(statement);
}

vector<USER> getAllUsers(nanodbc::connection conn)
{
	vector<USER> users;

	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT *
            FROM [ManagementSystemProject].[dbo].[Users]
    )"));

	auto result = execute(statement);

	while (result.next())
	{
		USER user;
		user.id = result.get<int>("Id");
		user.username = result.get<nanodbc::string>("Username", "");
		user.password = result.get<nanodbc::string>("Password", "");
		user.firstName = result.get<nanodbc::string>("FirstName", "");
		user.lastName = result.get<nanodbc::string>("LastName", "");
		user.dateOfCreation = result.get<nanodbc::string>("DateOfCreation", "");
		user.idCreator = result.get<int>("Id",0);
		user.dateOfCreation = result.get<nanodbc::string>("DateOfCreation", "");
		user.idLastChange = result.get<int>("Id",0);
		user.isAdmin = result.get<int>("isAdmin");
		

		users.push_back(user);
	}

	return users;
}