#include "BibtexBook.h"

BibtexBook::BibtexBook()
{
}

string BibtexBook::getPublisher() const
{
    return publisher;
}

void BibtexBook::setPublisher(const string &value)
{
    publisher = value;
}
