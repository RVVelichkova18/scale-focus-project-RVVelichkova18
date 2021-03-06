#include <nanodbc.h>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <exception> 
#include "dataFunctions.h"
#include "dataStructures.h"
using namespace std;

struct USER;
struct TEAMS;
struct PROJECTS;
struct TASKS;
struct LOGS;

//functions for geting input
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

std::string timestampToString(nanodbc::timestamp ts)
{
	return std::to_string(ts.year) + "-" + std::to_string(ts.month)
		+ "-" + std::to_string(ts.day) + " " + std::to_string(ts.hour)
		+ ":" + std::to_string(ts.min) + ":" + std::to_string(ts.sec);
}

//functions managing users
void USER::displayUsers()
{
	wait(400);
	spaces(32); cout << PURPLE << " ________________________________________________________________" << RESET << endl;
	spaces(38); cout << "User id: " << this->id << endl;
	spaces(38); cout << "Username: " << this->username << endl;
	spaces(38); cout << "First Name: " << this->firstName << endl;
	spaces(38); cout << "Last Name: " << this->lastName << endl;
	spaces(38); cout << "Date of creation: " << timestampToString(this->dateOfCreation) << endl;
	spaces(38); cout << "Id of the creator: " << this->idCreator << endl;
	spaces(38); cout << "Date of last change: " << timestampToString(this->dateOfLastChange) << endl;
	spaces(38); cout << "Id of the last changer: " << this->idLastChange << endl;
}
void createUser(nanodbc::connection conn)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        INSERT INTO
           [ManagementSystemProject].[dbo].[Users]
            (Username, Password, FirstName, LastName, DateOfCreation, IdCreator, DateOfLastChange, IdLastChange, isAdmin)
            VALUES
            ( ?, ?, ?, ?, GETDATE(), 1,GETDATE(), 1,0)
    )"));
	cout << endl;
	spaces(32); cout << " ________________________________________________________________" << endl;
	cout << endl;
	spaces(38); cout << "Enter the username: ";
	const string username = cinLine();
	statement.bind(0, username.c_str());
	spaces(38); cout << "Enter the password: ";
	const string password = cinLine();
	statement.bind(1, password.c_str());
	spaces(38); cout << "Enter the first name: ";
	const string firstName = cinLine();
	statement.bind(2, firstName.c_str());
	spaces(38); cout << "Enter the last name: ";
	const string lastName = cinLine();
	statement.bind(3, lastName.c_str());

	execute(statement);
}
void editUser(nanodbc::connection conn)
{

	nanodbc::statement statement(conn);

	spaces(38); cout << "Enter id of the user that you want edit: " << endl;
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
	  WHERE Id=? AND isDeleted<>1
    )"));

	spaces(32); cout << "Enter the username: "; const string username = cinLine();
	statement.bind(0, username.c_str());

	spaces(32); cout << "Enter the password: "; const string password = cinLine();
	statement.bind(1, password.c_str());

	spaces(32); cout << "Enter the first name: "; const string firstName = cinLine();
	statement.bind(2, firstName.c_str());

	spaces(32); cout << "Enter the last name: "; const string lastName = cinLine();
	statement.bind(3, lastName.c_str());

	spaces(32); cout << "Enter the id of the person that did the last change: "; const int idLastChange = cinNumber();
	statement.bind(4, &idLastChange);

	statement.bind(5, &id);

	execute(statement);
}
vector<USER> getUsers(nanodbc::connection conn)
{
	vector<USER> users;

	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT *
            FROM [ManagementSystemProject].[dbo].[Users]
			WHERE isDeleted<>1
			
    )"));

	auto result = execute(statement);

	while (result.next())
	{
		USER user;
		user.id = result.get<int>("Id");
		user.username = result.get<nanodbc::string>("Username", "");
		user.firstName = result.get<nanodbc::string>("FirstName", "");
		user.lastName = result.get<nanodbc::string>("LastName", "");
		user.dateOfCreation = result.get<nanodbc::timestamp>("DateOfCreation", nanodbc::timestamp{});
		user.idCreator = result.get<int>("IdCreator", 0);
		user.dateOfLastChange = result.get<nanodbc::timestamp>("DateOfLastChange", nanodbc::timestamp{});
		user.idLastChange = result.get<int>("IdLastChange", 0);
		user.isAdmin = result.get<int>("isAdmin");

		users.push_back(user);
	}

	return users;
}
void listAllUsers(nanodbc::connection conn)
{
	vector<USER> users = getUsers(conn);

	for (size_t i = 0; i < users.size(); i++)
	{
		users[i].displayUsers();
	}

}
void USER::deleteUserById(nanodbc::connection& conn, int& id)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
			UPDATE Users
			SET isDeleted = 1
            WHERE Id = ?
    )"));
	statement.bind(0, &id);
	auto result = execute(statement);

}
void deleteUser(nanodbc::connection conn)
{

	nanodbc::statement statement(conn);
	spaces(38); cout << "Enter id of the user that you want edit: " << endl;
	int id = cinNumber();

	USER::deleteUserById(conn, id);
	cout << endl;
	spaces(38); cout << GREEN << "Deleted successfully!" << endl;
}
int countUsers(nanodbc::connection conn)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT COUNT(Id) AS Count
            FROM [ManagementSystemProject].[dbo].[Users]
			WHERE isDeleted<>1
			
    )"));

	auto result = execute(statement);
	int usersCount = 0;
	if (result.next()) {
		usersCount = result.get<int>("Count");
	}

	return usersCount;
}

