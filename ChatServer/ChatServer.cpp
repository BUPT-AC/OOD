/*
Description: Design a chat server.
Supposed functionalities:
1. Signing
2. Add requests
3. Updating message status
4. creating private and group chats
5. add new messages to chats
*/

// a singleton class for managing users
class UserManager
 {

 private:
 	UserManager();
 	map<int, User> users;
 public:
 	static UserManager& getInstance(){
 		static UserManager instance;
 		return instance;
 	}
 	
 	void addUser(User);
 	void userSignOn(User );
 	void userSignOff(User);

 }; 

 class User
 {
 private:
 	int id;
 	UserStatus status;
 	map<int, PrivateChat> privateChats;
 	vector<GroupChat> groupChats;

 	map<int,User> contacts;
 public:
 	User(int ID);
 	~User();
 	bool SentMessageTo(User, string);
 	bool SentToGroup(int id, string);
 	void setStatus();
 	UserStatus getStatus();
 	bool addContact(User);
 	void addConversation(PrivateChat );
 	void addConversation(GroupChat );
 
 	/* data */
 };

 class Conversation
 {
 protected:
 	set<User> users;
 	int id;
 	vector<string> messages;

 public:
 	vector<string> getMessages();
 	bool addMessage(string);
 	int getId();
 	Conversation(arguments);
 	~Conversation();
 };

 class PrivateChat : public Conversation
 {

 public:
 	PrivateChat(User, User);
 };

 class GroupChat : public Con
 {
 public:
 	void addUser(User);
 	void removeUser(User);
 
 };


