#include <sstream>
#include "authorreader.h"
#include "util.h"

Authors* AuthorReader::parseAuthors(const string text)
{
    string values = Util::parseField("author",text);

    return parseAuthorsFromValue(values);
}

Authors * AuthorReader::parseAuthorsFromValue(const string values)
{
    Authors *authors = new Authors();
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