//functions managing teams
void TEAMS::displayTeams()
{
	wait(400);
	spaces(32); cout << PURPLE << " ________________________________________________________________" << RESET << endl;
	spaces(38); cout << "Team id: " << this->id << endl;
	spaces(38); cout << "Title: " << this->title << endl;
	spaces(38); cout << "Date of creation: " << timestampToString(this->dateOfCreation) << endl;
	spaces(38); cout << "Id of the creator: " << this->idCreator << endl;
	spaces(38); cout << "Date of last change: " << timestampToString(this->dateOfLastChange) << endl;
	spaces(38); cout << "Id of the last changer: " << this->idLastChange << endl;
}
void createTeam(nanodbc::connection conn)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        INSERT INTO
           [ManagementSystemProject].[dbo].[Teams]
            (Title, DateOfCreation, IdCreator, DateLastChange, IdLastCHange)
            VALUES
            ( ?, GETDATE(), ?, GETDATE(), ?)
    )"));
	cout << endl;
	spaces(32); cout << " ________________________________________________________________" << endl;
	cout << endl;
	spaces(38); cout << "Enter team's name: ";
	const string title = cinLine();
	statement.bind(0, title.c_str());

	spaces(38); cout << "Enter the id of the creator: ";
	const int idCreator = cinNumber();
	statement.bind(1, &idCreator);

	spaces(38); cout << "Enter the id of the person that did the last change: ";
	const int idLastChange = cinNumber();
	statement.bind(2, &idLastChange);

	execute(statement);
}
void editTeam(nanodbc::connection conn)
{

	nanodbc::statement statement(conn);

	spaces(38); cout << "Enter id of the team that you want edit: " << endl;
	const int id = cinNumber();
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
      UPDATE [ManagementSystemProject].[dbo].[Teams]
	  SET
			Title = ?
			,DateLastChange = GETDATE()
			,IdLastChange = ?
	  WHERE Id=? AND isDeleted<>1
    )"));

	spaces(32); cout << "Enter the team's new name: "; const string title = cinLine();
	statement.bind(0, title.c_str());

	spaces(32); cout << "Enter the id of the person that did the last change: "; const int idLastChange = cinNumber();
	statement.bind(1, &idLastChange);

	statement.bind(2, &id);

	execute(statement);
}
vector<TEAMS> getTeams(nanodbc::connection conn)
{
	vector<TEAMS> teams;

	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT *
            FROM [ManagementSystemProject].[dbo].[Teams]
			WHERE isDeleted<>1
    )"));

	auto result = execute(statement);

	while (result.next())
	{
		TEAMS team;
		team.id = result.get<int>("Id");
		team.title = result.get<nanodbc::string>("Title", "");
		team.dateOfCreation = result.get<nanodbc::timestamp>("DateOfCreation", nanodbc::timestamp{});
		team.idCreator = result.get<int>("IdCreator", 0);
		team.dateOfLastChange = result.get<nanodbc::timestamp>("DateLastChange", nanodbc::timestamp{});
		team.idLastChange = result.get<int>("IdLastChange", 0);

		teams.push_back(team);
	}

	return teams;
}
void listAllTeams(nanodbc::connection conn)
{
	vector<TEAMS> teams = getTeams(conn);

	for (size_t i = 0; i < teams.size(); i++)
	{
		teams[i].displayTeams();
	}

}
void TEAMS::deleteTeamById(nanodbc::connection& conn, int& id)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
			UPDATE Teams
			SET isDeleted = 1
            WHERE Id = ?
    )"));
	statement.bind(0, &id);
	auto result = execute(statement);

}
void deleteTeam(nanodbc::connection conn)
{

	nanodbc::statement statement(conn);
	spaces(38); cout << "Enter id of the team that you want delete: " << endl;
	int id = cinNumber();

	TEAMS::deleteTeamById(conn, id);
	cout << endl;
	spaces(38); cout << GREEN << "Deleted successfully!" << endl;
}
int countTeams(nanodbc::connection conn)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT COUNT(Id) AS Count
            FROM [ManagementSystemProject].[dbo].[Teams]
			WHERE isDeleted<>1
			
    )"));

	auto result = execute(statement);
	int teamsCount = 0;
	if (result.next()) {
		teamsCount = result.get<int>("Count");
	}

	return teamsCount;
}

