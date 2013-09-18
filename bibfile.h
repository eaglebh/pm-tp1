#ifndef BIBFILE_H
#define BIBFILE_H

#include "BibtexFormat.h"
#include "BibtexArticle.h"
#include "BibtexBook.h"
#include "BibtexInproceedings.h"

class BibFile
{
private:
    list<BibtexFormat *> bibs;

public:
    enum SearchCriteria {
        ALL, AUTHOR, YEAR, VEHICLE, TITLE, REFERENCE
    };
    BibFile();
    void createBibtex(BibtexFormat* bib);
    BibtexFormat* retrieveBibtex(SearchCriteria criteria, const string key);
    void updateBibtex(BibtexFormat* bib);
    void deleteBibtex(BibtexFormat* bib);
    string toText() const;
    list<BibtexFormat *> getBibs();
};



#endif // BIBFILE_H
