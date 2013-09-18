#ifndef BIBTEXINPROCEEDINGS_H
#define BIBTEXINPROCEEDINGS_H

#include "BibTexHasPages.h"

class BibtexInproceedings : public BibtexHasPages
{
private:
    string booktitle;
public:
    static const string TYPE;
    BibtexInproceedings();
    string getBooktitle() const;
    void setBooktitle(const string &value);
    // BibtexFormat interface
    virtual string getType() const
    {
        return "inproceedings";
    }
    string getRequiredFieldsText() const;
};

#endif // BIBTEXINPROCEEDINGS_H