//functions managing projects
void PROJECTS::displayProjects()
{
	wait(400);
	spaces(32); cout << PURPLE << " ________________________________________________________________" << RESET << endl;
	spaces(38); cout << "Project id: " << this->id << endl;
	spaces(38); cout << "Title: " << this->title << endl;
	spaces(38); cout << "Description: " << this->description << endl;
	spaces(38); cout << "Date of creation: " << timestampToString(this->dateOfCreation) << endl;
	spaces(38); cout << "Id of the creator: " << this->idCreator << endl;
	spaces(38); cout << "Date of last change: " << timestampToString(this->dateOfLastChange) << endl;
	spaces(38); cout << "Id of the last changer: " << this->idLastChange << endl;
}
void createProject(nanodbc::connection conn)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        INSERT INTO
           [ManagementSystemProject].[dbo].[Projects]
            (Title, Description, DateOfCreation, IdCreator, DateLastChange, IdLastCHange)
            VALUES
            ( ?, ?, GETDATE(), ?, GETDATE(), ?)
    )"));
	cout << endl;
	spaces(32); cout << " ________________________________________________________________" << endl;
	cout << endl;
	spaces(38); cout << "Enter project's name: ";
	const string title = cinLine();
	statement.bind(0, title.c_str());

	spaces(38); cout << "Enter project's description: ";
	const string description = cinLine();
	statement.bind(1, description.c_str());

	spaces(38); cout << "Enter the id of the creator: ";
	const int idCreator = cinNumber();
	statement.bind(2, &idCreator);

	spaces(38); cout << "Enter the id of the person that did the last change: ";
	const int idLastChange = cinNumber();
	statement.bind(3, &idLastChange);

	execute(statement);
}
void editProject(nanodbc::connection conn, const int& id)
{
	
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
      UPDATE [ManagementSystemProject].[dbo].[Projects]
	  SET
			Title = ?
			,Description = ?
			,DateLastChange = GETDATE()
			,IdLastChange = ?
	  WHERE Id=? AND isDeleted<>1
    )"));

	spaces(32); cout << "Enter the title: "; const string title = cinLine();
	statement.bind(0, title.c_str());

	spaces(32); cout << "Enter description: "; const string description = cinLine();
	statement.bind(1, description.c_str());

	spaces(32); cout << "Enter the id of the person that did the last change: "; const int idLastChange = cinNumber();
	statement.bind(2, &idLastChange);

	statement.bind(3, &id);

	execute(statement);
}
vector<PROJECTS> getProjects(nanodbc::connection conn)
{
	vector<PROJECTS> projects;

	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT *
            FROM [ManagementSystemProject].[dbo].[Projects]
			WHERE isDeleted<>1
    )"));

	auto result = execute(statement);

	while (result.next())
	{
		PROJECTS project;
		project.id = result.get<int>("Id");
		project.title = result.get<nanodbc::string>("Title", "");
		project.description = result.get<nanodbc::string>("Description", "");
		project.dateOfCreation = result.get<nanodbc::timestamp>("DateOfCreation", nanodbc::timestamp{});
		project.idCreator = result.get<int>("IdCreator", 0);
		project.dateOfLastChange = result.get<nanodbc::timestamp>("DateLastChange", nanodbc::timestamp{});
		project.idLastChange = result.get<int>("IdLastChange", 0);

		projects.push_back(project);
	}

	return projects;
}
void listAllProjects(nanodbc::connection conn)
{
	vector<PROJECTS> projects = getProjects(conn);

	for (size_t i = 0; i < projects.size(); i++)
	{
		projects[i].displayProjects();
	}

}
void PROJECTS::deleteProjectById(nanodbc::connection& conn, int& id)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
			UPDATE Projects
			SET isDeleted = 1
            WHERE Id = ?
    )"));
	statement.bind(0, &id);
	auto result = execute(statement);

}
PROJECTS getProjectById(nanodbc::connection conn, int& id)
{

	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT *
            FROM [ManagementSystemProject].[dbo].[Projects]
		WHERE Id=?
    )"));

	statement.bind(0, &id);
	auto result = execute(statement);
	PROJECTS project;
	if (!result.next());
	else {

		project.id = result.get<int>("Id");
		project.title = result.get<nanodbc::string>("Title", "");
		project.description = result.get<nanodbc::string>("Description", "");
		project.dateOfCreation = result.get<nanodbc::timestamp>("DateOfCreation", nanodbc::timestamp{});
		project.idCreator = result.get<int>("IdCreator", 0);
		project.dateOfLastChange = result.get<nanodbc::timestamp>("DateLastChange", nanodbc::timestamp{});
		project.idLastChange = result.get<int>("IdLastChange", 0);
	}

	return project;
}
int countProjects(nanodbc::connection conn)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT COUNT(Id) AS Count
            FROM [ManagementSystemProject].[dbo].[Projects]
			WHERE isDeleted<>1
			
    )"));

	auto result = execute(statement);
	int projectsCount = 0;
	if (result.next()) {
		projectsCount = result.get<int>("Count");
	}

	return projectsCount;
}

