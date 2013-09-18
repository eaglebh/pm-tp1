#include <algorithm>
#include "bibfile.h"

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
    for (list<BibtexFormat*>::iterator it = bibs.begin(); it != bibs.end(); it++) {
        bib = *it;
        switch (criteria) {
        case AUTHOR:
            actualText = bib->getAuthors().getAuthorsText();
            break;
        case YEAR:
     //       actualText = to_string(bib->getYear());
            break;
        case VEHICLE:
       //     actualText = bib->get;
            break;
        case TITLE:
            actualText = bib->getTitle();
            break;
        default:
            break;
        }
    }
    if(actualText.find(key) != string::npos){
        return bib;
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
