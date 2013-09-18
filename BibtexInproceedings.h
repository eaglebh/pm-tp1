#ifndef BIBTEXINPROCEEDINGS_H
#define BIBTEXINPROCEEDINGS_H

#include "BibTexHasPages.h"

class BibtexInproceedings : public BibtexHasPages
{
private:
    string booktitle;
    Pages pages;
public:
    static const string TYPE;
    BibtexInproceedings();
    string getBooktitle() const;
    void setBooktitle(const string &value);
    Pages getPages() const;
    void setPages(const Pages &value);

    // BibtexFormat interface
    virtual string getType() const
    {
        return "inproceedings";
    }
    string getRequiredFieldsText() const;
};

#endif // BIBTEXINPROCEEDINGS_H
