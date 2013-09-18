#include "pages.h"
#include <iostream>
#include <sstream>

string Pages::getPagesText() const
{
    stringstream pagesText;
    for (list<unsigned int>::const_iterator it = pageNumbers.begin(); it != pageNumbers.end(); it++) {
        pagesText << *it;
    }
    return pagesText.str();
}

Pages::Pages()
{
}

void Pages::addPage(unsigned int page)
{
    if(page <= 0) {
        throw "Pagina invalida";
    }
    pageNumbers.push_back(page);
}

void Pages::removePage(unsigned int page)
{
    pageNumbers.remove(page);
}
