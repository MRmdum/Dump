#ifndef HTTPEXTRACTOR_H
#define HTTPEXTRACTOR_H

#include "Extractor.h"

class HttpExtractor : public Extractor
{
public:
	virtual void extract(Database& database);
};
#endif


