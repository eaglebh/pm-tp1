#include <iostream>
#include <fstream>
#include "bibfileio.h"
#include "BibtexArticle.h"
#include "BibtexBook.h"
#include "BibtexInproceedings.h"

using namespace std;

BibtexFormat *BibfileIO::readBibtex(stringstream &bibStr)
{
    BibtexFormat* bib = BibFile::parseTypeAndReference(bibStr.str());

    return bib;
}

BibfileIO::BibfileIO(const string fileName)
{
    bibFile = new BibFile();

    stringstream bibStr;

    ifstream ifs(fileName.c_str());
    string line;

    while (getline(ifs, line, '@')) {
        if(line.length() > 0) {
            bibStr << line;
            BibtexFormat* bib = readBibtex(bibStr);
            bibFile->createBibtex(bib);
            bibStr.str("");
        }
    }
}

BibFile *BibfileIO::getBibFile()
{
    return bibFile;
}

void BibfileIO::persist()
{

}
