#include "Dumper.h"
#include "TxtExtractor.h"
#include "HttpExtractor.h"

Dumper::Dumper(){
	m_instance = new HttpExtractor;
}

Dumper::Dumper(Extractor* extractor){
	m_instance = extractor;
}
