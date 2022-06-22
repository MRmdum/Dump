#include "Database.h"

Database::Database() {
	_name = "Sans nom";
	vector<Table> _tables;
	_tables.push_back(Table());
	_tables.pop_back();
	cout << "database initiated" << endl;
}

Database::Database(string fullTable) {	

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
void Database::displayDatabase() {

	for (int i = 0; i < _tables.size(); i++) {
		_tables[i].displayTable();
		cout << endl;
	}
}