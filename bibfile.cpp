#include <algorithm>
#include <sstream>
#include "bibfile.h"
#include "util.h"
#include "authorreader.h"
#include "pagesreader.h"


list<BibtexFormat *> BibFile::getBibs()
{
    return bibs;
}

BibFile::BibFile()
{
}

void BibFile::createBibtex(BibtexFormat *bib)
{
    this->bibs.push_back(bib);
}

BibtexFormat *BibFile::retrieveBibtex(BibFile::SearchCriteria criteria, const string key)
{
    BibtexFormat* bib = NULL;
    string actualText = "";
    stringstream ss;
    for (list<BibtexFormat*>::iterator it = bibs.begin(); it != bibs.end(); it++) {
        bib = *it;
        switch (criteria) {
        case AUTHOR:
            actualText = bib->getAuthors().getAuthorsText();
            break;
        case YEAR:
            ss.str("");
            ss << bib->getYear();
            actualText = ss.str();
            break;
        case VEHICLE:
            if(bib->getType().compare(BibtexArticle::TYPE) == 0) {
                actualText = ((BibtexArticle*)bib)->getJournal();
            } else {
                if(bib->getType().compare(BibtexInproceedings::TYPE) == 0) {
                    actualText = ((BibtexInproceedings*)bib)->getBooktitle();
                }
            }
            break;
        case TITLE:
            actualText = bib->getTitle();
            break;
        case REFERENCE:
            actualText = bib->getReference();
            break;
        default:
            break;
        }
        if(key.size() == 0){
            if(actualText.size() == 0){
                return bib;
            }
        } else {
            if(actualText.find(key) != string::npos){
                return bib;
            }
        }
    }
    throw "Bibtex nao encontrado";
}

void BibFile::updateBibtex(BibtexFormat *bib)
{
    list<BibtexFormat*>::iterator findIter = find(bibs.begin(), bibs.end(), bib);
    if(findIter != bibs.end()) {
        if((*findIter) != bib) {
            // objeto passado nao eh referencia para objeto da lista
            deleteBibtex(*findIter);
            createBibtex(bib);
        }
    } else {
        throw "Bibtex atualizado nao esta na lista.";
    }
}

void BibFile::deleteBibtex(BibtexFormat *bib)
{
    this->bibs.remove(bib);
}

string BibFile::toText() const
{
    stringstream ss;
    list<BibtexFormat*>::const_iterator findIter = bibs.begin();
    for(;findIter != bibs.end(); findIter++) {
        BibtexFormat* bib = *findIter;
        ss << bib->getHeader();
        ss << bib->getRequiredFieldsText();
        ss << "}\n";
    }
    
    return ss.str();
}


