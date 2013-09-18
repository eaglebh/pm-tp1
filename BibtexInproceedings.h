#ifndef BIBTEXINPROCEEDINGS_H
#define BIBTEXINPROCEEDINGS_H

#include "BibTexHasPages.h"

class BibtexInproceedings : public BibtexHasPages
{
private:
    string booktitle;
    Pages pages;
public:
    BibtexInproceedings();
    string getBooktitle() const;
    void setBooktitle(const string &value);
    Pages getPages() const;
    void setPages(const Pages &value);
    string getRequiredFieldsText() const;
};

#endif // BIBTEXINPROCEEDINGS_H
