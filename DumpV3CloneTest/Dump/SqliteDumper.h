#ifndef SQLITEDUMPER_H
#define SQLITEDUMPER_H

using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>

#include "Dumper.h"
#include "sqlite3.h"

class SqliteDumper : public Dumper
{
private:

	static vector<vector<string>> m_buffer;

	Table dumpTable(string nomTable, Database& dbase);
	vector <string> enumerateTables(string sql);

protected:
	static int SqlCallback(void* data, int argc, char** argv, char** azColName);
	
public:
	SqliteDumper(Extractor* extractor);
	void dumpAllTables(string sql, Database& dbase);
	void dumpAllTheThing(Database& dbase);
	virtual Database dump(map<string, string> parameters);
};
#endif
