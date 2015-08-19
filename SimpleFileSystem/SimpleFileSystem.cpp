class Entry
{
private:
	string name;
	Entry * parent;
	Date createOn, updatedOn;

public:
	Entry(string name, Entry * p);
	~Entry();

	bool delete();
	bool changeName();

	virtual size_t Size() = 0;
	string getPath();

	Date getCreateTime();
	//...
};

class File : public Entry
{
private:
	size_t size;
	string content;
public:
	File(string n, Entry * p);
	~File();

	string read();
	void write(string);
	void append(string);

	size_t Size();

};

class Directory
{
private:
	vector<Entry *> contents;
public:
	Directory(string, Entry);
	~Directory();

	size_t Size();

	int numOfFile();

	bool deleteEntry(Entry);
	void addEntry(Entry);
};