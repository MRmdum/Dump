#ifndef DUMPER_H
#define DUMPER_H

#include "Extractor.h"
#include <map>

using namespace std;


class Dumper
{
private:

protected:
	Dumper();
	Extractor * m_instance;

public:
	Dumper(Extractor* extractor);
	virtual Database dump(map<string,string> parameters)=0;
};
#endif
