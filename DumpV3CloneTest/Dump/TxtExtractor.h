#ifndef TXTEXTRACTOR_H
#define TXTEXTRACTOR_H
 
#include "Extractor.h"

class TxtExtractor : public Extractor
{
public:
	virtual void extract(Database & database);
	 
};
#endif

