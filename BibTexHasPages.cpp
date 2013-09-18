#include <sstream>
#include "BibTexHasPages.h"



Pages BibtexHasPages::getPages() const
{
    return pages;
}

void BibtexHasPages::setPages(const Pages &value)
{
    pages = value;
}
BibtexHasPages::BibtexHasPages()
{
}

string BibtexHasPages::getRequiredFieldsText() const
{
    stringstream text;
    text << BibtexFormat::getRequiredFieldsText();
    text << "pages = {" << Pages::getPagesText(this->getPages()) << "},\n";
    return text.str();
}
