#ifndef PAGES_H
#define PAGES_H

#include <list>
#include <string>

using namespace std;
class Pages
{
private:
    list<unsigned int> pageNumbers;
public:
    Pages();
    void addPage(unsigned int page);
    void removePage(unsigned int page);
    string getPagesText() const;
};

#endif // PAGES_H
