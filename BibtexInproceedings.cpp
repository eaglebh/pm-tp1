#include <sstream>
#include "BibtexInproceedings.h"


string BibtexInproceedings::getBooktitle() const
{
    return booktitle;
}

void BibtexInproceedings::setBooktitle(const string &value)
{
    booktitle = value;
}

Pages BibtexInproceedings::getPages() const
{
    return pages;
}

void BibtexInproceedings::setPages(const Pages &value)
{
    pages = value;
}

string BibtexInproceedings::getRequiredFieldsText() const
{
    stringstream text;
    text << BibtexFormat::getRequiredFieldsText();
    text << "booktitle = {" << this->booktitle << "},\n";
    text << "pages = {" << this->pages.getPagesText() << "},\n";
    return text.str();
}
BibtexInproceedings::BibtexInproceedings()
{
}
