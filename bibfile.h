#ifndef BIBFILE_H
#define BIBFILE_H

#include "BibtexFormat.h"
#include "BibtexArticle.h"
#include "BibtexBook.h"
#include "BibtexInproceedings.h"

class BibFile
{
private:
    list<BibtexFormat*> bibs;
    enum SearchCriteria {
        AUTHOR, YEAR, VEHICLE, TITLE
    };

public:
    BibFile();
    void createBibtex(BibtexFormat* bib);
    BibtexFormat* retrieveBibtex(SearchCriteria criteria, const string key);
    void updateBibtex(BibtexFormat* bib);
    void deleteBibtex(BibtexFormat* bib);
    string toText() const;
    static BibtexFormat *parseTypeAndReference(const string bibStr);
};

#endif // BIBFILE_H
