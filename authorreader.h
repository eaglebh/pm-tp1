#ifndef AUTHORREADER_H
#define AUTHORREADER_H

#include "authors.h"

namespace AuthorReader
{
    Authors *parseAuthors(const string text);
    Authors * parseAuthorsFromValue(const string values);
}

#endif // AUTHORREADER_H
