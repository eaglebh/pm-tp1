#ifndef BIBTEXARTICLE_H
#define BIBTEXARTICLE_H
#include "BibtexFormat.h"

class BibtexArticle : public BibtexFormat
{
private:
    string journal;
    unsigned short volume;
    unsigned short number;
    unsigned int startPage;
    unsigned int endPage;
public:
    BibtexArticle();
    string getJournal() const;
    void setJournal(const string &value);
    unsigned short getVolume() const;
    void setVolume(unsigned short value);
    unsigned short getNumber() const;
    void setNumber(unsigned short value);
    unsigned int getStartPage() const;
    void setStartPage(unsigned int value);
    unsigned int getEndPage() const;
    void setEndPage(unsigned int value);
};

#endif // BIBTEXARTICLE_H
