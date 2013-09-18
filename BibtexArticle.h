#ifndef BIBTEXARTICLE_H
#define BIBTEXARTICLE_H
#include "BibTexHasPages.h"
#include <list>

class BibtexArticle : public BibtexHasPages
{
private:
    string journal;
    unsigned short volume;
    unsigned short number;
public:
    static const string TYPE;
    BibtexArticle();    
    string getJournal() const;
    void setJournal(const string &value);
    unsigned short getVolume() const;
    void setVolume(unsigned short value);
    unsigned short getNumber() const;
    void setNumber(unsigned short value);

    // BibtexFormat interface
    virtual string getType() const
    {
        return TYPE;
    }
    string getRequiredFieldsText() const;
};

#endif // BIBTEXARTICLE_H
