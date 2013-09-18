#include "authors.h"
#include <sstream>

Authors::Authors()
{
}

void Authors::addAuthor(string author)
{
    authors.push_back(author);
}

void Authors::removeAuthor(string author)
{
    authors.remove(author);
}

string Authors::getAuthorsText() const
{
    stringstream authorsText;
    for (list<string>::const_iterator it = authors.begin(); it != authors.end(); it++) {
        authorsText << *it;
    }
    return authorsText.str();
}