//functions managing tasks
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
	wait(400);
	spaces(32); cout << PURPLE << " ________________________________________________________________" << RESET << endl;
	spaces(38); cout << "Task id: " << this->id << endl;
	spaces(38); cout << "Project id: " << this->projectId << endl;
	spaces(38); cout << "User id: " << this->userId << endl;
	spaces(38); cout << "Title: " << this->title << endl;
	spaces(38); cout << "Description: " << this->description << endl;
	spaces(38); cout << "Status: " << getTaskStatusName(this->status) << endl;
	spaces(38); cout << "Date of creation: " << timestampToString(this->dateOfCreation) << endl;
	spaces(38); cout << "Id of the creator: " << this->idCreator << endl;
	spaces(38); cout << "Date of last change: " << timestampToString(this->dateOfLastChange) << endl;
	spaces(38); cout << "Id of the last changer: " << this->idLastChange << endl;

}
void createTask(nanodbc::connection conn)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        INSERT INTO
           [ManagementSystemProject].[dbo].[Tasks]
            (ProjectId, UserId, Title, Description, DateOfCreation, Status, IdCreator, DateLastChange, IdLastCHange)
            VALUES
            ( ?, ?, ?, ?, GETDATE(), ?, ?, GETDATE(), ?)
    )"));
	cout << endl;
	spaces(32); cout << " ________________________________________________________________" << endl;
	cout << endl;
	spaces(38); cout << "Enter project id: ";
	const int projectId = cinNumber();
	statement.bind(0, &projectId);

	spaces(38); cout << "Enter assignee id: ";
	const int userId = cinNumber();
	statement.bind(1, &userId);

	spaces(38); cout << "Enter task's name: ";
	const string title = cinLine();
	statement.bind(2, title.c_str());

	spaces(38); cout << "Enter task's description: ";
	const string description = cinLine();
	statement.bind(3, description.c_str());

	int status;
	do {
		spaces(38); cout << "Enter task's status (0 - In Progress / 1 - Pending / 2 - Completed): ";
		status = cinNumber();
		if (status >= 0 and status <= 2) {
			break;
		}
		spaces(38); cout <<RED<< "You have to ednter a digit between 0 and 2! Please, try again!" <<RESET<< endl;
		cout << endl;
	}while(true);
	statement.bind(4, &status);

	spaces(38); cout << "Enter the id of the creator: ";
	const int idCreator = cinNumber();
	statement.bind(5, &idCreator);

	spaces(38); cout << "Enter the id of the person that did the last change: ";
	const int idLastChange = cinNumber();
	statement.bind(6, &idLastChange);

	execute(statement);
}
void editTask(nanodbc::connection conn, const int& id)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
      UPDATE [ManagementSystemProject].[dbo].[Tasks]
	  SET
			UserId = ?
			,Title = ?
			,Description = ?
			,Status = ?
			,DateLastChange = GETDATE()
			,IdLastChange = ?
	  WHERE Id=? AND isDeleted<>1
    )"));

	spaces(32); cout << "Enter the id of the new assignee: "; const string userId = cinLine();
	statement.bind(0, userId.c_str());

	spaces(32); cout << "Enter the title: "; const string title = cinLine();
	statement.bind(1, title.c_str());

	spaces(32); cout << "Enter description: "; const string description = cinLine();
	statement.bind(2, description.c_str());
	int status;
	do {
		spaces(32); cout << "Enter task's status (0 - In Progress / 1 - Pending / 2 - Completed): "; status = cinNumber();
		if (status >= 0 and status <= 2) {
			break;
		}
		spaces(32); cout << RED << "You have to ednter a digit between 0 and 2! Please, try again!" << RESET << endl;
		cout << endl;
	} while (true);
	statement.bind(3, &status);

	spaces(32); cout << "Enter the id of the person that did the last change: "; const int idLastChange = cinNumber();
	statement.bind(4, &idLastChange);

	statement.bind(5, &id);

	execute(statement);
}
vector<TASKS> getTasks(nanodbc::connection conn)
{
	vector<TASKS> tasks;

	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT *
            FROM [ManagementSystemProject].[dbo].[Tasks]
			WHERE isDeleted<>1
    )"));

	auto result = execute(statement);

	while (result.next())
	{
		TASKS task;
		task.id = result.get<int>("Id");
		task.projectId = result.get<int>("ProjectId");
		task.userId = result.get<int>("UserId");
		task.title = result.get<nanodbc::string>("Title", "");
		task.description = result.get<nanodbc::string>("Description", "");
		task.status = (TASK_STATUS)result.get<int>("Status");
		task.dateOfCreation = result.get<nanodbc::timestamp>("DateOfCreation", nanodbc::timestamp{});
		task.idCreator = result.get<int>("IdCreator", 0);
		task.dateOfLastChange = result.get<nanodbc::timestamp>("DateLastChange", nanodbc::timestamp{});
		task.idLastChange = result.get<int>("IdLastChange", 0);

		tasks.push_back(task);
	}

	return tasks;
}
void listAllTasks(nanodbc::connection conn)
{
	vector<TASKS> tasks = getTasks(conn);

	for (size_t i = 0; i < tasks.size(); i++)
	{
		tasks[i].displayTasks();
	}

}
void TASKS::deleteTaskById(nanodbc::connection& conn, int& id)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
			UPDATE Tasks
			SET isDeleted = 1
            WHERE Id = ?
    )"));
	statement.bind(0, &id);
	auto result = execute(statement);

}
TASKS getTaskById(nanodbc::connection conn, int& id)
{

	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT *
            FROM [ManagementSystemProject].[dbo].[Tasks]
		WHERE Id=?
    )"));

	statement.bind(0, &id);
	auto result = execute(statement);
	TASKS task;
	if (!result.next());
	else {

		task.id = result.get<int>("Id");
		task.projectId = result.get<int>("ProjectId");
		task.userId = result.get<int>("UserId");
		task.title = result.get<nanodbc::string>("Title", "");
		task.description = result.get<nanodbc::string>("Description", "");
		task.status = (TASK_STATUS)result.get<int>("Status");
		task.dateOfCreation = result.get<nanodbc::timestamp>("DateOfCreation", nanodbc::timestamp{});
		task.idCreator = result.get<int>("IdCreator", 0);
		task.dateOfLastChange = result.get<nanodbc::timestamp>("DateLastChange", nanodbc::timestamp{});
		task.idLastChange = result.get<int>("IdLastChange", 0);
	}

	return task;
}
int countTasks(nanodbc::connection conn)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT COUNT(Id) AS Count
            FROM [ManagementSystemProject].[dbo].[Tasks]
			WHERE isDeleted<>1
			
    )"));

	auto result = execute(statement);
	int tasksCount = 0;
	if (result.next()) {
		tasksCount = result.get<int>("Count");
	}

	return tasksCount;
}

