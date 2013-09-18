#include <sstream>
#include "BibtexFormat.h"

Authors BibtexFormat::getAuthors() const
{
    return authors;
}

void BibtexFormat::setAuthors(const Authors &value)
{
    authors = value;
}

string BibtexFormat::getHeader() const
{
    stringstream header;
    header << '@' << getType() << "{" << reference << ",\n";
    return header.str();
}

string BibtexFormat::getRequiredFieldsText() const
{
    stringstream text;
    text << "author = {" << this->authors.getAuthorsText() << "},\n";
    text << "title = {" << this->title << "},\n";
    text << "year = {" << this->year << "},\n";
    return text.str();
}
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

string BibtexFormat::getTitle() const
{
    return this->title;
}

long BibtexFormat::getYear() const
{
    return this->year;
}

void BibtexFormat::setTitle(const string &title)
{
    this->title = title;
}

void BibtexFormat::setYear(const long &year)
{
    this->year = year;
}
