#include <algorithm>
#include <sstream>
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

string BibFile::toText() const
{
    stringstream ss;
    list<BibtexFormat*>::const_iterator findIter = bibs.begin();
    for(;findIter != bibs.end(); findIter++) {
        BibtexFormat* bib = *findIter;
        ss << bib->getHeader();
        ss << bib->getRequiredFieldsText();
        ss << "}";
    }

    return ss.str();
}

BibtexFormat* BibFile::parseTypeAndReference(const string bibStr)
{
    char type[80], ref[80];
    sscanf(bibStr.c_str(), "%[^{]{%[^,],", type, ref);
    BibtexFormat* bib;

//      std::regex e ("\\b(sub)([^ ]*)");   // matches words beginning by "sub"

//      std::regex_iterator<std::string::iterator> rit ( s.begin(), s.end(), e );
//      std::regex_iterator<std::string::iterator> rend;

//      while (rit!=rend) {
//        std::cout << rit->str() << std::endl;
//        ++rit;
//      }

    if(BibtexArticle::TYPE.compare(type) == 0){
        bib = new BibtexArticle();

    } else {

        if(BibtexBook::TYPE.compare(type) == 0){
            bib = new BibtexBook();
        } else {

            if(BibtexInproceedings::TYPE.compare(type) == 0){
                bib = new BibtexInproceedings();
            }
        }
    }

    bib->setReference(ref);
    return bib;
}
