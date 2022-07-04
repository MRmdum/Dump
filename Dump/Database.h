#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>

#include "Table.h"

using namespace std;

class Database
{
public:
	string _name;
	vector<Table> _tables;

public:
	Database();
	Database(string fullTable);
	virtual ~Database();

	void addTable(Table table);
	vector<Table> getTables();

	string getName();
	void setName(string name);

	string displayDatabase();
};
#endif
