#ifndef EXTRACTOR_H
#define EXTRACTOR_H

class Database;
#include "Database.h"

class Extractor
{
protected:

public:	
	virtual void extract(Database & database)=0 ;
};

#endif
