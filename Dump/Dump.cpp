#include "SqliteDumper.h"
#include "SqliteExtractor.h"

using namespace std;

int main()
{
    Extractor* extractor = new SqliteExtractor;
    Dumper dump = Dumper(extractor);
    map<string,string> parameters;
    dump.dump(parameters);

    //(*dump).enumerateTables();
    //SqlDump dump = SqlDump("db.sqlite3");
    

    /*SqlDump* dump2 = SqlDump::GetInstance();
    (*dump2).WritteTable();*/
    //(*dump2).DestroyInstance();
}