//functions managing work logs
void LOGS::displayLogs()
{
	wait(400);
	spaces(32); cout << PURPLE << " ________________________________________________________________" << RESET << endl;
	spaces(38); cout << "Log id: " << this->id << endl;
	spaces(38); cout << "Task id: " << this->taskId << endl;
	spaces(38); cout << "User id: " << this->userId << endl;
	spaces(38); cout << "Time: " << this->time << endl;
	spaces(38); cout << "Date: " << this->date.year << "-"<<this->date.month << "-" << this->date.day << endl;
}
void createLog(nanodbc::connection conn)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        INSERT INTO
           [ManagementSystemProject].[dbo].[WorkLog]
            (TaskId, UserId, Time, Date)
            VALUES
            ( ?, ?, ?, ?)
    )"));
	cout << endl;
	spaces(32); cout << " ________________________________________________________________" << endl;
	cout << endl;
	spaces(38); cout << "Enter task id: ";
	const int taskId = cinNumber();
	statement.bind(0, &taskId);

	spaces(38); cout << "Enter assignee id: ";
	const int userId = cinNumber();
	statement.bind(1, &userId);

	spaces(38); cout << "Enter working hours: ";
	const int time = cinNumber();
	statement.bind(2, &time);

	nanodbc::date date;

	spaces(38); cout << "Enter year: ";
	date.year = cinNumber();

	spaces(38); cout << "Enter month: ";
	date.month = cinNumber();

	spaces(38); cout << "Enter day: ";
	date.day = cinNumber();


	statement.bind(3, &date);
	spaces(32); cout << " ________________________________________________________________" << endl;
	execute(statement);
}
void editLog(nanodbc::connection conn, const int& id)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
      UPDATE [ManagementSystemProject].[dbo].[WorkLog]
	  SET
			TaskId = ?
			,UserId = ?
			,Time = ?
			,Date = ?
	  WHERE Id=? AND isDeleted<>1
    )"));

	spaces(32); cout << "Enter the id of the new task: "; const string taskId = cinLine();
	statement.bind(0, taskId.c_str());

	spaces(32); cout<< "Enter the id of the new assignee:: "; const string userId = cinLine();
	statement.bind(1, userId.c_str());

	spaces(32); cout << "Enter working hours: "; const string time = cinLine();
	statement.bind(2, time.c_str());

	spaces(32); cout << "Enter  the date when you are going to work: "; const string date = cinLine();
	statement.bind(3, date.c_str());

	statement.bind(4, &id);

	execute(statement);
}
vector<LOGS> getLogs(nanodbc::connection conn)
{
	vector<LOGS> logs;

	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT *
            FROM [ManagementSystemProject].[dbo].[WorkLog]
			WHERE isDeleted<>1
    )"));

	auto result = execute(statement);

	while (result.next())
	{
		LOGS log;
		log.id = result.get<int>("Id");
		log.taskId = result.get<int>("TaskId");
		log.userId = result.get<int>("UserId");
		log.time = result.get<int>("Time");
		log.date = result.get<nanodbc::date>("Date");

		logs.push_back(log);
	}

	return logs;
}
void listAllLogs(nanodbc::connection conn)
{
	vector<LOGS> logs = getLogs(conn);

	for (size_t i = 0; i < logs.size(); i++)
	{
		logs[i].displayLogs();
	}

}
void LOGS::deleteLogById(nanodbc::connection& conn, int& id)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
			UPDATE WorkLog
			SET isDeleted = 1
            WHERE Id = ?
    )"));
	statement.bind(0, &id);
	auto result = execute(statement);

}
LOGS getLogById(nanodbc::connection conn, int& id)
{

	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT *
            FROM [ManagementSystemProject].[dbo].[WorkLog]
		WHERE Id=?
    )"));

	statement.bind(0, &id);
	auto result = execute(statement);
	LOGS log;
	if (!result.next());
	else {

		log.id = result.get<int>("Id");
		log.taskId = result.get<int>("TaskId");
		log.userId = result.get<int>("UserId");
		log.time = result.get<int>("Time");
		log.date = result.get<nanodbc::date>("Date");
	}

	return log;
}
LOGS getLogByTaskId(nanodbc::connection conn, int& taskId)
{

	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT *
            FROM [ManagementSystemProject].[dbo].[WorkLog]
		WHERE TaskId = ?
    )"));

	statement.bind(0, &taskId);
	auto result = execute(statement);
	LOGS log;
	if (!result.next());
	else {

		log.id = result.get<int>("Id");
		log.taskId = result.get<int>("TaskId");
		log.userId = result.get<int>("UserId");
		log.time = result.get<int>("Time");
		log.date = result.get<nanodbc::date>("Date");
	}

	return log;
}
int countLogs(nanodbc::connection conn)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT COUNT(Id) AS Count
            FROM [ManagementSystemProject].[dbo].[WorkLog]
			WHERE isDeleted<>1
			
    )"));

	auto result = execute(statement);
	int logsCount = 0;
	if (result.next()) {
		logsCount = result.get<int>("Count");
	}

	return logsCount;
}


