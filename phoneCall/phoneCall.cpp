/*
Imagine you hava a call center with three levels of employees: respondent, manager and director. 
An incoming telephone call mush be first allocated to a respondent who is free. If the respondent 
can't handle the call, he or she mush escalate the call to a manager. If a manager is not free or 
not able to handle it, then the call should be secalted to a director. Design the classes and data 
structure for thsi problem. Implement a method dispatchCall() which assigns a call the first available 
employee.
*/

enum Level { Respondent, Manager , Director};
// abstract class for general employee
class Employee
{
protected:
	bool free;
	Level level;
	Call currentCall;
public:
	Employee();
	~Employee();

	void receiveCall(Call c);
	void escalateCall(Call c);
	void callComplete();
	Level getLevel();
	bool isFree();
};

class Director : public Employee
{
public:
	Director();
	~Director();
};

class Manager : public Employee
{
public:
	Manager(arguments);
	~Manager();

	/* data */
};

class Respondent : public Employee
{
public:
	Respondent(arguments);
	~Respondent();
};

class Call
{
private:
	string caller;
	Employee * handler;
	int rank;
public:
	Call();
	~Call();

	void setHandler();
	void setRank();
	int getRank();

	void replay(string message);
};

// a singleton class the handle the whole process

class CallHandler
{
private:
	// dummy numbers
	const int NUM_RESPONDENTS = 10;
	const int NUM_MANAGERS = 10;
	const int NUM_DIRECTORS = 10;
	// employeeList[0] is respondents, employeeList[1] is managers, employeeList[2] is directors
	vector<vector<Employee *>> employeeList (3, std::vector<Employee *> ());
	// based on the call's value
	priority_queue<Call> callQueues;

	CallHandler();
	~CallHandler();
public:
	static CallHandler& getInstance(){
		static CallHandler instance;
		return instance;
	}

	Employee * getHandlerForCall(Call c);
	coid dispatchCall(Call c);

	/* data */
};