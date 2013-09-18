#ifndef BIBTEXBOOK_H
#define BIBTEXBOOK_H
#include "BibtexFormat.h"

class BibtexBook : public BibtexFormat
{
    string publisher;
public:
    static const string TYPE;
    BibtexBook();
    string getPublisher() const;
    void setPublisher(const string &value);

    // BibtexFormat interface
    virtual string getType() const
    {
        return TYPE;
    }
    string getRequiredFieldsText() const;
};

#endif // BIBTEXBOOK_H
