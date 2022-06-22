#include "Dumper.h"

//
//Dumper::Dumper(){
//	m_instance = new Extractor;
//}

Dumper::Dumper(Extractor* extractor){
	m_instance = extractor;
}
 
void Dumper::dump(map<string,string> parameters) {
	Database database = Database();
	m_instance->extract(database);
	cout << endl <<"|||Start output DB|||" << endl<<endl;
	database.displayDatabase();
	cout <<endl << "|||Ending output DB|||" << endl;

}