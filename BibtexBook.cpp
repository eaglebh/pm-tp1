#include <sstream>
#include "BibtexBook.h"

const string BibtexBook::TYPE = "book";

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

string BibtexBook::getRequiredFieldsText() const
{
    stringstream text;
    text << BibtexFormat::getRequiredFieldsText();
    text << "publisher = {" << this->publisher << "},\n";
    return text.str();
}
