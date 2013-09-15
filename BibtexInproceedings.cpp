#include "BibtexInproceedings.h"


string BibtexInproceedings::getBooktitle() const
{
    return booktitle;
}

void BibtexInproceedings::setBooktitle(const string &value)
{
    booktitle = value;
}

unsigned int BibtexInproceedings::getStartPage() const
{
    return startPage;
}

void BibtexInproceedings::setStartPage(unsigned int value)
{
    startPage = value;
}

unsigned int BibtexInproceedings::getEndPage() const
{
    return endPage;
}

void BibtexInproceedings::setEndPage(unsigned int value)
{
    endPage = value;
}
BibtexInproceedings::BibtexInproceedings()
{
}
