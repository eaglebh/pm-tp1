#include "BibtexArticle.h"


string BibtexArticle::getJournal() const
{
    return journal;
}

void BibtexArticle::setJournal(const string &value)
{
    journal = value;
}

unsigned short BibtexArticle::getVolume() const
{
    return volume;
}

void BibtexArticle::setVolume(unsigned short value)
{
    volume = value;
}

unsigned short BibtexArticle::getNumber() const
{
    return number;
}

void BibtexArticle::setNumber(unsigned short value)
{
    number = value;
}

unsigned int BibtexArticle::getStartPage() const
{
    return startPage;
}

void BibtexArticle::setStartPage(unsigned int value)
{
    startPage = value;
}

unsigned int BibtexArticle::getEndPage() const
{
    return endPage;
}

void BibtexArticle::setEndPage(unsigned int value)
{
    endPage = value;
}
BibtexArticle::BibtexArticle()
{
}
