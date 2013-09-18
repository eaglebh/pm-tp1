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
    string getRequiredFieldsText() const;
};

#endif // BIBTEXBOOK_H
