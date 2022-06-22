#ifndef MOCK_EXTRACTOR_H
#define MOCK_EXTRACTOR_H

#include "Database.h"
#include "Extractor.h"

class MockExtractor : Extractor
{
public:
	void extract(const Database& database);
};

#endif
