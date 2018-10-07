#include <iostream>
using namespace std;

class Connection
{
public:
	virtual void connectionName() = 0;
};

class SQLServerConnection :public Connection
{
public:
	void connectionName() {
		cout << "I'm SQL Server Connection" << endl;
	}
};

class MySQLConnection : public Connection
{
public:
	void connectionName() {
		cout << "I'm MySQL Connection" << endl;
	}
};
//Abstract class Creator of Factory Method
class ConnectionCreator
{
public:
	virtual Connection* createConnection() = 0;
	void showConnectionName() {
		Connection* connection = createConnection();
		connection->connectionName();
	}
};

class createSQLServerConnection :public ConnectionCreator
{
public:
	Connection* createConnection() {
		return new SQLServerConnection();
	}
};

class createMySQLConnection : public ConnectionCreator
{
	Connection* createConnection() {
		return new MySQLConnection();
	}
};

void main()
{
	ConnectionCreator *f;
	f = new createMySQLConnection();
	f->showConnectionName();

	f = new createSQLServerConnection();
	f->showConnectionName();
	delete f;
}