//
//void enterPassword(string* code)
//{
// char star;
//	star = _getch();
//while (star != 13) {
//	if (star == 8) {
//		if (password.length() > 0) {
//			cout << "/b /b";
//			password.pop_back();
//		}
//	}
//	else {
//		cout << "*";
//		password = star;
//	}
//	star = _getch();
//}
//}

//functions for authentication
USER loginDataCheck(nanodbc::connection conn, string username, string password)
{
	USER user{};

	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        SELECT 
				Id
				, Username
				, Password
				, FirstName
				, LastName
				, DateOfCreation
				, idCreator
				, DateOfLastChange
				, IdLastChange
			    , isAdmin
            FROM Users
        WHERE Username = ? AND Password = ?
    )"));

	statement.bind(0, username.c_str());
	statement.bind(1, password.c_str());

	nanodbc::result result = nanodbc::execute(statement);

	if (result.next())
	{
		user.id = result.get<int>("Id");
		user.username = result.get<nanodbc::string>("Username", "");
		user.password = result.get<nanodbc::string>("Password", "");
		user.firstName = result.get<nanodbc::string>("FirstName", "");
		user.lastName = result.get<nanodbc::string>("LastName", "");
		user.dateOfCreation = result.get<nanodbc::timestamp>("DateOfCreation", nanodbc::timestamp{});
		user.idCreator = result.get<int>("idCreator", 0);
		user.dateOfLastChange = result.get<nanodbc::timestamp>("DateOfLastChange", nanodbc::timestamp{});
		user.idLastChange = result.get<int>("IdLastChange", 0);
		user.isAdmin = result.get<int>("isAdmin");
	}

	return user;
}

