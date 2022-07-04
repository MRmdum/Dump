#include "TxtExtractor.h"
#include <fstream>

/// <summary>
/// Wrtie and present the database on a .txt file
/// </summary>
/// <param name="database">the database to extract</param>
void TxtExtractor::extract(Database & database) {

	string alltables;

	for (int i = 0; i < database._tables.size(); i++) {

		alltables += ("|||" + database._tables[i].Getname() + "|||\n\n");

		for (int x = 0; x < database._tables[i].Getcolumn().size(); x++) {

			alltables += (database._tables[i].Getcolumn()[x] + "  :  ");
		}
		alltables +=  "\n\n";

		for (int x = 0; x < database._tables[i].Getdata().size(); x++) {
			for (int j = 0; j < database._tables[i].Getdata()[x].size(); j++) {


				alltables += (database._tables[i].Getdata()[x][j] + "  /  ");
			}
			alltables += "\n";
		}
		alltables += "\n";		
	}
		ofstream Myflow("C:/Users/stagiaire/Desktop/Dump/FichierTest.txt");
		Myflow << alltables;
		Myflow.close(); 
}
