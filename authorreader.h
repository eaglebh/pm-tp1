#ifndef AUTHORREADER_H
#define AUTHORREADER_H

#include "authors.h"

class AuthorReader
{
public:
    AuthorReader();
    static Authors *parseAuthors(const string text);
};

#endif // AUTHORREADER_H
