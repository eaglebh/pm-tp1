#include <sstream>
#include "BibtexInproceedings.h"

const string BibtexInproceedings::TYPE = "inproceedings";

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
    text << "pages = {" << Pages::getPagesText(&this->pages) << "},\n";
    return text.str();
}
BibtexInproceedings::BibtexInproceedings()
{
}
