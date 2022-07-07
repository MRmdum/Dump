/*class files*/
#include "HttpExtractor.h"
#include "TxtExtractor.h"
#include "SqliteDumper.h"
#include "Dump.h"
/*---*/

using namespace std;

int main()
{
    Extractor* extractor = new HttpExtractor; //can be replace by other extractors

    SqliteDumper dump = SqliteDumper(extractor); //can be replaced by other Dumpers

    map<string,string> parameters;
    dump.dump(parameters);

}

