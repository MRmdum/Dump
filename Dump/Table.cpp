#include "Table.h"


Table::Table(vector<vector<string>> fulltable,vector<string> columns,string name){
	_name = name;
	_data = fulltable;
	_columns = columns;
}

/// <summary>
/// empty version of the constructor constructor
/// </summary>
Table::Table(){
	string _name = "Nameless column";
	vector<string> _columns;
	vector<vector<string>> _data;
}

Table::~Table(){
}


vector<string> Table::getColumns() {
	return _columns;
}

/// <summary>
/// Set a column's values after it has been instansiated in addColumn
/// </summary>
/// <param name="columns">column's values</param>
void Table::setColumns(vector<string> columns) {
	if (columns.size() <= _data.size()) {

		for (int i = 0; i < _data.size(); i++) {

			_data[i].push_back(columns[i]);
		}
	}
	else {
		cout << "Error column's size out of range" << endl;
	}
}

void Table::addColumn(string column) {
	_columns.push_back(column);
}

vector<vector<string>> Table::getData() {
	return _data ;
}

void Table::insertLine(vector<string> line) {
	_data.push_back(line);
}

string Table::getName() {
	return _name;
}

void Table::setName(string name) {
	_name = name;
}


string Table::displayTable() {

	string allTableToString;
	for (int i = 0; i < _columns.size(); i++) {
		allTableToString += _columns[i] + " ";
	}
	allTableToString +="\n\n";

	for (int i = 0; i < _data.size(); i++) {
		for (int j = 0; j < _data[i].size(); j++) {

			allTableToString+= _data[i][j] + " ";
		}
		allTableToString +="\n";
	}
	return allTableToString;
}

string Table::Getname() {
	return _name;
}

vector<string> Table::Getcolumn() {
	return _columns;
}

vector<vector<string>> Table::Getdata() {
	return _data;
}