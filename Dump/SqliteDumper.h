#ifndef SQLITEDUMPER_H
#define SQLITEDUMPER_H

#include <map>

#include "Dumper.h"

template <typename T> class SqliteDumper : public Dumper
{
public:
	void dump(map<string,string> parameters);
};

#endif