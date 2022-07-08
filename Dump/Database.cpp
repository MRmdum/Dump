#include "Database.h"

/// <summary>
/// empty constructor for the database
/// </summary>
Database::Database() {
	_name = "Sans nom";
	vector<Table> _tables;
	_tables.push_back(Table());
	_tables.pop_back();
	cout << "database initiated" << endl;
}

Database::Database::~Database(){
}

void Database::addTable(Table table){
	_tables.push_back(table);
}

vector<Table> Database::getTables(){
	return _tables;
}

string Database::getName(){
	return _name;
}

void Database::setName(string name){
	_name = name;
}

string Database::displayDatabase() {

	string allDataBaseToString;
	for (int i = 0; i < _tables.size(); i++) {
		allDataBaseToString+= _tables[i].displayTable();
		allDataBaseToString += "\n";
	}
	return allDataBaseToString;
}