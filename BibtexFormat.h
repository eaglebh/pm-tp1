#ifndef BIBTEXFORMAT_H
#define BIBTEXFORMAT_H

#include <string>

using namespace std;

class BibtexFormat
{
private:
    string reference;
    string author;
    string title;
    long year;
public:
    BibtexFormat();
    string getReference() const;
    void setReference(const string &value);
    string getAuthor() const;
    void setAuthor(const string &author);
    string getTitle() const;
    void setTitle(const string &title);
    long getYear() const;
    void setYear(const long &year);
};

#endif // BIBTEXFORMAT_H
