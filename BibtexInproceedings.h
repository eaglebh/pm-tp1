#ifndef BIBTEXINPROCEEDINGS_H
#define BIBTEXINPROCEEDINGS_H

#include "BibtexFormat.h"

class BibtexInproceedings : public BibtexFormat
{
private:
    string booktitle;
    unsigned int startPage;
    unsigned int endPage;
public:
    BibtexInproceedings();
    string getBooktitle() const;
    void setBooktitle(const string &value);
    unsigned int getStartPage() const;
    void setStartPage(unsigned int value);
    unsigned int getEndPage() const;
    void setEndPage(unsigned int value);
};

#endif // BIBTEXINPROCEEDINGS_H
