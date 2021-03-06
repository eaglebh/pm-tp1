#ifndef BIBTEXFORMAT_H
#define BIBTEXFORMAT_H

#include <string>
#include <iostream>
#include "authors.h"

using namespace std;

class BibtexFormat
{
private:
    string reference;
    Authors authors;
    string title;
    long year;
public:
    BibtexFormat();
    string getReference() const;
    void setReference(const string value);
    string getTitle() const;
    void setTitle(const string title);
    long getYear() const;
    void setYear(const long year);
    Authors getAuthors() const;
    void setAuthors(const Authors value);
    virtual string getType() const = 0;
    string getHeader() const;
    virtual string getRequiredFieldsText() const;
    friend bool operator== (BibtexFormat &lhs, BibtexFormat &rhs){
        cout << "comparando "  << lhs.reference << " com " << rhs.reference << endl;
        return (lhs.reference.compare(rhs.reference) == 0);
    }
};

#endif // BIBTEXFORMAT_H
