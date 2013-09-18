#include "pages.h"
#include <iostream>

list<unsigned int> Pages::getPageNumbers() const
{
    return pageNumbers;
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
