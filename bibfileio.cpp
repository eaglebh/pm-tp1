#include <iostream>
#include <fstream>
#include "bibfileio.h"
#include "BibtexArticle.h"
#include "BibtexBook.h"
#include "BibtexInproceedings.h"
#include "pagesreader.h"
#include "authorreader.h"
#include "util.h"

using namespace std;

BibtexFormat *BibfileIO::readBibtex(stringstream &bibStr)
{
    BibtexFormat* bib = parseTypeAndReference(bibStr.str());

    return bib;
}

BibtexFormat *BibfileIO::parseTypeAndReference(const string bibStr)
{
    char type[80], ref[80];
    sscanf(bibStr.c_str(), "%[^{]{%[^,],", type, ref);
    BibtexFormat* bib;

    if(BibtexArticle::TYPE.compare(type) == 0){
        bib = new BibtexArticle();
        ((BibtexArticle*)bib)->setJournal(Util::parseField("journal", bibStr));
        ((BibtexArticle*)bib)->setVolume(Util::parseIntField("volume", bibStr));
        ((BibtexArticle*)bib)->setNumber(Util::parseIntField("number", bibStr));
        ((BibtexArticle*)bib)->setPages(*PagesReader::parsePages(bibStr));
    } else {

        if(BibtexBook::TYPE.compare(type) == 0){
            bib = new BibtexBook();
            ((BibtexBook*)bib)->setPublisher(Util::parseField("publisher", bibStr));
        } else {

            if(BibtexInproceedings::TYPE.compare(type) == 0){
                bib = new BibtexInproceedings();
                ((BibtexInproceedings*)bib)->setBooktitle(Util::parseField("booktitle", bibStr));
                ((BibtexInproceedings*)bib)->setPages(*PagesReader::parsePages(bibStr));
            }
        }
    }
    bib->setAuthors(*AuthorReader::parseAuthors(bibStr));
    bib->setTitle(Util::parseField("title", bibStr));
    bib->setYear(Util::parseIntField("year", bibStr));
    bib->setReference(ref);
    return bib;
}

BibfileIO::BibfileIO(const string fileName)
    :fileName(fileName)
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
    ifs.close();
}

BibFile *BibfileIO::getBibFile()
{
    return bibFile;
}

void BibfileIO::persist()
{
    ofstream ofs(fileName);

    list<BibtexFormat*> bibs = bibFile->getBibs();
    list<BibtexFormat*>::const_iterator findIter = bibs.begin();
    for(;findIter != bibs.end(); findIter++) {
        BibtexFormat* bib = *findIter;
        if(bib->getReference().length() > 0) {
            ofs << bib->getHeader();
            ofs << bib->getRequiredFieldsText();
            ofs << "}\n";
        }
    }

    ofs.close();
}
