#ifndef PAGESREADER_H
#define PAGESREADER_H

#include "pages.h"

namespace PagesReader
{
    Pages *parsePages(const string text);
    Pages * parsePagesFromValue(string values);
}

#endif // PAGESREADER_H
