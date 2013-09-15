#include "BibtexFormat.h"

BibtexFormat::BibtexFormat()
{
}

string BibtexFormat::getReference() const
{
    return reference;
}

void BibtexFormat::setReference(const string &value)
{
    reference = value;
}

string BibtexFormat::getAuthor() const
{
    return this->author;
}

string BibtexFormat::getTitle() const
{
    return this->title;
}

long BibtexFormat::getYear() const
{
    return this->year;
}

void BibtexFormat::setAuthor(const string &author)
{
    this->author = author;
}

void BibtexFormat::setTitle(const string &title)
{
    this->title = title;
}

void BibtexFormat::setYear(const long &year)
{
    this->year = year;
}
