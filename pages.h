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
        bool first = true;
        unsigned int last = 0;
        bool endSequence = false;
        for (list<unsigned int>::const_iterator it = pageNumbers.begin(); it != pageNumbers.end(); it++) {
            if(first) {
                last = *it;
                pagesText << *it;
                first = false;
            } else {
                if((last+1) == *it) { // sequencia identificada
                    last = *it;
                    endSequence = true;
                } else { // quebra de sequencia
                    if(endSequence) {
                        endSequence = false;
                        pagesText << "-" << last << ',' << *it << ',';
                    } else {
                        pagesText << *it << ',';
                    }
                }
            }
        }
        if(endSequence) {
            endSequence = false;
            pagesText << "-" << last << ',';
        }
        return pagesText.str();
    }
    list<unsigned int> getPageNumbers() const;
};

#endif // PAGES_H
