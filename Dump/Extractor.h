#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include "Database.h"

class Extractor
{
protected:

public:
	//Extractor(Database&database);
	virtual void extract(Database & database)=0;
};
#endif
