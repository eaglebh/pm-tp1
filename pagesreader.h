#ifndef PAGESREADER_H
#define PAGESREADER_H

#include "pages.h"

class PagesReader
{
public:
    PagesReader();
    static Pages *parsePages(const string text);
};

#endif // PAGESREADER_H
