#ifndef DUMPER_H
#define DUMPER_H

#include "Extractor.h"
#include <string>
#include <vector>
#include <map>

using namespace std;


class Dumper
{
private:
	Dumper();

protected:
	Extractor * m_instance;


public:
	/*
	virtual Dumper * GetInstance() =0;
	virtual void DestroyInstance()=0;
	virtual void DumpAllTheThings(string filename) const = 0;	
    static T* GetInstance();
	static void DestroyInstance();*/

	Dumper(Extractor* extractor);
	virtual void dump(map<string,string> parameters);
};
#endif
