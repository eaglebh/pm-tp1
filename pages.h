#ifndef PAGES_H
#define PAGES_H

#include <list>
#include <string>
#include <sstream>

using namespace std;
class Pages
{
private:
    list<unsigned int> pageNumbers;
public:
    Pages();
    void addPage(unsigned int page);
    void removePage(unsigned int page);

    static string getPagesText(const Pages &pages)
    {
        stringstream pagesText;
        list<unsigned int> pageNumbers = pages.getPageNumbers();
        for (list<unsigned int>::const_iterator it = pageNumbers.begin(); it != pageNumbers.end(); it++) {
            pagesText << *it;
        }
        return pagesText.str();
    }
    list<unsigned int> getPageNumbers() const;
};

#endif // PAGES_H
