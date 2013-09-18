#ifndef AUTHORS_H
#define AUTHORS_H

#include <list>
#include <string>

using namespace std;

class Authors
{
private:
    list<string> authors;
public:
    Authors();
    void addAuthor(string author);
    void removeAuthor(string author);
    string getAuthorsText() const;
};

#endif // AUTHORS_H
