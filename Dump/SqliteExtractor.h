#ifndef SQLITEEXTRACTOR_H
#define SQLITEEXTRACTOR_H
using namespace std; 

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>

#include "Extractor.h"
#include "sqlite3.h"

class SqliteExtractor : public Extractor
{
private:

	static vector<vector<string>> m_buffer;

	string dumpTable(string nomTable,Database & dbase);
	vector <string> enumerateTables(string sql);
	
protected:
	static int SqlCallback(void* data, int argc, char** argv, char** azColName);
	 
public:
	SqliteExtractor();
	void dumpAllTables(string sql, Database & dbase);
	void WritteTable();
	void dumpAllTheThing(Database& dbase);
	virtual void extract(Database& database);

};
#endif
