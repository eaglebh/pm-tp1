#ifndef BIBTEXBOOK_H
#define BIBTEXBOOK_H
#include "BibtexFormat.h"

class BibtexBook : public BibtexFormat
{
    string publisher;
public:
    BibtexBook();
    string getPublisher() const;
    void setPublisher(const string &value);
};

#endif // BIBTEXBOOK_H
