#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Table
{
private:
	string _name;
	vector<string> _columns;
	vector<vector<string>> _data;

public:
	string Getname();
	vector<string> Getcolumn();
	vector<vector<string>> Getdata();

	Table();
	Table(vector<vector<string>> fulltable,vector<string> columns,string name);
	virtual ~Table();

	vector<string> getColumns();
	void setColumns(vector<string> columns);
	void addColumn(string column);
		
	vector<vector<string>> getData();
	void insertLine(vector<string> line);

	string getName();
	void setName(string name);

	string displayTable();
};
#endif
