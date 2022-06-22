#include "SqliteDumper.h"

template<class T> void SqliteDumper<T>::dump(map<string,string> parameters) {
	Database database;
	m_instance->extract(database);
}