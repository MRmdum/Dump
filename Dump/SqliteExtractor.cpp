#include "SqliteExtractor.h"
#include "Table.h"

 vector<vector<string>>  SqliteExtractor::m_buffer;
 
 SqliteExtractor:: SqliteExtractor(){}


void SqliteExtractor::WritteTable()
{
    sqlite3* m_bdd;

    string sql;
    cout << "Entrez commande SQL";
    cin >> sql;

    bool exist;
    char* ErrorMessage = 0;

    string const file = "C:/Users/stagiaire/Desktop/Dump/db.sqlite3";

    const char* data = "Callback function called";

    /* Open database */
    exist = sqlite3_open(file.c_str(), &m_bdd);

    if (exist) {
        cout << "Can't open database: %s" << endl << sqlite3_errmsg(m_bdd) << endl;
    }
    else {
        //cout << "Opened database successfully" << endl;
    }

    //Execute
    exist = sqlite3_exec(m_bdd, sql.c_str(), SqlCallback, (void*)data, &ErrorMessage);

    sqlite3_close(m_bdd);
}

/// <summary>
/// Function called to iterate on each row
/// </summary>
/// <param name="data">storage unused</param>
/// <param name="argc">number of columns in the data base</param>
/// <param name="argv">value in the columns</param>
/// <param name="azColName">columns' names</param>
/// <returns></returns>
int SqliteExtractor::SqlCallback(void * data, int argc, char ** argv, char ** azColName)
{
    
    int i;
    vector<string> temp_buff;
    //fprintf(stderr, "%s: ", (const char*)data);
        
    for (i = 0; i < argc; i++) {

        //cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
        if(argv[i]) temp_buff.push_back(argv[i]);
    }
    m_buffer.push_back(temp_buff);
    
    return 0;
}

/// <summary>
/// Lists all tables' name
/// </summary>
vector<string> SqliteExtractor::enumerateTables(string sql)
{
    sqlite3* m_bdd;

    bool exist;
    char* ErrorMessage = 0;
    string const file = "C:/Users/stagiaire/Desktop/Dump/db.sqlite3";

    const char* data = "Callback function called";

    /* Open database */
    exist = sqlite3_open(file.c_str(), &m_bdd);

    if (exist) {
        cout << "Can't open database: %s" << endl << sqlite3_errmsg(m_bdd) << endl;
    }
    else {
        //cout << "Opened database successfully" << endl;
    }    

    //Execute
    exist = sqlite3_exec(m_bdd, sql.c_str(), SqliteExtractor::SqlCallback, (void*)data, &ErrorMessage);

    vector<string> tablesName;

    if (exist != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", ErrorMessage);
        sqlite3_free(ErrorMessage);
    }
    else {
        //cout << "Operation done successfuly" << endl;
        
        for (int i = 0; i < m_buffer.size(); i++)
        {
            tablesName.push_back(m_buffer[i][0]);
        }

        /*for (int i = 0; i != m_buffer.size(); i++)
        {
            vector <string> temp_buff = m_buffer[i];

            for (int j = 0; j != temp_buff.size(); j++)
            {
                cout << temp_buff[j];
            }
            cout << endl;
        }*/
    }
    sqlite3_close(m_bdd);
    return tablesName;
}

/// <summary>
/// Dump all of fields for one table
/// </summary>
/// <param name="nomTable">table to dump</param>
/// <returns>the all table is return</returns>
string SqliteExtractor::dumpTable(string nomTable,Database  &dbase)
{
    string table;
    sqlite3* m_bdd;

    bool exist = NULL;
    string sql;
    char* ErrorMessage = 0;
    string file = "db.sqlite3";
    m_buffer.erase(m_buffer.begin(), m_buffer.end());
    const char* data = "Callback function called";

    /* Open database */
    exist = sqlite3_open(file.c_str(), &m_bdd);

    if (exist) {
        cout << "Can't open database: %s" << endl << sqlite3_errmsg(m_bdd) << endl;
    }
    else {
        //cout << "Opened database successfully" << endl;
    }

    sql = "SELECT * FROM " + nomTable + ";";

    //erase the buffer to avoid corruption
    m_buffer.erase(m_buffer.begin(), m_buffer.end());

    //Execution
    exist = sqlite3_exec(m_bdd, sql.c_str(), SqliteExtractor::SqlCallback, (void*)data, &ErrorMessage);

    for (int i = 0; i != m_buffer.size(); i++)
    {
        for (int j = 0; j < m_buffer[i].size(); j++)
        {
            table += m_buffer[i][j] +" ";
            //cout << m_buffer[i][j] + " ";
        }
        table += "\n";
        //cout << endl;
    }
    vector<vector<string>> tempbuffer = m_buffer;
    dbase.addTable(Table(tempbuffer,enumerateTables("select name from pragma_table_info('django_migrations') as tblInfo;"), nomTable));
    return table;
}


/// <summary>
/// Dump all fields for all tables from one data base
/// </summary>
/// <returns></returns>
void SqliteExtractor::dumpAllTables(string sql, Database  &dbase)
{
    vector<string> tablesName = enumerateTables(sql);
    
    //Store every value of every table
    string tableS = "";

    string name = "";

    for (int i = 0; i != tablesName.size(); i++)
    {        
        name += tablesName[i];        

        //dbase.addTable(Table(dumpTable(name, dbase), "Table" + string(1,i));

        tableS += ("\n |||"+name+"||| \n \n"+ dumpTable(name,dbase));
        name = "";
    }

    string const fileName("C:/Users/stagiaire/Desktop/Dump/FichierTest.txt");
    ofstream myFlow(fileName.c_str(),ios::app);

    if (myFlow)
    {
        myFlow << tableS;
        cout << "File Written successfuly\n";
        //(dbase).displayDatabase();
    }
    else
    {
        cout << "Error: Writing file not found !";
    }
}

/// <summary>
/// Display all the fields in a the database
/// </summary>
/// <param name="dbase">The pseudo-database we're writting on</param>
void SqliteExtractor::dumpAllTheThing(Database & dbase)
{
    string const fileName("C:/Users/stagiaire/Desktop/Dump/FichierTest.txt");
    ofstream myFlow(fileName.c_str());

    dumpAllTables("SELECT name FROM sqlite_master WHERE type = 'table';",dbase);
    dumpAllTables("SELECT name FROM sqlite_master WHERE type = 'index';",dbase);
    dumpAllTables("SELECT name FROM sqlite_master WHERE type = 'view';", dbase);
    dumpAllTables("SELECT name FROM sqlite_master WHERE type = 'trigger';", dbase);
}


void SqliteExtractor::extract(Database & database) {

    dumpAllTables("SELECT name FROM sqlite_master WHERE type = 'table';",database);
}