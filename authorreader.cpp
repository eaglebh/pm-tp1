#include <sstream>
#include "authorreader.h"
#include "util.h"

AuthorReader::AuthorReader()
{
}

Authors* AuthorReader::parseAuthors(const string text)
{
    Authors *authors = new Authors();

    string values = Util::parseField("author",text);
    istringstream iss(values);

    string word;
    stringstream actualAuthor;
    while (iss >> word) {
        if(word.compare("and") == 0) {
            authors->addAuthor( actualAuthor.str() );
            actualAuthor.str("");
        } else {
            actualAuthor << " " << word;
        }
    }
    authors->addAuthor( actualAuthor.str() );

    return authors;
}
