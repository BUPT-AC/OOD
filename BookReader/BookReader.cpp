/*
 Design the data structure for an online book reader system
*/

// the collection of books
class Library
{
private:
	map<string, Book> books;

public:
	void addBook(string id, Book book);
	void updateBook(string id, Book book);
	void selectBook(string id);
	void deleteBook(string id);

	/* data */
};

class Book
{
	string bookId;
	string name;
	vector<string> body;
	size_t cur_page, total_page;
public:
	Book(string id, string content);
	~Book();

	string getId();
	strign getName();
	string getContent();
	void setContent();
};

class User
{
private:
	size_t userId;
	string username;
	bool member;
	float money;
public:
	User(size_t id, string username);
	~User();

	void addMoney(float m);
	void renewMember();
	size_t getId();
	string getUsername();
	void setUsername(string name);
	bool isMember();
	string readPage(size_t page);
	string readNext(); 
	
};

// the collection of users
class UserManager
{
private:
	map<size_t,User> users;
public:
	void addUser(size_t id, User u);
	void updateUser(size_t id, User u);
	User selectUser(size_t id);
	void deleteUser(size_t id);

};

// the wrapper class for all
class OnlineSystem
{
private:
	UserManager users;
	Library books;
	Book activeBook;
	User activeUser;

public:
	Library getLib();
	UserManager getUsers();
	Book getBook();
	User getUser();

	void setActiveBook(Book b);
	void setActiveUser(User u);
};