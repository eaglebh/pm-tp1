#include <sstream>
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

string BibtexArticle::getRequiredFieldsText() const
{
    stringstream text;
    text << BibtexHasPages::getRequiredFieldsText();
    text << "journal = {" << this->journal << "},\n";
    text << "volume = {" << this->volume << "},\n";
    text << "number = {" << this->number << "},\n";
    return text.str();
}
BibtexArticle::BibtexArticle()
{
}
